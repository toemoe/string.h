#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *true_dest = dest;
  while (*dest != '\0') {
    dest++;
  }

  while (n > 0 && *src != '\0') {
    *dest = *src;
    dest++;
    src++;
    n--;
  }
  *dest = '\0';
  return true_dest;
}

const char *s21_strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  return str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    const char *s = str2;
    while (*s != '\0') {
      if (*str1 == *s) {
        return (char *)str1;
      }
      s++;
    }
    str1++;
  }
  return NULL;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *true_dest = dest;
  while (n > 0 && *src != '\0') {
    *dest = *src;
    dest++;
    src++;
    n--;
  }
  while (n > 0) {
    *dest = '\0';
    dest++;
    n--;
  }
  return true_dest;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }
  while (*haystack != '\0') {
    const char *hs = haystack;
    const char *nd = needle;
    while (*hs != '\0' && *nd != '\0' && *hs == *nd) {
      hs++;
      nd++;
    }
    if (*nd == '\0') {
      return (char *)haystack;
    }
    haystack++;
  }
  return NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;

  while (n > 0) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
    n--;
  }
  return 0;
}

void *s21_memchr(const void *str, int c, size_t n) {
  const unsigned char *s = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  while (n > 0) {
    if (*s == ch) {
      return (char *)s;
    }
    s++;
    n--;
  }
  return NULL;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  void *true_d = dest;

  while (n > 0) {
    *d = *s;
    d++;
    s++;
    n--;
  }
  return true_d;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *s = (unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  while (n > 0) {
    *s = ch;
    s++;
    n--;
  }
  return str;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;

  while (n > 0) {
    if (*s1 != *s2) {
      return *s1 - *s2;
    }
    if (*s1 == '\0') {
      break;
    }
    s1++;
    s2++;
    n--;
  }
  return 0;
}

char *s21_strrchr(const char *str, int c) {
  const char *lastoc = NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      lastoc = str;
    }
    str++;
  }
  return (char *)lastoc;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t length = 0;

  while (*str1 != '\0') {
    const char *d = str2;
    while (*d != '\0') {
      if (*str1 == *d) {
        return length;
      }
      d++;
    }
    length++;
    str1++;
  }
  return length;
}

const char *s21_strerror(int errnum) {
  static const char *error[] = ERROR_MESSAGES;
  const int errors_count = sizeof(error) / sizeof(error[0]);

  if (errnum < 0 || errnum >= errors_count) {
    return "Unknown error";
  }
  return error[errnum];
}
