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

You can ignore this section if you're using an external programmer.

### How to Upload

Connect the board to your computer using a USB cable, and make sure you have the proper board selected in the IDE's 'boards' menu (with or without XInput). If the board already has an XInput sketch on it, you do *not* need to select a serial port. You should also turn on 'verbose output' for uploading in the Arduino IDE's preferences (`File -> Preferences`). This makes it easier to time the manual reset and see if the upload succeeded.

Lastly, you need to know where the 'reset' button is on your Arduino. If your board does not have a 'reset' button, you can wire your own by momentarily connecting the 'reset' pin to ground.

To upload to the board:
* Press the 'Upload' button in the IDE
* Wait until the status bar says "Uploading..."
* Press the reset button twice, quickly

If you did these steps properly, the board should reset to the bootloader and the upload should begin. AVRDUDE will do its thing and you should see `avrdude done.  Thank you.` near the bottom of the output window.

Note that the IDE may say that it "Couldn't find a Board on the selected port" even if the upload succeeded. This is why it's important to turn on the verbose uploading output - look for the `avrdude` message.

**Do *not* upload XInput sketches to your Arduino unless you know how to reset it!** Otherwise you will not be able to program it anymore and you'll have to [reflash the bootloader](https://learn.sparkfun.com/tutorials/installing-an-arduino-bootloader/all) with an external programmer.

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
