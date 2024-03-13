MKFILE_PATH := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TARGET_DIR  := $(MKFILE_PATH)/build
TARGET      := $(TARGET_DIR)/3DViewer
SRC_DIR     := $(MKFILE_PATH)
SRC_STRIPPED:= back/parser.c 
SRC         := $(SRC_DIR)/$(SRC_STRIPPED)
CFLAGS      := --debug -Wall -Wextra -g


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


%.o: %.c
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
tests: back/parser.o back/tests/test.o
	-@gcc back/parser.o back/tests/test.o $(FLAGS) -o test
	./test


gcov_report: back/parser.c back/tests/test.c
	gcc  back/parser.c back/tests/test.c $(FLAGS) --coverage -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
ifeq ($(OS), Linux)
	xdg-open report/index.html
else
	open report/index.html
endif

dvi:
	cd documentation && \
	doxygen && \
	open html/index.html

dist: clean
	tar -cvzf 3DViewer.tar.gz Makefile CMakeLists.txt back/ front/ 

clang:
	clang-format -style=google -i front/*.cpp front/*.h
	clang-format -style=google -i back/*.c back/*.h

clean:
	find . -type f -name "*.o" -exec rm -f {} +
	find . -type f -name "*.txt.*" -exec rm -f {} +
	rm -rf ../build*
	rm -rf build/
	rm -rf ./test
	rm -rf report *.gcda *.gcno *.info