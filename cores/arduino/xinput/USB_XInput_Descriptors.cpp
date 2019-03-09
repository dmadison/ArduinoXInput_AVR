/*
 *  Project     Arduino XInput - AVR Core
 *  @author     David Madison
 *  @link       github.com/dmadison/ArduinoXInput_AVR
 *  @license    MIT - Copyright (c) 2019 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "USB_XInput_Descriptors.h"

#if defined(USBCON)

const DeviceDescriptor USB_DeviceDescriptor = {
	0x12,           // bLength (18)
	0x01,           // bDescriptorType (DEVICE)
	USB_VERSION,    // bcdUSB (2.0)
	0xFF,           // bDeviceClass
	0xFF,           // bDeviceSubClass
	0xFF,           // bDeviceProtocol
	0x40,           // bMaxPacketSize0
	USB_VID,        // idEVendor
	USB_PID,        // idProduct
	0x114,          // bcdDevice
	IMANUFACTURER,  // iManufacturer
	IPRODUCT,       // iProduct
	ISERIAL,        // iSerialNumber
	0x01,           // bNumConfigurations
};

const u8 USB_ConfigDescriptor[] = {
	// Configuration Descriptor
	0x09,        // bLength
	0x02,        // bDescriptorType (CONFIGURATION)
	0x99, 0x00,  // wTotalLength (153)
	0x04,        // bNumInterfaces
	0x01,        // bConfigurationValue
	0x00,        // iConfiguration
	0xA0,        // bmAttributes
	0xFA,        // bMaxPower

	/* ---------------------------------------------------- */
	// Interface 0: Control Data
	0x09,        // bLength
	0x04,        // bDescriptorType (INTERFACE)
	0x00,        // bInterfaceNumber
	0x00,        // bAlternateSetting
	0x02,        // bNumEndpoints
	0xFF,        // bInterfaceClass
	0x5D,        // bInterfaceSubClass
	0x01,        // bInterfaceProtocol
	0x00,        // iInterface

	// Unknown Descriptor (If0)
	0x11,        // bLength
	0x21,        // bDescriptorType
	0x00, 0x01, 0x01, 0x25,  // ???
	0x81,        // bEndpointAddress (IN, 1)
	0x14,        // bMaxDataSize
	0x00, 0x00, 0x00, 0x00, 0x13,  // ???
	0x02,        // bEndpointAddress (OUT, 2)
	0x08,        // bMaxDataSize
	0x00, 0x00,  // ???

	// Endpoint 1: Control Surface Send
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x81,        // bEndpointAddress (IN, 1)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x04,        // bInterval

	// Endpoint 1: Control Surface Receive
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x02,        // bEndpointAddress (OUT, 2)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x08,        // bInterval

	/* ---------------------------------------------------- */
	// Interface 1: Headset (and Expansion Port?)
	0x09,        // bLength
	0x04,        // bDescriptorType (INTERFACE)
	0x01,        // bInterfaceNumber
	0x00,        // bAlternateSetting
	0x04,        // bNumEndpoints
	0xFF,        // bInterfaceClass
	0x5D,        // bInterfaceSubClass
	0x03,        // bInterfaceProtocol
	0x00,        // iInterface

	// Unknown Descriptor (If1)
	0x1B,        // bLength
	0x21,        // bDescriptorType
	0x00, 0x01, 0x01, 0x01,  // ???
	0x83,        // bEndpointAddress (IN, 3)
	0x40,        // bMaxDataSize
	0x01,        // ???
	0x04,        // bEndpointAddress (OUT, 4)
	0x20,        // bMaxDataSize
	0x16,        // ???
	0x85,        // bEndpointAddress (IN, 5)
	0x00,        // bMaxDataSize
	0x00, 0x00, 0x00, 0x00, 0x00, 0x16,  // ???
	0x05,        // bEndpointAddress (OUT, 5)
	0x00,        // bMaxDataSize
	0x00, 0x00, 0x00, 0x00, 0x00,  // ???

	// Endpoint 2: Microphone Data Send
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x83,        // bEndpointAddress (IN, 3)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x02,        // bInterval

	// Endpoint 2: Headset Audio Receive
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x04,        // bEndpointAddress (OUT, 4)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x04,        // bInterval

	// Endpoint 3: Unknown, Send
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x85,        // bEndpointAddress (IN, 5)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x40,        // bInterval

	// Endpoint 3: Unknown, Receive
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x05,        // bEndpointAddress (OUT, 5)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x10,        // bInterval

	/* ---------------------------------------------------- */
	// Interface 2: Unknown
	0x09,        // bLength
	0x04,        // bDescriptorType (INTERFACE)
	0x02,        // bInterfaceNumber
	0x00,        // bAlternateSetting
	0x01,        // bNumEndpoints
	0xFF,        // bInterfaceClass
	0x5D,        // bInterfaceSubClass
	0x02,        // bInterfaceProtocol
	0x00,        // iInterface

	// Unknown Descriptor (If2)
	0x09,        // bLength
	0x21,        // bDescriptorType
	0x00, 0x01, 0x01, 0x22,  // ???
	0x86,        // bEndpointAddress (IN, 6)
	0x07,        // bMaxDataSize
	0x00,        // ???

	// Endpoint 4: Unknown, Send
	0x07,        // bLength
	0x05,        // bDescriptorType (ENDPOINT)
	0x86,        // bEndpointAddress (IN, 6)
	0x03,        // bmAttributes
	0x20, 0x00,  // wMaxPacketSize
	0x10,        // bInterval

	/* ---------------------------------------------------- */
	// Interface 3: Security Method
	0x09,        // bLength
	0x04,        // bDescriptorType (INTERFACE)
	0x03,        // bInterfaceNumber
	0x00,        // bAlternateSetting
	0x00,        // bNumEndpoints
	0xFF,        // bInterfaceClass
	0xFD,        // bInterfaceSubClass
	0x13,        // bInterfaceProtocol
	0x04,        // iInterface

	// Unknown Descriptor (If3)
	0x06,        // bLength
	0x41,        // bDescriptorType
	0x00, 0x01, 0x01, 0x03,  // ???
};

const u16 USB_ConfigDescriptorSize = sizeof(USB_ConfigDescriptor);

const u8 STRING_SERIAL[] = "Arduino XInput AVR";
const u8 STRING_SECURITY[] = "Xbox Security Method 3, Version 1.00, \xA9 2005 Microsoft Corporation. All rights reserved.";

#endif /* if defined(USBCON) */
