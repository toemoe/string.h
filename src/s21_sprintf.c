#include "s21_string.h"

void sp_d(long int num, char **buf_ptr, int *count, int *width, int fl_left,
          int pad_zero, int fl_plus, int fl_space, int precision) {
  char num_buffer[20];
  int num_length = 0, padding;
  int fl_negative = 0;
  int diff_precision;

  if (num < 0) {
    fl_negative = 1;
    num = -num;
    (*count)++;
    (*width)--;
  } else if (fl_plus) {
    (*count)++;
    (*width)--;
  } else if (fl_space) {
    (*count)++;
    (*width)--;
  }

  do {
    num_buffer[num_length++] = num % 10 + '0';
    num = num / 10;
  } while (num > 0);

  padding = (*width) - num_length;
  diff_precision = precision - num_length;

  if (fl_left) {
    if (fl_negative) {
      *(*buf_ptr) = '-';
      (*buf_ptr)++;

    } else if (fl_plus) {
      *(*buf_ptr) = '+';
      (*buf_ptr)++;

    } else if (fl_space) {
      *(*buf_ptr) = ' ';
      (*buf_ptr)++;
    }
    while (diff_precision > 0) {
      *(*buf_ptr) = '0';
      (*buf_ptr)++;
      (*count)++;
      diff_precision--;
    }

    while (num_length > 0) {
      *(*buf_ptr) = num_buffer[--num_length];
      (*buf_ptr)++;
      (*count)++;
    }

    while (padding > 0) {
      *(*buf_ptr) = ' ';
      (*buf_ptr)++;
      (*count)++;
      padding--;
    }
  } else {
    if (pad_zero) {
      while (padding > 0) {
        **buf_ptr = '0';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    } else {
      while (padding > 0) {
        *(*buf_ptr) = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    }

    if (fl_negative) {
      *(*buf_ptr) = '-';
      (*buf_ptr)++;

    } else if (fl_plus) {
      *(*buf_ptr) = '+';
      (*buf_ptr)++;

    } else if (fl_space) {
      *(*buf_ptr) = ' ';
      (*buf_ptr)++;
    }

    while (diff_precision > 0) {
      *(*buf_ptr) = '0';
      (*buf_ptr)++;
      (*count)++;
      diff_precision--;
    }

    while (num_length > 0) {
      *(*buf_ptr) = num_buffer[--num_length];
      (*buf_ptr)++;
      (*count)++;
    }
  }
}

void sp_c(char c, int fl_left, char **buf_ptr, int *count, int *width,
          int fl_l) {
  if (fl_l) {
    wchar_t wc = (wchar_t)c;
    if (fl_left) {
      **buf_ptr = (char)wc;
      (*buf_ptr)++;
      (*count)++;
      while ((*width) > 1) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        (*width)--;
      }
    } else {
      while ((*width) > 1) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        (*width)--;
      }
      **buf_ptr = (char)wc;
      (*buf_ptr)++;
      (*count)++;
    }
  } else {
    if (fl_left) {
      **buf_ptr = c;
      (*buf_ptr)++;
      (*count)++;
      while ((*width) > 1) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        (*width)--;
      }
    } else {
      while ((*width) > 1) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        (*width)--;
      }
      **buf_ptr = c;
      (*buf_ptr)++;
      (*count)++;
    }
  }
}

