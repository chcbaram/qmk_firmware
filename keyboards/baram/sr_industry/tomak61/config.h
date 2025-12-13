/* Copyright 2025 BARAM */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once



// Configure half duplex split comms over PIO
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_TX_PIN GP28


/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

