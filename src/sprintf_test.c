#include <check.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

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

Suite *s21_sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");
  tc_core = tcase_create("Core");

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
  Suite *s = s21_sprintf_suite();
  SRunner *sr = srunner_create(s);

  printf("Running tests...\n");

  srunner_run_all(sr, CK_VERBOSE);
  srunner_set_log(sr, "test_log.txt");

  number_failed = srunner_ntests_failed(sr);
  printf("\n\nFailed tests: %d\n", number_failed);

  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
