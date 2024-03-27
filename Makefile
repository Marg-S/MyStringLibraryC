CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g 
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = $(shell pkg-config --cflags --libs check) -lcheck -lm 

OS := $(shell uname)

ifeq ($(OS),Linux)
	LDFLAGS += -lsubunit
endif

GCOV_HTML_DIR = report
SRC_DIR = .
OBJ_DIR = obj
OBJ_DIR_TEST = obj_test
TEST_DIR = tests

SRC = my_memchr.c my_memcpy.c my_strcspn.c my_strlen.c my_strncat.c my_strncmp.c my_strrchr.c my_strchr.c my_strtok.c my_memset.c my_memcmp.c my_strncpy.c my_strpbrk.c my_strstr.c my_sscanf.c my_to_upper.c my_to_lower.c my_insert.c my_trim.c my_strerror.c my_sprintf.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_TEST = $(addprefix $(OBJ_DIR_TEST)/, $(SRC:.c=.o))
TEST = my_tests.c $(patsubst %.c, test_%.c, $(SRC))
TEST_SRC = $(addprefix $(TEST_DIR)/, $(TEST))
TEST_OBJ = $(addprefix $(TEST_DIR)/$(OBJ_DIR)/, $(TEST:.c=.o))

LIB = my_string.a
EXECUTABLE = test_set
COVERAGE_INFO = coverage.info

all: clean gcov_html

$(LIB): ${OBJ}
	@echo "Building the static library..."
	ar rc $(LIB) $^
	ranlib $(LIB)

gcov_report: test
	@echo "Preparing a report..."
	gcov $(SRC)
	@echo "Generating HTML coverage report..."
	@mkdir -p $(GCOV_HTML_DIR)
	geninfo $(SRC_DIR) --output-file $(GCOV_HTML_DIR)/$(COVERAGE_INFO)
	genhtml $(GCOV_HTML_DIR)/$(COVERAGE_INFO) --output-directory $(GCOV_HTML_DIR)
	open $(GCOV_HTML_DIR)/index.html

test: clean ${EXECUTABLE}
	@echo "Running tests..."
	./${EXECUTABLE}

style:
	@echo "Checking styles..."
	clang-format -n -style=Google *.c *.h tests/*.c tests/*.h

format_style:
	@echo "Formatting styles..."
	clang-format -i -style=Google *.c *.h tests/*.c tests/*.h

clean:
	@echo "Cleaning up..."
	rm -rf *.o $(EXECUTABLE) *.gcov *.gcda *.gcno $(LIB) $(OBJ_DIR) $(OBJ_DIR_TEST) $(GCOV_HTML_DIR) ${TEST_DIR}/$(OBJ_DIR) $(TEST_DIR)/*.gcov $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno $(TEST_DIR)/$(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR_TEST)/%.o: %.c
	@mkdir -p $(OBJ_DIR_TEST)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c -o $@ $<

$(TEST_DIR)/$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c -o $@ $<

$(EXECUTABLE): $(TEST_OBJ) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $^ -o $@ $(LDFLAGS)  


.PHONY: all gcov_report test style format_style clean