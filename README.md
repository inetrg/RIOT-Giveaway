# NdW-2017

At the *Nacht des Wissens 2017* (night of sciences) the [iNET](https://www.inet.haw-hamburg.de)
research group distributed a [RIOT](https://riot-os.org) starter pack containing
an embedded development board, i.e., a STM32F103 *bluepill*.

## What else do you need

## Quick starter

#. clone this repository and initialize submodules:

```
git clone https://github.com/inetrg/NdW-2017
cd NdW-2017
git submodule init
git submodule update
```

#. to check if board is ready run `dfu-util -l`, output should be similar to:

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
#. if no device with `[1d50:6017]` or `[1d50:6018]` is visible, you need to
connect pin `B1` to ground (`G`) and press reset to halt the bootloader:

[[https://github.com/inetrg/NdW-2017/blob/master/doc/bootloader.png|alt=bootloader]]

#. build and flash the Morse code example onto a board; replace `<board-name>`,
e.g. `bluepill`:

```
cd morse
BOARD=<board-name> make clean all flash
```

#. afterwards press the reset button. The onboard LED should start blinking,
it morses the given text. Default is `Hello World this is RIOT`, try if you
can decode it. Note, there is a *Morse code cheat sheet* under `doc/`.

## Further Information and Resources

Regarding hardware, the [STM32duino Wiki](http://wiki.stm32duino.com/index.php?title=Blue_Pill)
gives a good overview on the *bluepill* features and specifications, also have a
look at the official [datasheet](http://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
for the STM32F103 MCU.
