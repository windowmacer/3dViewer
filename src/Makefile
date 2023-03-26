CC						= gcc
CFLAGS					= -Wall -Werror -Wextra -std=c11 -pedantic -g
LDFLAGS					= $(shell pkg-config --cflags --libs check)
GCOV_FLAGS				= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS			= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

SRC_PROJECT_DIR			= Backend/logic/
SRC_TEST_DIR			= Backend/tests/
SRC_GIFLIB_DIR			= GUI/3DViewer/QtGifImage/giflib/
OBJ_PROJECT_DIR			= ../obj/logic/
OBJ_TEST_DIR			= ../obj/tests/
OBJ_GIFLIB_DIR			= ../obj/GIFLIB/

LIBRARY					= 3dviewer.a
GIF_LIBRARY				= giflib.a
APP_NAME				= 3DViewer
BUILD_FOLDERS			:= $(shell mkdir -p $(OBJ_PROJECT_DIR); mkdir -p $(OBJ_TEST_DIR); mkdir -p $(OBJ_GIFLIB_DIR))
SRC_PROJECT				:= $(wildcard $(SRC_PROJECT_DIR)*.c)
SRC_TEST				:= $(wildcard $(SRC_TEST_DIR)*.c)
SRC_GIFLIB				:= $(wildcard $(SRC_GIFLIB_DIR)*.c)
OBJ_PROJECT				:= $(patsubst $(SRC_PROJECT_DIR)%.c,$(OBJ_PROJECT_DIR)%.o,$(SRC_PROJECT))
OBJ_TEST				:= $(patsubst $(SRC_TEST_DIR)%.c,$(OBJ_TEST_DIR)%.o,$(SRC_TEST))
OBJ_GIFLIB				:= $(patsubst $(SRC_GIFLIB_DIR)%.c,$(OBJ_GIFLIB_DIR)%.o,$(SRC_GIFLIB))

all: install launch_app gcov_report uninstall clean

install: $(LIBRARY) $(GIF_LIBRARY)
	mv $(LIBRARY) GUI/3DViewer/lib$(LIBRARY)
	cmake -S GUI/3DViewer -B build
	make -C build
#	cp build/3DViewer $(APP_NAME)
	cp build/3DViewer.app/Contents/MacOS/3DViewer $(APP_NAME)

uninstall: clean
	rm -rf ../obj/
	rm -rf build
	rm -rf GUI/3DViewer/lib$(LIBRARY)
	rm -rf GUI/3DViewer/lib$(GIF_LIBRARY)
	rm -rf $(APP_NAME)
	rm -rf $(APP_NAME).tar.gz

dvi:
	open README.md

# посмотреть еще варианты архивации
dist: install
	tar -czf $(APP_NAME).tar.gz --directory=build/ .

launch_app:
	./$(APP_NAME)

$(LIBRARY): $(OBJ_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

$(GIF_LIBRARY): $(OBJ_GIFLIB)
	ar rc $(GIF_LIBRARY) $(OBJ_GIFLIB)
	ranlib $(GIF_LIBRARY)
	mv $(GIF_LIBRARY) GUI/3DViewer/lib$(GIF_LIBRARY)

tests: $(OBJ_TEST) $(LIBRARY)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(LDFLAGS)
	./test

gcov_report: $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
	./test
	lcov -t "test" -o gcov.info -c -d .
	genhtml -o report gcov.info
	rm -rf ./*.gc*
	make open

$(OBJ_PROJECT_DIR)%.o: $(SRC_PROJECT_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TEST_DIR)%.o: $(SRC_TEST_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_GIFLIB_DIR)%.o: $(SRC_GIFLIB_DIR)%.c
	$(CC) -c $< -o $@

clean:
	# rm -rf ../obj/
	rm -rf $(OBJ_PROJECT_DIR)*
	rm -rf $(OBJ_TEST_DIR)*
	rm -rf $(OBJ_GIFLIB_DIR)*
	rm -rf test
	rm -rf *.a
	rm -rf report
	rm -rf *.info
	rm -rf valgrind.txt

rebuild: clean tests

open: 
	open report/index.html

valgrind: rebuild
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i $(SRC_PROJECT_DIR)*
	clang-format --style=google -i $(SRC_TEST_DIR)*
	clang-format --style=google -i GUI/3DViewer/*.cpp
	clang-format --style=google -i GUI/3DViewer/*.h

.PHONY: all clean rebuild open clang valgrind docker
