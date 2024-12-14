#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  size_t length = s21_strlen(str);

  char *upper_str = (char *)malloc(length + 1);
  if (upper_str == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < length; i++) {
    char c = str[i];
    if (c >= 'a' && c <= 'z') {
      upper_str[i] = c - ('a' - 'A');
    } else {
      upper_str[i] = c;
    }
  }

  upper_str[length] = '\0';

  return upper_str;
}

void *s21_to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  size_t length = s21_strlen(str);

  char *lower_str = (char *)malloc(length + 1);
  if (lower_str == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < length; i++) {
    char c = str[i];
    if (c >= 'A' && c <= 'Z') {
      lower_str[i] = c + ('a' - 'A');
    } else {
      lower_str[i] = c;
    }
  }

  lower_str[length] = '\0';

  return lower_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  size_t src_length = s21_strlen(src);
  size_t trim_length = s21_strlen(trim_chars);

  char *result = (char *)malloc(src_length + 1);
  if (result == NULL) {
    return NULL;
  }

  size_t result_index = 0;

  for (size_t i = 0; i < src_length; i++) {
    char c = src[i];
    int trim = 0;

    for (size_t j = 0; j < trim_length; j++) {
      if (c == trim_chars[j]) {
        trim = 1;
        break;
      }
    }

    if (!trim) {
      result[result_index++] = c;
    }
  }
  result[result_index] = '\0';
  return result;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
    return NULL;
  }

  size_t src_length = s21_strlen(src);
  size_t str_length = s21_strlen(str);

  char *result = (char *)malloc(src_length + str_length + 1);
  if (result == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < start_index; i++) {
    result[i] = src[i];
  }

  for (size_t i = 0; i < str_length; i++) {
    result[start_index + i] = str[i];
  }

  for (size_t i = start_index; i < src_length; i++) {
    result[start_index + str_length + i - start_index] = src[i];
  }
  result[src_length + str_length] = '\0';
  return result;
}

void s21_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
}
