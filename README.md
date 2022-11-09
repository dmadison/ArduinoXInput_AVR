# XInput USB Core for Arduino AVR
[![Build Status](https://github.com/dmadison/ArduinoXInput_AVR/workflows/build/badge.svg?branch=master)](https://github.com/dmadison/ArduinoXInput_AVR/actions?query=workflow%3Abuild)

The files in this repository allow you to emulate an Xbox gamepad (XInput) using a USB-capable Arduino microcontroller. Originally forked from [the official Arduino AVR core](https://github.com/arduino/ArduinoCore-avr).

This is meant to be used in conjunction with the [ArduinoXInput library](https://github.com/dmadison/ArduinoXInput).

## Automated Installation

Follow the official instructions for [adding third party boards](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-or-remove-third-party-boards-in-Boards-Manager) and [adding boards to the Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360016119519-Add-boards-to-Arduino-IDE).

Add the following line to the "Additional Boards Manager URLs" list:
```
https://raw.githubusercontent.com/dmadison/ArduinoXInput_Boards/master/package_dmadison_xinput_index.json
```

If you've done this correctly, the XInput boards packages will be available within the Boards Manager. Install the "XInput AVR Boards" package to add these boards to the IDE.

## Manual Installation
<pre>
└───Arduino App Data Folder
    ├───cache
    ├───logs
    ├───staging
    └───packages
        ├───arduino
        └───<b>xinput
            └───hardware
                └───avr
                    └───{version}
                        ├───bootloaders
                        ├───cores
                        ├───drivers
                        ├───libraries
                        └───variants</b>
</pre>

To install manually you will need to find the Arduino IDE's application data folder. On Windows this is located in `%APPDATA%\..\Local\Arduino15`.

You will need to create the necessary folders in the "packages" directory: `xinput/hardware/avr/{version}`, where `{version}` is the current [semantic version number](https://en.wikipedia.org/wiki/Software_versioning) of the repository (e.g. "1.0.0"). The repository should then be cloned into this folder. See the tree view above for reference.

After you have copied the files, restart the Arduino IDE. If the XInput AVR core is installed correctly, you should see a new collection of "XInput AVR Boards" in the `Tools -> Boards` menu.

To uninstall, delete the 'xinput' folder and then restart the Arduino IDE.

## Upload Warning and Instructions

Due to the nature of how the XInput USB mode works, Arduinos that have XInput sketches on them will ***not*** automatically reset when programmed by the IDE! You will need to reset the board by hand every time you upload new code.

You can ignore this section if you're using an external programmer.

### How to Upload

Connect the board to your computer using a USB cable, and make sure you have the proper board selected in the IDE's 'boards' menu (with or without XInput). If the board already has an XInput sketch on it, you do *not* need to select a serial port. You should also turn on 'verbose output' for uploading in the Arduino IDE's preferences (`File -> Preferences`). This makes it easier to time the manual reset and see if the upload succeeded.

Lastly, you need to know where the 'reset' button is on your Arduino. If your board does not have a 'reset' button, you can wire your own by momentarily connecting the 'reset' pin to ground.

To upload to the board:
* Press the 'Upload' button in the IDE
* Wait until the status bar says "Uploading..."
* Press the reset button twice, quickly

If you timed it properly, the board should reset to the bootloader and the upload should begin. AVRDUDE will do its thing and you should see `avrdude done.  Thank you.` near the bottom of the output window.

Note that the IDE may say that it "Couldn't find a Board on the selected port" even if the upload succeeded. This is why it's important to turn on the verbose uploading output - look for the `avrdude` message.

**Do *not* upload XInput sketches to your Arduino unless you know how to reset it!** Otherwise you will not be able to program it anymore and you'll have to remove the XInput sketch by flashing the board with an external programmer.

## Supported Boards

* [Adafruit Circuit Playground 32u4](https://www.adafruit.com/product/3000)
* [Arduino Esplora](https://store.arduino.cc/usa/arduino-esplora)
* [Arduino Industrial 101](https://store.arduino.cc/usa/arduino-industrial-101)
* [Arduino Leonardo](https://store.arduino.cc/usa/leonardo)
* [Arduino Leonardo ETH](https://store.arduino.cc/usa/arduino-leonardo-eth)
* [Arduino Micro](https://store.arduino.cc/usa/arduino-micro)
* [Arduino Robot Control / Motor](https://store.arduino.cc/usa/arduino-robot)
* [Arduino Yún](https://store.arduino.cc/usa/arduino-yun)
* [Arduino Yún Mini](https://store.arduino.cc/usa/arduino-yun-mini)
* [LilyPad Arduino USB](https://www.sparkfun.com/products/12049)
* [Linino One](https://store.arduino.cc/usa/linino-one)

Unfortunately boards such as the Uno, Nano, or Mega that do not have native USB support will *not* work.

## Limitations

### No Console Support

This will *not* enable you to use your Arduino with an Xbox console! Genuine controllers use a dedicated hardware security chip that handshakes with the console. The Arduinos do not have this chip, and its security method has not been (openly) broken.

### No Commercial Use

These board definitions make use of Microsoft's VID and PID in order to latch on to the PC driver. As such this is strictly for educational or development use by non-commercial entities.

## License

The Arduino core files are licensed under the terms of the [GNU Lesser General Public License (LGPL) version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html). Modifications are released under these same terms. See the [LICENSE](LICENSE.txt) file for more information.

Newly contributed files for XInput support are licensed under the terms of the more permissive [MIT license](https://opensource.org/licenses/MIT).