void sp_f(int precision, double num, char **buf_ptr, int *count, int *width,
          int fl_left, int fl_plus, int fl_space, int fl_latt) {
  int accuracy = (precision >= 0) ? precision : 6;
  char num_buffer[50];
  int num_length = 0, padding;

  double rounded_num = round(num * pow(10, accuracy)) / pow(10, accuracy);

  if (rounded_num < 0) {
    **buf_ptr = '-';
    (*buf_ptr)++;
    rounded_num = -rounded_num;
    (*count)++;
    (*width)--;
  } else if (fl_plus) {
    **buf_ptr = '+';
    (*buf_ptr)++;
    (*count)++;
    (*width)--;
  } else if (fl_space) {
    **buf_ptr = ' ';
    (*buf_ptr)++;
    (*count)++;
    (*width)--;
  }

  int integer = (int)rounded_num;
  do {
    num_buffer[num_length++] = integer % 10 + '0';
    integer = integer / 10;
  } while (integer > 0);

  while (num_length > 0) {
    **buf_ptr = num_buffer[--num_length];
    (*buf_ptr)++;
    (*count)++;
  }

  **buf_ptr = '.';
  (*buf_ptr)++;
  (*count)++;

  double fraction = rounded_num - (int)rounded_num;
  int fraction_digits = 0;
  for (int i = 0; i < accuracy; i++) {
    fraction *= 10;
    int digit = (int)fraction;
    **buf_ptr = digit + '0';
    (*buf_ptr)++;
    (*count)++;
    fraction -= digit;
    if (digit != 0) fraction_digits++;
  }

  if (fraction >= 0.5) {
    char *round_ptr = (*buf_ptr) - 1;
    while (*round_ptr == '9') {
      *round_ptr-- = '0';
    }
    (*round_ptr)++;
  }

  if (fl_latt && fraction_digits == 0 && accuracy == 0) {
    **buf_ptr = '0';
    (*buf_ptr)++;
    (*count)++;
  }

  padding = (*width) - (*count);
  if (fl_left) {
    while ((*count) < (*width)) {
      **buf_ptr = ' ';
      (*buf_ptr)++;
      (*count)++;
    }
  } else {
    while (padding > 0) {
      **buf_ptr = ' ';
      (*buf_ptr)++;
      (*count)++;
      padding--;
    }
  }
}

