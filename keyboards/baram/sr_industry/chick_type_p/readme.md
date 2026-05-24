# CHICK TYPE P

The CHECK TYPE P is the keyboard from SR Industry

* Keyboard Maintainer: [BARAM](https://github.com/chcbaram)
* Hardware Supported: RP2040
* Hardware Availability: [SR Industry](https://www.srind.kr)


Make example for this keyboard (after setting up your build environment):

    make baram/sr_industry/chick_type_p:via
    
Flashing example for this keyboard:

    make baram/sr_industry/chick_type_p:via:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top-most and outer-most key in the matrix and plug in the keyboard
* **Physical reset button**: Hold the "BOOTMODE" button on the back of the PCB and briefly press the "RESET" button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
