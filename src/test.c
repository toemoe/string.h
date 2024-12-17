#include <check.h>

#include "s21_string.h"

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen("Hello Kitty"), strlen("Hello Kitty"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("12345"), strlen("12345"));
}
END_TEST

START_TEST(test_s21_strncat) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  ck_assert_str_eq(s21_strncat(str1, "Kitty and My Melody", 5),
                   strncat(str2, "Kitty and My Melody", 5));

  char str3[100] = "";
  char str4[100] = "";
  ck_assert_str_eq(s21_strncat(str3, "", 0), strncat(str4, "", 0));

  char str5[100] = "";
  char str6[100] = "";
  ck_assert_str_eq(s21_strncat(str5, "   ", 3), strncat(str6, "   ", 3));
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_ptr_eq(s21_strchr("Hello Kitty", 'l'), strchr("Hello Kitty", 'l'));
  ck_assert_ptr_eq(s21_strchr("", '\0'), strchr("", '\0'));
  ck_assert_ptr_eq(s21_strchr("12345", '5'), strchr("12345", '5'));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("Hello Kitty", "eo"),
                   strpbrk("Hello Kitty", "eo"));
  ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
  ck_assert_ptr_eq(s21_strpbrk("12345", "345"), strpbrk("12345", "345"));
}
END_TEST

START_TEST(test_s21_strncpy) {
  char str1[100];
  char str2[100];
  ck_assert_str_eq(s21_strncpy(str1, "and My Melody", 20),
                   strncpy(str2, "and My Melody", 20));

  char str3[100];
  char str4[100];
  ck_assert_str_eq(s21_strncpy(str3, "", 3), strncpy(str4, "", 3));

  char str5[100];
  char str6[100];
  ck_assert_str_eq(s21_strncpy(str5, "345", 5), strncpy(str6, "345", 5));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_ptr_eq(s21_strstr("Hello Kitty and My Melody", "Melody"),
                   strstr("Hello Kitty and My Melody", "Melody"));
  ck_assert_ptr_eq(s21_strstr("", ""), strstr("", ""));
  ck_assert_ptr_eq(s21_strstr("12345", "234"), strstr("12345", "234"));
}
END_TEST

START_TEST(test_s21_memcmp) {
  ck_assert_int_eq(s21_memcmp("Hello Kitty and My Melody", "Hello", 5),
                   memcmp("Hello Kitty and My Melody", "Hello", 5));
  ck_assert_int_eq(s21_memcmp("", "", 0), memcmp("", "", 0));
  ck_assert_int_eq(s21_memcmp("12345", "2145", 2), memcmp("12345", "2145", 2));
}
END_TEST

START_TEST(test_s21_memchr) {
  ck_assert_ptr_eq(s21_memchr("Hello Kitty and My Melody", 'l', 3),
                   memchr("Hello Kitty and My Melody", 'l', 3));
  ck_assert_ptr_eq(s21_memchr("", 'a', 0), memchr("", 'a', 0));
  ck_assert_ptr_eq(s21_memchr("123425", '2', 6), memchr("123425", '2', 6));
}
END_TEST

START_TEST(test_s21_memcpy) {
  char str1[100];
  char str2[100];
  ck_assert_mem_eq(s21_memcpy(str1, "Hello Kitty and My Melody", 11),
                   memcpy(str2, "Hello Kitty and My Melody", 11), 11);

  char str3[100];
  char str4[100];
  ck_assert_mem_eq(s21_memcpy(str3, "", 0), memcpy(str4, "", 0), 0);

  char str5[100];
  char str6[100];
  ck_assert_mem_eq(s21_memcpy(str5, "123456789", 6),
                   memcpy(str6, "123456789", 6), 6);
}
END_TEST

