CFLAGS = -Wall -Werror -Wextra -std=c11

SYSTEM := $(shell uname -s)
ifeq ($(SYSTEM),Linux)
    LFLAGS = -lcheck -lsubunit -lm -lrt -lpthread -L.
endif
ifeq ($(SYSTEM),Darwin)
	LFLAGS = -lcheck -lm -lpthread
endif

all: clean s21_string.a test

s21_string.a:
	gcc $(CFLAGS) -c s21_string.c -o s21_string.o
	gcc $(CFLAGS) -c s21_sprintf.c -o s21_sprintf.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o

test: s21_string.a
	gcc $(CFLAGS) -o test test.c s21_string.a $(LFLAGS)
	@./test

gcov_report: test
	gcc -fprofile-arcs -ftest-coverage -g -c s21_string.c -o s21_string.o
	gcc -fprofile-arcs -ftest-coverage -g -c s21_sprintf.c -o s21_sprintf.o
	gcc -fprofile-arcs -ftest-coverage -g -o test test.c s21_string.o s21_sprintf.o $(LFLAGS)
	@./test
	mkdir gcov_report
	gcov -n -o . s21_string.c
	gcov -n -o . s21_sprintf.c
	lcov -c -d ./ --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./gcov_report/

clean:
	rm -rf *.o *.a test coverage.info *.gcda *.gcno out
