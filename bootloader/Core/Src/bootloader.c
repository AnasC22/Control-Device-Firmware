/*
 * bootloader.c
 *
 *  Created on: Aug 20, 2024
 *      Author: chowd
 */
#include "bootloader.h"

BootloaderStorage storage = {.state = BOOTLOADER_UNINITIALIZED};

void bootloader_init(BootloaderConfig *config) {
	storage.config = config;
	storage.binary_size = 0;
	storage.state = BOOTLOADER_IDLE;
	storage.bytes_written = 0;
}

void bootloader_jump_app()
{
	void *app_reset_handler() = (void *)(storage.config->app_start_addr + 0x4);
}

void bootloader_run();

void bootloader_switch_states(BootloaderStates new_state)
{
	switch (new_state) {
	case BOOTLOADER_UNINITIALIZED:
		storage.state = BOOTLOADER_FAULT;
		break;
	case BOOTLOADER_IDLE:
		if (storage.state != BOOTLOADER_FAULT) {
			storage.state = BOOTLOADER_IDLE;
		}
		break;
	case BOOTLOADER_JUMP_APP:
		if (storage.state != BOOTLOADER_FAULT) {
			storage.state = BOOTLOADER_JUMP_APP;
		}
		break;
	case BOOTLOADER_FAULT:
		storage.state = BOOTLOADER_FAULT;
		break;
	default:
		storage.state = BOOTLOADER_FAULT;
	}
}
