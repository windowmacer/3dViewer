CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -std=c11 -pedantic -g #-fsanitize=address
GCOV_FLAGS		= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS	= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
CHECK_FLAGS		= $(shell pkg-config --cflags --libs check)

LIBRARY			= 3dviewer.a
APP_NAME		= 3DViewer
SRC_PROJECT		= $(wildcard Backend/logic/*.c)
SRC_TEST		= $(wildcard Backend/tests/*.c)
OBJ_PROJECT		= fillingNode.o get_next_line.o parserOBJ.o utilsNode.o # $(SRC_PROJECT:.c=.o)
OBJ_TEST		= test_core.o test_parser.o # $(SRC_TEST:.c=.o)

all: install launch_app gcov_report uninstall clean

install: $(LIBRARY)
	mv $(LIBRARY) GUI/3DViewer/lib$(LIBRARY)
	cmake -S GUI/3DViewer -B build
	make -C build
	cp build/3DViewer $(APP_NAME)

uninstall: clean
	rm -rf build
	rm -rf GUI/3DViewer/lib$(LIBRARY)
	rm -rf $(APP_NAME)
	rm -rf $(APP_NAME).tar.gz

dvi:
	open README.md
	# можно сделать через doxygen, но там нужно будет описание для функций составлять

dist: install
	tar -czf SmartCalculator.tar.gz --directory=build/ .
	mv SmartCalculator.tar.gz ../SmartCalculator.tar.gz

launch_app:
	./$(APP_NAME)

$(LIBRARY): $(SRC_PROJECT)
	$(CC) $(CFLAGS) -c $(SRC_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

test: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS)
	./test

gcov_report: clean $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(CHECK_FLAGS)
	./test
	lcov -t "test" -o gcov.info -c -d .
	genhtml -o report gcov.info
	rm -rf ./*.gc*
	make open

$(OBJ_TEST):
	$(CC) $(CFLAGS) -c $(SRC_TEST)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info
	rm -rf valgrind.txt

rebuild: clean test

open: 
	open report/index.html

valgrind: rebuild
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i Backend/logic/*
	clang-format --style=google -i Backedn/tests/*
	clang-format --style=google -i GUI/3DViewer/*.cpp
	clang-format --style=google -i GUI/3DViewer/*.h

.PHONY: all clean rebuild open clang valgrind docker


