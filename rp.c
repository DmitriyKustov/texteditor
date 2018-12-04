/**
 * rp.c -- удаляет строку перед текущей.
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

static void rp_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void rp(text txt)
{

    process_forward(txt, rp_line, txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void rp_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);

    if (cursor > 0) {
	
	delete_line(data, index);
    }

}
    