START_TEST(test_s21_memset) {
  char str1[100];
  char str2[100];
  ck_assert_mem_eq(s21_memset(str1, '*', 11), memset(str2, '*', 11), 11);

  char str3[100];
  char str4[100];
  ck_assert_mem_eq(s21_memset(str3, '\0', 0), memset(str4, '\0', 0), 0);

  char str5[100];
  char str6[100];
  ck_assert_mem_eq(s21_memset(str5, '1', 0), memset(str6, '1', 0), 0);
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp("Hello Kitty and My Melody", "Hello", 5),
                   strncmp("Hello Kitty and My Melody", "Hello", 5));
  ck_assert_int_eq(s21_strncmp("", "", 0), strncmp("", "", 0));
  ck_assert_int_eq(s21_strncmp("12345", "2145", 2),
                   strncmp("12345", "2145", 2));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("Hello, World!", 'o'),
                   strrchr("Hello, World!", 'o'));
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'd'), strrchr("abcdef", 'd'));
  ck_assert_ptr_eq(s21_strrchr("abcdef", 'z'), strrchr("abcdef", 'z'));
}
END_TEST

START_TEST(test_s21_strcspn) {
  ck_assert_int_eq(s21_strcspn("abcdef", "ae"), strcspn("abcdef", "ae"));
  ck_assert_int_eq(s21_strcspn("abcdef", "xyz"), strcspn("abcdef", "xyz"));
  ck_assert_int_eq(s21_strcspn("hello", "l"), strcspn("hello", "l"));
}
END_TEST

START_TEST(test_s21_strtok) {
  char str1[] = "Hello, world! How are you?";
  char str2[] = "Hello, world! How are you?";
  const char *delim = " ,!?";

  char *s21_token = s21_strtok(str1, delim);
  char *std_token = strtok(str2, delim);

  while (std_token != NULL && s21_token != NULL) {
    ck_assert_str_eq(s21_token, std_token);
    s21_token = s21_strtok(NULL, delim);
    std_token = strtok(NULL, delim);
  }

  ck_assert_ptr_null(s21_token);
  ck_assert_ptr_null(std_token);
}
END_TEST

