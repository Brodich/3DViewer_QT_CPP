CC = g++ -Wall
MKFILE_PATH := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGET_DIR  := $(MKFILE_PATH)/build
TARGET      := $(TARGET_DIR)/3DViewer
SRC_DIR     := $(MKFILE_PATH)
SRC_STRIPPED:= model/parser.c 
SRC         := $(SRC_DIR)/$(SRC_STRIPPED)
CFLAGS      := --debug -Wall -Wextra -g
TEST_NAME = test_model
OTHER_LIBS = -lgtest -lgcov -fno-elide-constructors  
GCOVFLAGS = -L. --coverage


ifeq ($(OS), Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
	INSTALL_OS = ./viewer
else
	FLAGS = -lcheck -lm
	INSTALL_OS = viewer.app/Contents/MacOS/viewer
endif

all: clang install 
	-@mkdir $(TARGET_DIR)
	gcc $(SRC) $(CFLAGS) -o $(TARGET)
	build/3DViewer

%.o: %.cc
	$(CC) -c -o $@ $<

info:
	@echo -e "MKFILE_PATH := $(MKFILE_PATH)"
	@echo -e "TARGET_DIR  := $(TARGET_DIR)"
	@echo -e "TARGET      := $(TARGET)"
	@echo -e "SRC_DIR     := $(SRC_DIR)"
	@echo -e "SRC         := $(SRC)"
	@echo -e "CFLAGS      := $(CFLAGS)"

run:
	cd build && \
	$(INSTALL_OS)

install:
	-@mkdir build 
	cd build && \
	cmake .. && \
	make && \
	unset GTK_PATH && \
	$(INSTALL_OS)

uninstall:
	rm -rf build/ *.tar.gz

.PHONY: test 
tests: clang
	$(CC) model/parser.cc tests/$(TEST_NAME).cc $(FLAGS) $(OTHER_LIBS) -o tests/$(TEST_NAME)
	tests/$(TEST_NAME)

gcov_report: clang
	$(CC) -w model/parser.cc tests/$(TEST_NAME).cc  $(OTHER_LIBS) $(GCOVFLAGS) -o test
	./test
ifeq ($(OS), Linux)
	lcov --no-external -t test -o rep.info -c -d .
else 
	lcov --ignore-errors mismatch --no-external -t test -o rep.info -c -d .
endif
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

dvi:
	cd documentation && \
	doxygen && \
	open html/index.html

dist: clean
	tar -cvzf 3DViewer.tar.gz Makefile CMakeLists.txt model/ view/ controller/ assets/ tests/ documentation/

clang:
	-@clang-format -style=google -i view/*.cc view/*.h
	-@clang-format -style=google -i controller/*.h
	-@clang-format -style=google -i model/*.cc model/*.h
	-@clang-format -style=google -i tests/*.cc

clean:
	-@find . -type f -name "*.o" -exec rm -f {} +
	-@find . -type f -name "*.txt.*" -exec rm -f {} +
	-@rm -rf ../build*
	-@rm -rf build/
	-@rm tests/$(TEST_NAME) test
	-@rm -rf report *.gcda *.gcno *.info
