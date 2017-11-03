APPLICATION = ndw-morse

RIOTBASE ?= ../RIOT
BOARD ?= bluepill

USEMODULE += xtimer

USEPKG += umorse

MORSE_DELAY ?= 120

CFLAGS += -DUMORSE_DELAY_DIT=$(MORSE_DELAY)

include $(RIOTBASE)/Makefile.include
