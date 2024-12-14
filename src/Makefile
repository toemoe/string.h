CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11

all: s21_string.a s21_sprintf.a

s21_string.a:
	gcc $(CFLAGS) -c s21_string.c -o s21_string.o
	ar rcs s21_string.a s21_string.o

s21_sprintf.a:
	gcc $(CFLAGS) -c s21_sprintf.c -o s21_sprintf.o
	ar rcs s21_sprintf.a s21_sprintf.o


string_test:
	gcc -o test_s21_string string_test.c s21_string.a -lcheck -lm -pthread
	@./test_s21_string

gcov_report_string:
	gcc -fprofile-arcs -ftest-coverage -g -o test_s21_string string_test.c s21_string.c -lcheck -lm -pthread
	@./test_s21_string
	gcov -n -o . s21_string.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html
	rm -rf coverage.info
	rm -rf test_program
	rm -rf coverage.info
	rm -rf *.gcda
	rm -rf *.gcno
	rm test_s21_string

sprintf_test:
	gcc -o test_s21_sprintf sprintf_test.c s21_sprintf.a -lcheck -lm -pthread
	@./test_s21_sprintf

gcov_report_sprintf:
	gcc -fprofile-arcs -ftest-coverage -g -o test_s21_sprintf sprintf_test.c s21_sprintf.c -lcheck -lm -pthread
	@./test_s21_sprintf
	gcov -n -o . s21_sprintf.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html
	rm -rf coverage.info
	rm -rf coverage.info
	rm -rf *.gcda
	rm -rf *.gcno
	rm test_s21_sprintf

clean:
	rm -rf *.a *.o test_s21_string test_s21_sprintf coverage.info *.gcda *.gcno