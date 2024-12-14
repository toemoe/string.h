#include <check.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

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
