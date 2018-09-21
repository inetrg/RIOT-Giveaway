# RIOT Giveaway

At various public, scientific events, such as the *Hamburger Nacht des Wissens*,
the [iNET research group][iNET] of the [HAW Hamburg][HAW] distributed a [RIOT]
starter pack containing an embedded development board, i.e., a STM32 *bluepill*.
The board features a STM32F103C8T6 CPU running at 72MHz, it has 64KB flash and
20KB SRAM, more information can be found in the official [datasheet]. The
following provides an introduction on how to use the board together with RIOT.

![img:bluepill](/doc/bluepill.png)

## What else do you need

To start using and developing with the embedded device and RIOT you'll need
at least the following additional hardware:
* computer running Linux, macOS, or Windows
* micro-USB cable to connect device with computer

Further we recommend to have:
* a USB-to-UART/Serial adapter, cost around 2 EUR/USD, e.g. on eBay
* basic knowledge of the C/C++ programming language

To better get to know RIOT and setup the required toolchains please have a look
at the [RIOT Tutorials][Tutorials] and also the [RIOT Wiki][Wiki]. Specifically,
the tutorials show how to easily setup an initial development environment using
Vagrant and VirtualBox - the latest RIOT VM has all required tools to get you
started.

## Quick start guide

First, you need to setup a working RIOT toolchain with `arm-none-eabi-gcc`
to compile the code and `dfu-util` for flashing. Optionally, Python 3 with the
`pyserial` package is needed to access RIOT shell on the board connected via
an USB-to-UART adapter. RIOT offers a fully prepared virtual machine to begin
with, just follow these steps:

* Install [git], [Vagrant], and [VirtualBox] on your computer, you'll find
install packages for Windows and macOS on referenced websites. For VirtualBox
you also need to install the generic [extension pack][vboxext].
Linux users should use  the package managing system of their distribution, e.g.
`apt` for Debian/Ubuntu, or `yum` for CentOS/Fedora/RedHat. Alternatively, you
can also use [Docker] - see [riotdocker] for further information.

* Afterwards clone the RIOT Github repository and create a VM using Vagrant.
Open a command line (terminal, or shell) and run:

```
git clone https://github.com/RIOT-OS/RIOT
cd RIOT
vagrant up
```

* It takes sometime to download and create the RIOT VM, when finished login to
the VM running `vagrant ssh` and proceed with the steps below.

----

* Clone this repository and initialise submodules:

```
git clone https://github.com/inetrg/NdW-2017
cd NdW-2017
git submodule init
git submodule update
```

* This will download the source code and initialise a copy of RIOT as a
submodule, you can also use a different RIOT clone by setting `RIOTBASE` as
an environment variable.

* Afterwards, check if the board is ready, therefore run `dfu-util -l` on the
command line. Output of the command should be similar to:

```
$ dfu-util --list
dfu-util 0.9

Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
Copyright 2010-2016 Tormod Volden and Stefan Schmidt
This program is Free Software and has ABSOLUTELY NO WARRANTY
Please report bugs to http://sourceforge.net/p/dfu-util/tickets/

Deducing device DFU version from functional descriptor length
Found Runtime: [05ac:828b] ver=0144, devnum=5, cfg=1, intf=3, path="29-1.8.1.3", alt=0, name="UNKNOWN", serial="UNKNOWN"
Found DFU: [1eaf:0003] ver=0201, devnum=30, cfg=1, intf=0, path="20-3.2", alt=2, name="STM32duino bootloader v1.0  Upload to Flash 0x8002000", serial="LLM 003"
Found DFU: [1eaf:0003] ver=0201, devnum=30, cfg=1, intf=0, path="20-3.2", alt=1, name="STM32duino bootloader v1.0  Upload to Flash 0x8005000", serial="LLM 003"
Found DFU: [1eaf:0003] ver=0201, devnum=30, cfg=1, intf=0, path="20-3.2", alt=0, name="STM32duino bootloader v1.0  ERROR. Upload to RAM not supported.", serial="LLM 003"
```

* If no device with `[1eaf:0003]` is visible (there should be 3 as shown above)
you need to set the jumper of boot pin 1 to 1 and press reset to stop bootloader
from loading an existing firmware, see also following picture.

![img:bootloader](/doc/bootloader_new.png)

* *Note*: if you see a device with `[1d50:6017]` or `[1d50:6018]` please refer
to [ndw17.md](ndw17.md).

* Finally, build and flash the Morse code example onto a board:

```
cd morse
PROGRAMMER=dfu-util make clean all flash
```

* *Note*: the above command only works for the *bluepill*, if you have another
board try `BOARD=<name> make clean flash`.

* *Note*: remember to reset the boot pin 1 to 0, if necessary.

* Afterwards press the reset button. The onboard LED should start blinking,
it morses a given text, the default is `Hello World this is RIOT`. Try if you
can decode it on your own,  note: there is a *Morse code cheat sheet* in the
subdirectory [doc](/doc/morse_code.pdf).

* Optionally, you can connect an USB-to-UART adapter to access the RIOT shell
and see the morse code printed, see [morse README.md](/morse/README.md) for
further information. Connect the USB-to-UART adapter as follows

![img:USB-to-UART](/doc/shell.png)

* Afterwards run `make term` which will start the RIOT shell. To exit the shell,
either type `/exit` or press `ctrl + c` to terminate.

## Information and Resources

You will find useful information on the board in

* the [STM32duino Wiki][bluepill], which gives a good overview on the *bluepill*
basic features and specifications.
* and the official [datasheet] for the STM32F103 MCU.

Further information on RIOT are available on line:

* the RIOT-OS [homepage][RIOT] and on [Github].
* the RIOT [Tutorials] provide a good starting point to get know RIOT.
* also checkout RIOTs [Wiki] pages and the [Doxygen] documentation.

We also recommend to join the RIOT [user](https://lists.riot-os.org/mailman/listinfo/users)
and/or [developer](https://lists.riot-os.org/mailman/listinfo/devel) mailing lists.

[HAW]:  http://www.haw-hamburg.de
[iNET]: https://www.inet.haw-hamburg.de
[RIOT]: https://riot-os.org
[Github]: https://github.com/RIOT-OS/RIOT
[Tutorials]: https://github.com/RIOT-OS/Tutorials
[Wiki]: https://github.com/RIOT-OS/RIOT/Wiki
[Doxygen]: https://doc.riot-os.org

[bluepill]: http://wiki.stm32duino.com/index.php?title=Blue_Pill
[datasheet]: http://www.st.com/resource/en/datasheet/stm32f103c8.pdf

[Docker]: https://www.docker.com
[riotdocker]: https://github.com/RIOT-OS/riotdocker
[git]: https://git-scm.com/downloads
[Vagrant]: https://www.vagrantup.com/downloads.html
[VirtualBox]: https://www.virtualbox.org/wiki/Downloads
[vboxext]: http://download.virtualbox.org/virtualbox/5.2.0/Oracle_VM_VirtualBox_Extension_Pack-5.2.0-118431.vbox-extpack
