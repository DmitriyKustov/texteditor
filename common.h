/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет текст в указанный файл
 */
void save(text txt, char *filename);

/**
 * Переводит в верхний регистр
 */
void showupper(text txt);

/**
 * Удаляет первую пустую строку
 */
void remove_first_entry_line(text txt);

/**
 * Выводит содержимое с нумерацией строк
 */
void shownum(text txt);


/**
 * Выводит строки, в которых содержатся цифры
 */
void showlineswithdigits(text txt);

#endif
