/*
 * bootloader.h
 *
 *  Created on: Aug 20, 2024
 *      Author: chowd
 */

#ifndef INC_BOOTLOADER_H_
#define INC_BOOTLOADER_H_

#include <stdint.h>

typedef enum {
	BOOTLOADER_UNINITIALIZED,
	BOOTLOADER_IDLE,
	BOOTLOADER_JUMP_APP,
	BOOTLOADER_FAULT
} BootloaderStates;

typedef struct {
	uint32_t app_start_addr;
	uint32_t app_end_addr;
} BootloaderConfig;

typedef struct {
	BootloaderConfig *config;
	uint32_t bytes_written;
	uint32_t binary_size;
	BootloaderStates state;
} BootloaderStorage;

void bootloader_init(BootloaderConfig *config);

void bootloader_jump_app();

void bootloader_run();

void bootloader_switch_states(BootloaderStates new_state);



#endif /* INC_BOOTLOADER_H_ */
