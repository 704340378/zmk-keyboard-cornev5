/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/devicetree.h>

static int pinmux_cornev5_init(void) {
#if (CONFIG_BOARD_CORNEV5)
    const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
#if CONFIG_BOARD_CORNEV5_CHARGER
    gpio_pin_configure(p0, 5, GPIO_OUTPUT);
    gpio_pin_set(p0, 5, 0);
#else
    gpio_pin_configure(p0, 5, GPIO_INPUT);
#endif
#endif
    return 0;
}

SYS_INIT(pinmux_cornev5_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
