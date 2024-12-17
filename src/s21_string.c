#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
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

char *s21_strchr(const char *str, int c) {
  while (*str != '\0' && *str != c) {
    str++;
  }
  return *str == c ? (char *)str : S21_NULL;
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
  return S21_NULL;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
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
  return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
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

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  while (n > 0) {
    if (*s == ch) {
      return (char *)s;
    }
    s++;
    n--;
  }
  return S21_NULL;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
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

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  while (n > 0) {
    *s = ch;
    s++;
    n--;
  }
  return str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
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
  const char *lastoc = S21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      lastoc = str;
    }
    str++;
  }
  return (char *)lastoc;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;

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

char *s21_strerror(int errnum) {
  static const char *error[] = ERROR_MESSAGES;
  const int errors_count = sizeof(error) / sizeof(error[0]);

  if (errnum < 0 || errnum >= errors_count) {
    return "Unknown error";
  }
  return (char *)error[errnum];
}

char *s21_strtok(char *str, const char *delim) {
  if (delim == S21_NULL) return S21_NULL;

  static char *next_token = S21_NULL;
  char *token = S21_NULL;

  if (str) next_token = str;

  if (next_token) {
    while (*next_token && s21_strchr(delim, *next_token)) next_token++;

    if (*next_token != '\0') {
      token = next_token;

      while (*next_token && !s21_strchr(delim, *next_token)) next_token++;

      if (*next_token)
        *next_token++ = '\0';
      else
        next_token = S21_NULL;
    }
  }

  return token;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t length = s21_strlen(str);

  char *upper_str = (char *)malloc(length + 1);
  if (upper_str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < length; i++) {
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
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t length = s21_strlen(str);

  char *lower_str = (char *)malloc(length + 1);
  if (lower_str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < length; i++) {
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
  if (src == S21_NULL || trim_chars == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t begin = 0;
  s21_size_t end = src_length - 1;

  while (begin < src_length && s21_strchr(trim_chars, src[begin]) != S21_NULL) {
    begin++;
  }

  while (end >= begin && s21_strchr(trim_chars, src[end]) != S21_NULL) {
    end--;
  }

  s21_size_t trimmed_length = end - begin + 1;

  char *result = (char *)malloc(trimmed_length + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_memcpy(result, src + begin, trimmed_length);
  result[trimmed_length] = '\0';

  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL || start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t str_length = s21_strlen(str);

  char *result = (char *)malloc(src_length + str_length + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_memcpy(result, src, start_index);

  s21_memcpy(result + start_index, str, str_length);

  s21_memcpy(result + start_index + str_length, src + start_index,
             src_length - start_index);

  result[src_length + str_length] = '\0';

  return result;
}

void s21_free(void *ptr) {
  if (ptr != S21_NULL) {
    free(ptr);
  }
}