START_TEST(test_sp_d_basic) {
  char buffer1[100], buffer2[100];
  int value = 123;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_basic_negative) {
  char buffer1[100], buffer2[100];
  int value = -123;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_width) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%5d", value);
  sprintf(buffer2, "%5d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_zero_padding) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%05d", value);
  sprintf(buffer2, "%05d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_align) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%-5d", value);
  sprintf(buffer2, "%-5d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_with_sign) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%+5d", value);
  sprintf(buffer2, "%+5d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_with_space) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "% d", value);
  sprintf(buffer2, "% d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_with_length_h) {
  char buffer1[100], buffer2[100];
  short int value = 42;

  s21_sprintf(buffer1, "%hd", value);
  sprintf(buffer2, "%hd", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_with_length_l) {
  char buffer1[100], buffer2[100];
  long int value = 42;

  s21_sprintf(buffer1, "%ld", value);
  sprintf(buffer2, "%ld", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_precision) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%.3d", value);
  sprintf(buffer2, "%.3d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_precision_arg) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%.*d", 3, value);
  sprintf(buffer2, "%.*d", 3, value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_negative) {
  char buffer1[100], buffer2[100];
  int value = -42;

  s21_sprintf(buffer1, "%-d", value);
  sprintf(buffer2, "%-d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_sign) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%-+d", value);
  sprintf(buffer2, "%-+d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_space) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%- d", value);
  sprintf(buffer2, "%- d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_zero) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%-.4d", value);
  sprintf(buffer2, "%-.4d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_d_left_width) {
  char buffer1[100], buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%-5d", value);
  sprintf(buffer2, "%-5d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// Тесты для %s

START_TEST(test_sp_s_basic) {
  char buffer1[100], buffer2[100];
  char *value = "Hello";

  s21_sprintf(buffer1, "%s", value);
  sprintf(buffer2, "%s", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_s_width) {
  char buffer1[100], buffer2[100];
  char *value = "Hello";

  s21_sprintf(buffer1, "%10s", value);
  sprintf(buffer2, "%10s", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_s_left_align) {
  char buffer1[100], buffer2[100];
  char *value = "Hello";

  s21_sprintf(buffer1, "%-10s", value);
  sprintf(buffer2, "%-10s", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_s_precision) {
  char buffer1[100], buffer2[100];
  char *value = "Hello, world!";

  s21_sprintf(buffer1, "%.5s", value);
  sprintf(buffer2, "%.5s", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_s_precision_arg) {
  char buffer1[100], buffer2[100];
  char *value = "Hello, world!";

  s21_sprintf(buffer1, "%.*s", 3, value);
  sprintf(buffer2, "%.*s", 3, value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_c_basic) {
  char buffer1[100], buffer2[100];
  char value = 'A';

  s21_sprintf(buffer1, "%c", value);
  sprintf(buffer2, "%c", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_c_width) {
  char buffer1[100], buffer2[100];
  char value = 'A';

  s21_sprintf(buffer1, "%5c", value);
  sprintf(buffer2, "%5c", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_c_left_align) {
  char buffer1[100], buffer2[100];
  char value = 'A';

  s21_sprintf(buffer1, "%-5c", value);
  sprintf(buffer2, "%-5c", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_c_fl_l) {
  char buffer1[100], buffer2[100];
  wchar_t value = 'A';

  s21_sprintf(buffer1, "%lc", value);
  sprintf(buffer2, "%lc", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_c_left_width) {
  char buffer1[100], buffer2[100];
  wchar_t value = 'A';

  s21_sprintf(buffer1, "%-lc", value);
  sprintf(buffer2, "%-lc", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_basic) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%f", value);
  sprintf(buffer2, "%f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_basic_negative) {
  char buffer1[100], buffer2[100];
  double value = -123.456;

  s21_sprintf(buffer1, "%f", value);
  sprintf(buffer2, "%f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_width) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%10f", value);
  sprintf(buffer2, "%10f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_precision) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%.2f", value);
  sprintf(buffer2, "%.2f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_precision_arg) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%.*f", 3, value);
  sprintf(buffer2, "%.*f", 3, value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_left_align) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%-10f", value);
  sprintf(buffer2, "%-10f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_zero_padding) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%010f", value);
  sprintf(buffer2, "%010f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_with_sign) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "%+10f", value);
  sprintf(buffer2, "%+10f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_with_space) {
  char buffer1[100], buffer2[100];
  double value = 123.456;

  s21_sprintf(buffer1, "% 10f", value);
  sprintf(buffer2, "% 10f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_with_fl_L) {
  char buffer1[100], buffer2[100];
  long double value = 123.456;

  s21_sprintf(buffer1, "%Lf", value);
  sprintf(buffer2, "%Lf", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_with_fl_latt) {
  char buffer1[100], buffer2[100];
  double value = 123;

  s21_sprintf(buffer1, "%#f", value);
  sprintf(buffer2, "%#f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_f_with_round) {
  char buffer1[100], buffer2[100];
  double value = 1.99999;

  s21_sprintf(buffer1, "%.3f", value);
  sprintf(buffer2, "%.3f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_basic) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%u", value);
  sprintf(buffer2, "%u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_width) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%10u", value);
  sprintf(buffer2, "%10u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_left_align) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%-10u", value);
  sprintf(buffer2, "%-10u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_zero_padding) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%010u", value);
  sprintf(buffer2, "%010u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_precision) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%.4u", value);
  sprintf(buffer2, "%.4u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_precision_arg) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%.*u", 3, value);
  sprintf(buffer2, "%.*u", 3, value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_with_fl_h) {
  char buffer1[100], buffer2[100];
  short unsigned int value = 12345;

  s21_sprintf(buffer1, "%hu", value);
  sprintf(buffer2, "%hu", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_with_fl_l) {
  char buffer1[100], buffer2[100];
  long unsigned int value = 12345;

  s21_sprintf(buffer1, "%lu", value);
  sprintf(buffer2, "%lu", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_u_left_precision) {
  char buffer1[100], buffer2[100];
  unsigned int value = 12345;

  s21_sprintf(buffer1, "%-.3u", value);
  sprintf(buffer2, "%-.3u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sp_percent) {
  char buffer1[100], buffer2[100];

  s21_sprintf(buffer1, "%%");
  sprintf(buffer2, "%%");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite *string_suite(void) {
  Suite *s = suite_create("String Functions");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strtok);

  tcase_add_test(tc_core, test_sp_d_basic);
  tcase_add_test(tc_core, test_sp_d_basic_negative);
  tcase_add_test(tc_core, test_sp_d_width);
  tcase_add_test(tc_core, test_sp_d_zero_padding);
  tcase_add_test(tc_core, test_sp_d_left_align);
  tcase_add_test(tc_core, test_sp_d_with_sign);
  tcase_add_test(tc_core, test_sp_d_with_space);
  tcase_add_test(tc_core, test_sp_d_precision);
  tcase_add_test(tc_core, test_sp_d_precision_arg);
  tcase_add_test(tc_core, test_sp_d_with_length_h);
  tcase_add_test(tc_core, test_sp_d_with_length_l);
  tcase_add_test(tc_core, test_sp_d_left_negative);
  tcase_add_test(tc_core, test_sp_d_left_sign);
  tcase_add_test(tc_core, test_sp_d_left_space);
  tcase_add_test(tc_core, test_sp_d_left_zero);
  tcase_add_test(tc_core, test_sp_d_left_width);

  tcase_add_test(tc_core, test_sp_s_basic);
  tcase_add_test(tc_core, test_sp_s_width);
  tcase_add_test(tc_core, test_sp_s_left_align);
  tcase_add_test(tc_core, test_sp_s_precision);
  tcase_add_test(tc_core, test_sp_s_precision_arg);

  tcase_add_test(tc_core, test_sp_c_basic);
  tcase_add_test(tc_core, test_sp_c_width);
  tcase_add_test(tc_core, test_sp_c_left_align);
  tcase_add_test(tc_core, test_sp_c_fl_l);
  tcase_add_test(tc_core, test_sp_c_left_width);

  tcase_add_test(tc_core, test_sp_f_basic);
  tcase_add_test(tc_core, test_sp_f_basic_negative);
  tcase_add_test(tc_core, test_sp_f_width);
  tcase_add_test(tc_core, test_sp_f_precision);
  tcase_add_test(tc_core, test_sp_f_precision_arg);
  tcase_add_test(tc_core, test_sp_f_left_align);
  tcase_add_test(tc_core, test_sp_f_zero_padding);
  tcase_add_test(tc_core, test_sp_f_with_sign);
  tcase_add_test(tc_core, test_sp_f_with_space);
  tcase_add_test(tc_core, test_sp_f_with_fl_L);
  tcase_add_test(tc_core, test_sp_f_with_fl_latt);
  tcase_add_test(tc_core, test_sp_f_with_round);

  tcase_add_test(tc_core, test_sp_u_basic);
  tcase_add_test(tc_core, test_sp_u_width);
  tcase_add_test(tc_core, test_sp_u_left_align);
  tcase_add_test(tc_core, test_sp_u_zero_padding);
  tcase_add_test(tc_core, test_sp_u_precision);
  tcase_add_test(tc_core, test_sp_u_precision_arg);
  tcase_add_test(tc_core, test_sp_u_with_fl_h);
  tcase_add_test(tc_core, test_sp_u_with_fl_l);
  tcase_add_test(tc_core, test_sp_u_left_precision);

  tcase_add_test(tc_core, test_sp_percent);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s = string_suite();
  SRunner *sr = srunner_create(s);

  printf("Running tests...\n");

  srunner_run_all(sr, CK_VERBOSE);
  srunner_set_log(sr, "test_log.txt");

  number_failed = srunner_ntests_failed(sr);
  printf("\n\nFailed tests: %d\n", number_failed);

  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
