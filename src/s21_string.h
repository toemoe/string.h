#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "errors.h"

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
const char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
const char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, size_t start_index);
void s21_free(void *ptr);

void sp_d(long int num, char **buf_ptr, int *count, int *width, int fl_left,
          int pad_zero, int fl_plus, int fl_space, int presicion);
void sp_c(char c, int fl_left, char **buf_ptr, int *count, int *width,
          int fl_l);
void sp_f(int precision, double num, char **buf_ptr, int *count, int *width,
          int fl_left, int fl_plus, int fl_space, int fl_latt);
void sp_u(long unsigned int num, int *width, int *count, int fl_left,
          char **buf_ptr, int pad_zero, int fl_space, int precision);
void sp_s(char *str, int precision, int *width, int *count, int fl_left,
          char **buf_ptr, int fl_l);

int s21_sprintf(char *buffer, const char *format, ...);

#endif
