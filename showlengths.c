/**
 * showlengths.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2018, Dmitriy Kustov <kustov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <string.h>

static void showlengths_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showlengths(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showlengths_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void showlengths_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    int length = strlen(contents);
    
    printf("\t %d \n", length);
    
}
