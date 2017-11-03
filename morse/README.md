# Description

This RIOT application translates a given text string into Morse Code and prints
the encoded text to the RIOT shell and also blinks it using an onboard LED (if
available). The encoded text is printed using `.` and `_` for DIT (short) and
DAH (long) Morse chars. Inter char gaps are represented by ` ` (space), inter
word gaps are printed as ` / ` (dash).

To view the printed Morse code output on the shell, connect the board with a
USB-serial adapter to a computer and run 'make term'.

# Configuration

The delay can be configured by setting `UMORSE_DELAY_DIT`, see Makefile.
The default in uMorse is 60ms, as this is quite fast for beginners, its
set to 120ms for this test and could be further raised, e.g. 240ms.
