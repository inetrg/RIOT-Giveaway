# NdW-2017

At the *Nacht des Wissens 2017* (night of sciences) the [iNET](https://www.inet.haw-hamburg.de)
research group distributed a [RIOT](https://riot-os.org) starter pack containing
an embedded development board, i.e., a STM32F103 *bluepill*. The following
provides an introduction on how to use the board together with RIOT.

## What else do you need

To start using and developing with the embedded device and RIOT you'll need
at least the following additional hardware:
* computer running Linux, macOS, or Windows
* micro-USB cable to connect device with computer

Further we recommend to have:
* a USB-to-UART/Serial adapter, cost around 2 EUR/USD, e.g. on eBay
* basic knowledge of the C/C++ programming language

## Quick starter

* clone this repository and initialize submodules:

```
git clone https://github.com/inetrg/NdW-2017
cd NdW-2017
git submodule init
git submodule update
```

* to check if the board is ready, run `dfu-util -l`.
Output of the command should be similar to:

```
$ dfu-util -l
dfu-util 0.9

Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
Copyright 2010-2016 Tormod Volden and Stefan Schmidt
This program is Free Software and has ABSOLUTELY NO WARRANTY
Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

Deducing device DFU version from functional descriptor length
Found Runtime: [05ac:828b] ver=0143, devnum=5, cfg=1, intf=3, path="29-3", alt=0, name="UNKNOWN", serial="UNKNOWN"
Found DFU: [1d50:6017] ver=0100, devnum=9, cfg=1, intf=0, path="20-1", alt=0, name="@Internal Flash   /0x08000000/8*001Ka,056*001Kg", serial="B5EB9BE2"
```

* if no device with `[1d50:6017]` or `[1d50:6018]` is visible (see last line),
you need to connect pin `B1` to ground (`G`) and press reset to stop bootloader
from loading an existing firmware:

![bootloader](/doc/bootloader.png)

* build and flash the Morse code example onto a board:

```
cd morse
PROGRAMMER=dfu-util make clean all flash
```

* *Note*: the above command only works for the *bluepill*, if you have another
board try `BOARD=<name> make clean flash`.

* afterwards press the reset button. The onboard LED should start blinking,
it morses the given text. Default is `Hello World this is RIOT`, try if you
can decode it. Note, there is a *Morse code cheat sheet* in the subdirectory
[doc](/doc/morse_code.pdf).

* optionally you can connect the USB-to-UART adapter to access the RIOT shell
and see the morse code printed, see [morse README.md](/morse/README.md) for
further information. Connect the USB-to-UART adapter as follows

![USB-to-UART](/doc/shell.png)

* afterwards run `make term` to start the shell.

## Getting to know RIOT

* [RIOT Tutorials](https://github.com/RIOT-OS/Tutorials)
* [RIOT Wiki](https://github.com/RIOT-OS/RIOT/Wiki)

You may also join the RIOT [user](https://lists.riot-os.org/mailman/listinfo/users)
and/or [developer](https://lists.riot-os.org/mailman/listinfo/devel) mailing lists.


## Further Information and Resources

* the [STM32duino Wiki](http://wiki.stm32duino.com/index.php?title=Blue_Pill)
gives a good overview on the *bluepill* features and specifications.
* also have a look at the official [datasheet](http://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
for the STM32F103 MCU.
