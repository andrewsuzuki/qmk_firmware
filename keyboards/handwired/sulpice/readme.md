# sulpice

See https://github.com/andrewsuzuki/sulpice

Sulpice uses the [Teensy Loader](https://www.pjrc.com/teensy/loader.html).

Linux users need to modify udev rules as described on the [Teensy
Linux page].  Some distributions provide a binary, maybe called
`teensy-loader-cli`.

[Teensy Linux page]: https://www.pjrc.com/teensy/loader_linux.html

To flash the firmware:

  - Build the firmware with `make handwired/sulpice:<keymapname>`, for example `make handwired/sulpice:default`
  - This will result in a hex file called `handwired_sulpice_<keymapname>.hex`, e.g.
    `handwired_sulpice_default.hex`

  - Start the teensy loader.

  - Load the .hex file into it.

  - Put the Teensy in firmware-loading mode:
    * If your current layout has a RESET key, press it.
    * If you lack a RESET key, press the reset button on the Teensy board itself.

  - Click the button in the Teensy app to download the firmware.

To flash with ´teensy-loader-cli´:

  - Build the firmware as above

  - Run `<path/to/>teensy_loader_cli -mmcu=atmega32u4 -w handwired_sulpice_<keymapname>.hex`

  - If you like, you can do both at once: `make handwired/sulpice:<keymapname>:teensy`

  - Put the Teensy in firmware-loading mode:
    * If your current layout has a RESET key, press it.
    * If you lack a RESET key, press the reset button on the Teensy board itself.
