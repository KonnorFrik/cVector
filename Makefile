.RECIPEPREFIX = >

CC = gcc
CFLAGS = -std=c11 -pedantic -g -Wall -Wextra -Werror
COVERAGE_FLAGS = -lgcov --coverage
TEST_CFLAGS = -std=c11 -pedantic -g -Wall $(COVERAGE_FLAGS)

REPORT = REPORT.html
GCOV_DIR = report
LOCAL_GCOVR = gcovr


CREATOR_SRC = src/creators
ALL_SRC_DIRS = $(CREATOR_SRC)
SRC = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.c))
HEADERS = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.h))
OBJ = $(SRC:.c=.o)

MAIN_TESTS = tests
CREATOR_TESTS = $(MAIN_TESTS)/test_creators
ALL_TESTS_DIRS = $(MAIN_TESTS) $(CREATOR_TESTS)

TEST_SRC = $(foreach dir, $(ALL_TESTS_DIRS), $(wildcard $(dir)/*.c))
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_NAME = cvector_test

test: $(TEST_NAME)
> ./$(TEST_NAME)

$(TEST_NAME): CFLAGS = $(TEST_CFLAGS)
$(TEST_NAME): LDFLAGS = -lcmocka
$(TEST_NAME): $(TEST_OBJ) $(OBJ)
> $(CC) $^ $(CFLAGS) $(LDFLAGS) -o $(TEST_NAME)

gcov_report:
> @mkdir -p $(GCOV_DIR)
> $(LOCAL_GCOVR) -f src/.*/.*\.c --html-details -o $(GCOV_DIR)/$(REPORT)
> ln -f -s $(GCOV_DIR)/$(REPORT) ./$(REPORT)
> @printf "\n\tREPORT REPORT FILE: '\033[38;5;46m$(REPORT)\033[0m'\n"
> @echo;

static:
> cppcheck --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem --std=c11 $(SRC) $(HEADERS)

clean:
> $(RM) $(TEST_OBJ)
> $(RM) $(TEST_NAME)
> $(RM) $(OBJ)
> $(RM) $(foreach dir, $(ALL_SRC_DIRS) $(ALL_TESTS_DIRS), $(wildcard $(dir)/*.gc*))
> $(RM) $(REPORT)
> $(RM) ./$(GCOV_DIR)/*
> rmdir $(GCOV_DIR) || true


show:
> @echo "TEST_SRC:"
> @echo $(TEST_SRC)
> @echo "TEST_OBJ:"
> @echo $(TEST_OBJ)
> @echo "SRC:"
> @echo $(SRC)
> @echo "OBJ:"
> @echo $(OBJ)
> @echo "gc*:"
> @echo $(foreach dir, $(ALL_SRC_DIRS) $(ALL_TESTS_DIRS), $(wildcard $(dir)/*.gc*))
