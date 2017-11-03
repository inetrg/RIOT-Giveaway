/*
 * Copyright (C) 2017 HAW Hamburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @brief       Morse Code RIOT example for NdW 2017
 *
 * @author      Sebastian Meiling <s@mlng.net>
 */

#include <stdio.h>
#include <string.h>

#include "board.h"
#include "led.h"
#include "periph_conf.h"
#include "xtimer.h"
#define UMORSE_MSLEEP(m)    xtimer_usleep(m * US_PER_MS)

#include "umorse.h"
#include "print.h"

/* increase this for longer texts */
#define CODE_LEN	(64U)

void blink_dit(void *args, uint8_t flags)
{
    (void) args;
    (void) flags;

    LED0_ON;
    UMORSE_MSLEEP(UMORSE_DELAY_DIT);
    LED0_OFF;
}

void blink_dah(void *args, uint8_t flags)
{
    (void) args;
    (void) flags;

    LED0_ON;
    UMORSE_MSLEEP(UMORSE_DELAY_DAH);
    LED0_OFF;
}

void blink_nil(void *args, uint8_t flags)
{
    (void) args;

    uint8_t cnt = flags & UMORSE_MASK_COUNT;
    UMORSE_MSLEEP(cnt * UMORSE_DELAY_DIT);
}

/* Morse code output to LED */
static const umorse_out_t blink = {
    .dit = blink_dit,
    .dah = blink_dah,
    .nil = blink_nil,
    .params = NULL
};

/* Morse code output to shell */
static const umorse_out_t print = {
    .dit = umorse_print_dit,
    .dah = umorse_print_dah,
    .nil = umorse_print_nil,
    .params = NULL
};

static const char text[] = "Hello World, this is RIOT!";

static uint8_t code[CODE_LEN];

int main(void)
{
    /* make sure onboard LED is turned off */
    LED0_OFF;

    printf("> Translate following text of length %u into Morse code:\n\"%s\"\n",
           (unsigned)strlen(text), text);

    memset(code, 0, CODE_LEN);
    /* start encoding */
    int ret = umorse_encode_compact(text, sizeof(text), code, sizeof(code));
    /* exit on error */
    if (ret < 0) {
        printf("! error during encoding (%d)", ret);
        return 2;
    }
    /* wait a second before start */
    xtimer_sleep(1);
    printf("> Morse encoded text:\n");
    /* print code to shell, visible when connected via UART */
    umorse_output(&print, code, ret, UMORSE_FLAG_NODELAY);
    /* blink code via onboard LED0 */
    umorse_output(&blink, code, ret, 0x0);

    return 0;
}
