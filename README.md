# XInput USB Core for Arduino AVR

The files in this repository allow you to emulate an Xbox gamepad (XInput) using a USB-capable Arduino microcontroller.

## Installation
<pre>
└───Arduino Installation
	├───drivers
	├───examples
	├───hardware
	│   ├───arduino
	│   ├───tools
	│   └───<b>xinput
	│       └───avr
	│           ├───bootloaders
	│           ├───cores
	│           ├───libraries
	│           └───variants</b>
	├───java
	├───lib
	├───libraries
	├───reference
	├───tools
	└───tools-builder
</pre>

To install, download [the latest version](../../releases/latest) of this repository to your PC. Navigate to the directory containing your Arduino installation, and then open up the 'hardware' folder. Extract the contents of the .zip file into this directory. You should have a new 'xinput' folder with an 'avr' folder inside of it, containing the files from this repository (see the tree view above).

Restart the Arduino IDE. If the XInput AVR core is installed correctly, you should see a new collection of "XInput AVR Boards" in the `Tools -> Boards` menu.

To uninstall, delete the 'xinput' folder in the 'hardware' directory, and then restart the Arduino IDE.

## Upload Warning and Instructions

**!!!!!!! IMPORTANT !!!!!!!**

Due to the nature of how the XInput USB mode works, Arduinos that have XInput sketches on them will ***not*** automatically reset when programmed by the IDE! You will need to reset the board by hand every time you upload new code.

To upload to the board:
* Connect the board via USB
* Make sure the proper board is selected in the IDE
* Hold the 'reset' button
* Press 'Upload' in the IDE
* Release the 'reset' button

If you did these steps properly, the board should reset to the bootloader and the upload should begin. If your board does not have a 'reset' button, you can wire your own by connecting the 'reset' pin to ground.

**Do *not* upload XInput sketches to your Arduino unless you know how to reset it!**

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

## License

The Arduino core files are licensed under the terms of the [GNU Lesser General Public License (LGPL) version 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html). Modifications are released under these same terms. See the [LICENSE](LICENSE.txt) file for more information.

Newly contributed files for XInput support are licensed under the terms of the more permissive [MIT license](https://opensource.org/licenses/MIT).