void sp_u(long unsigned int num, int *width, int *count, int fl_left,
          char **buf_ptr, int pad_zero, int fl_space, int precision) {
  char num_buffer[20];
  int num_length = 0, padding;
  int diff_precision;

  if (fl_space) {
    **buf_ptr = ' ';
    (*buf_ptr++)++;
    (*count)++;
    (*width)--;
  }

  do {
    num_buffer[num_length++] = num % 10 + '0';
    num /= 10;
  } while (num > 0);

  padding = (*width) - num_length;
  diff_precision = precision - num_length;
  if (fl_left) {
    while (diff_precision > 0) {
      *(*buf_ptr) = '0';
      (*buf_ptr)++;
      (*count)++;
      diff_precision--;
    }
    while (num_length > 0) {
      **buf_ptr = num_buffer[--num_length];
      (*buf_ptr)++;
      (*count)++;
    }

    while (padding > 0) {
      **buf_ptr = ' ';
      (*buf_ptr)++;
      (*count)++;
      padding--;
    }
  } else {
    if (pad_zero) {
      while (padding > 0) {
        **buf_ptr = '0';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    } else {
      while (padding > 0) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    }

    while (diff_precision > 0) {
      *(*buf_ptr) = '0';
      (*buf_ptr)++;
      (*count)++;
      diff_precision--;
    }

    while (num_length > 0) {
      **buf_ptr = num_buffer[--num_length];
      (*buf_ptr)++;
      (*count)++;
    }
  }
}

void sp_s(char *str, int precision, int *width, int *count, int fl_left,
          char **buf_ptr, int fl_l) {
  int padding;
  if (fl_l) {
    wchar_t *wstr = (wchar_t *)str;
    int str_length = 0;

    while (wstr[str_length] != L'\0' &&
           (precision < 0 || str_length < precision)) {
      str_length++;
    }

    padding = (*width) - str_length;
    if (fl_left) {
      for (int i = 0; i < str_length; i++) {
        **buf_ptr = (char)wstr[i];
        (*buf_ptr)++;
        (*count)++;
      }

      while (padding > 0) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    } else {
      while (padding > 0) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }

      for (int i = 0; i < str_length; i++) {
        **buf_ptr = (char)wstr[i];
        (*buf_ptr)++;
        (*count)++;
      }
    }
  } else {
    if (str == NULL) {
      str = "(null)";
    }

    int str_length = 0;
    while (str[str_length] != '\0' &&
           (precision < 0 || str_length < precision)) {
      str_length++;
    }

    padding = (*width) - str_length;
    if (fl_left) {
      for (int i = 0; i < str_length; i++) {
        **buf_ptr = str[i];
        (*buf_ptr)++;
        (*count)++;
      }

      while (padding > 0) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }
    } else {
      while (padding > 0) {
        **buf_ptr = ' ';
        (*buf_ptr)++;
        (*count)++;
        padding--;
      }

      for (int i = 0; i < str_length; i++) {
        **buf_ptr = str[i];
        (*buf_ptr)++;
        (*count)++;
      }
    }
  }
}

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;
  char *buf_ptr = buffer;

  while (*format) {
    if (*format == '%') {
      format++;
    }
    int width = 0;
    int precision = -1;
    int pad_zero = 0;
    int fl_plus = 0;
    int fl_space = 0;
    int fl_h = 0;
    int fl_l = 0;
    int fl_L = 0;
    int fl_left = 0;
    int fl_latt = 0;

    if (*format == '#') {
      fl_latt = 1;
      format++;
    }

    if (*format == '0') {
      pad_zero = 1;
      format++;
    }

    if (*format == '+') {
      fl_plus = 1;
      format++;
    }
    if (*format == ' ') {
      fl_space = 1;
      format++;
    }

    if (*format == '-') {
      fl_left = 1;
      format++;
    }

    if (*format == 'h') {
      fl_h = 1;
      format++;
    }

    if (*format == 'l') {
      fl_l = 1;
      format++;
    }
    if (*format == 'L') {
      fl_L = 1;
      format++;
    }

    if (*format == '.') {
      format++;
      if (*format == '*') {
        precision = va_arg(args, int);
        format++;
      } else {
        precision = 0;
        while (*format >= '0' && *format <= '9') {
          precision = precision * 10 + (*format - '0');
          format++;
        }
      }
    }

    if (*format == '*') {
      width = va_arg(args, int);
      format++;
    } else {
      while (*format >= '0' && *format <= '9') {
        width = width * 10 + (*format - '0');
        format++;
      }
    }

    switch (*format) {
      case 'd': {
        long int num;
        if (fl_h) {
          num = va_arg(args, int);
          num = (short)num;
        } else if (fl_l) {
          num = va_arg(args, long int);
        } else {
          num = va_arg(args, int);
        }

        sp_d(num, &buf_ptr, &count, &width, fl_left, pad_zero, fl_plus,
             fl_space, precision);
        break;
      }
      case 'c': {
        if (fl_l) {
          wchar_t wc = va_arg(args, wchar_t);
          sp_c(wc, fl_left, &buf_ptr, &count, &width, fl_l);
        } else {
          char c = (char)va_arg(args, int);
          sp_c(c, fl_left, &buf_ptr, &count, &width, fl_l);
        }
        break;
      }
      case '%': {
        *buf_ptr++ = '%';
        count++;
        break;
      }
      case 'f': {
        long double num;
        if (fl_L) {
          num = va_arg(args, long double);
        } else {
          num = va_arg(args, double);
        }
        sp_f(precision, num, &buf_ptr, &count, &width, fl_left, fl_plus,
             fl_space, fl_latt);
        break;
      }
      case 'u': {
        long unsigned int num;
        if (fl_h) {
          num = va_arg(args, unsigned int);
          num = (short)num;
        } else if (fl_l) {
          num = va_arg(args, long unsigned int);
        } else {
          num = va_arg(args, unsigned int);
        }

        sp_u(num, &width, &count, fl_left, &buf_ptr, pad_zero, fl_space,
             precision);
        break;
      }
      case 's': {
        if (fl_l) {
          wchar_t *wstr = va_arg(args, wchar_t *);
          sp_s((char *)wstr, precision, &width, &count, fl_left, &buf_ptr,
               fl_l);
        } else {
          char *str = va_arg(args, char *);
          sp_s(str, precision, &width, &count, fl_left, &buf_ptr, fl_l);
        }
        break;
      }
      default:
        *buf_ptr++ = *format;
        count++;
        break;
    }

    format++;
  }
  *buf_ptr = '\0';
  va_end(args);
  return count;
}
