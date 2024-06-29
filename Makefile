.RECIPEPREFIX = >

CC = gcc
LOCAL_GCOVR = gcovr


CFLAGS = -std=c11 -pedantic -g -Wall -Wextra -Werror
COVERAGE_FLAGS = -lgcov --coverage
TEST_CFLAGS = -std=c11 -pedantic -g -Wall $(COVERAGE_FLAGS)


REPORT = REPORT.html
GCOV_DIR = report

DOC_DIR = documentation
DOCUMENTATION = Documentation.html


CREATOR_SRC = src/creators
ACCESSORS_SRC = src/accessors
MODIFIERS_SRC = src/modifiers
CAPACITY_SRC = src/capacity

ALL_SRC_DIRS = $(CREATOR_SRC) $(ACCESSORS_SRC) $(MODIFIERS_SRC)
ALL_SRC_DIRS += $(CAPACITY_SRC)

SRC = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.c))
HEADERS = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.h))
OBJ = $(SRC:.c=.o)

MAIN_TESTS = tests
CREATOR_TESTS = $(MAIN_TESTS)/test_creators
ACCESSORS_TESTS = $(MAIN_TESTS)/test_accessors
MODIFIERS_TESTS = $(MAIN_TESTS)/test_modifiers
CAPACITY_TESTS = $(MAIN_TESTS)/test_capacity

ALL_TESTS_DIRS = $(MAIN_TESTS) $(CREATOR_TESTS) $(ACCESSORS_TESTS) 
ALL_TESTS_DIRS += $(MODIFIERS_TESTS) $(CAPACITY_TESTS)

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

doc:
> doxygen $(DOC_DIR)/Doxyfile
> ln -fs $(DOC_DIR)/html/index.html $(DOCUMENTATION)

check_static:
> cppcheck --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem --std=c11 $(SRC) $(HEADERS)

check_leak: $(TEST_NAME)
> valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_NAME)

clean:
> $(RM) $(TEST_OBJ)
> $(RM) $(TEST_NAME)
> $(RM) $(OBJ)
> $(RM) $(foreach dir, $(ALL_SRC_DIRS) $(ALL_TESTS_DIRS), $(wildcard $(dir)/*.gc*))
> $(RM) $(REPORT)
> $(RM) $(DOCUMENTATION)
> $(RM) ./$(GCOV_DIR)/*
> $(RM) -d ./$(DOC_DIR)/html/search/*
> $(RM) -d ./$(DOC_DIR)/html/*
> $(RM) -d ./$(DOC_DIR)/latex/*
> $(RM) -d ./$(DOC_DIR)/html
> $(RM) -d ./$(DOC_DIR)/latex
> $(RM) -d ./$(GCOV_DIR)


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
