/**
 * mnwbf.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2018, Dmitriy Kustov <kustov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void mnwbf_line(int index, char *contents, int cursor, void *data);


void mnwbf(text txt)
{
    
    process_forward(txt, mnwbf_line, NULL);
}

static void mnwbf_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    
    
    if (cursor > 0) {
	for (int j = 0; j < 100; j++) {
	    if (contents[j] == '|') {
		int length = strlen(contents);
		for (int i = 1; i < length; i++) {
		    if (isspace(contents[cursor+i]) && !isspace(contents[cursor+i+1])) {
			cursor += i;
			break;
		    }
		}
	    }
	    break;
	}
    }
    mwcrsr(txt, index + 1, cursor);
}
