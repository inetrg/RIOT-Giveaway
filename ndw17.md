# Nacht des Wissens 2017

*NOTE: the following description will only work for devices that we distributed
at the NdW'17: *Nacht des Wissens* = *Night of Sciences* in November 2017 at the
HAW Hamburg.

## Flash with dfu-util

* Afterwards, check if the board is ready, therefore run `dfu-util -l` on the
command line. Output of the command should be similar to:

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

* If no device with `[1d50:6017]` or `[1d50:6018]` is visible (see last line),
you need to connect pin `B1` to ground (`G`) and press reset to stop bootloader
from loading an existing firmware:

![img:bootloader](/doc/bootloader.png)
