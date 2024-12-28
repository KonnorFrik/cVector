CC = gcc
LOCAL_GCOVR = gcovr

CFLAGS = -std=c11 -pedantic -g -Wall -Wextra
# CFLAGS += -Werror
COVERAGE_FLAGS = -lgcov --coverage
TEST_CFLAGS = $(COVERAGE_FLAGS)

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

# ============== LIBRARY ==============
LIB_NAME = cvector
LIB = lib$(LIB_NAME)

lib_static: $(LIB).a

$(LIB).a: $(OBJ)
	$(AR) src $@ $^

clean_lib_static:
	$(RM) $(LIB).a
# ============== LIBRARY ==============


# ============== TEST ==============
MAIN_TESTS_DIR = tests

CVECTOR_CREATOR_TESTS = $(MAIN_TESTS_DIR)/test_creators
CVECTOR_ACCESSORS_TESTS = $(MAIN_TESTS_DIR)/test_accessors
CVECTOR_MODIFIERS_TESTS = $(MAIN_TESTS_DIR)/test_modifiers
CVECTOR_CAPACITY_TESTS = $(MAIN_TESTS_DIR)/test_capacity

CVECTOR_ALL_TESTS_DIRS = $(CVECTOR_CREATOR_TESTS) $(CVECTOR_ACCESSORS_TESTS) $(CVECTOR_MODIFIERS_TESTS) $(CVECTOR_CAPACITY_TESTS)

CVECTOR_TEST_SRC = $(foreach dir, $(CVECTOR_ALL_TESTS_DIRS), $(wildcard $(dir)/*.c)) $(MAIN_TESTS_DIR)/test_cvector_main.c
CVECTOR_TEST_OBJ = $(CVECTOR_TEST_SRC:.c=.o)
CVECTOR_TEST_NAME = cvector_test

test_cvector: $(CVECTOR_TEST_NAME)
	./$(CVECTOR_TEST_NAME)

$(CVECTOR_TEST_NAME): CFLAGS += $(TEST_CFLAGS) $(shell pkg-config --cflags cmocka)
$(CVECTOR_TEST_NAME): LDFLAGS = $(shell pkg-config --libs cmocka)
$(CVECTOR_TEST_NAME): $(CVECTOR_TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

CVECTORM_TEST_DIR = $(MAIN_TESTS_DIR)/test_cvectorm_int
CVECTORM_TEST_SRC = $(wildcard $(CVECTORM_TEST_DIR)/*.c) $(MAIN_TESTS_DIR)/test_cvectorm_int_main.c
CVECTORM_TEST_OBJ = $(CVECTORM_TEST_SRC:.c=.o)
CVECTORM_TEST_NAME = cvector_macros_test

test_cvectorm: $(CVECTORM_TEST_NAME)
	./$(CVECTORM_TEST_NAME)

$(CVECTORM_TEST_NAME): CFLAGS += $(TEST_CFLAGS) $(shell pkg-config --cflags cmocka)
$(CVECTORM_TEST_NAME): LDFLAGS = $(shell pkg-config --libs cmocka)
$(CVECTORM_TEST_NAME): $(CVECTORM_TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean_test:
	$(RM) $(CVECTOR_TEST_NAME)
	$(RM) $(CVECTOR_TEST_OBJ)
	$(RM) $(CVECTORM_TEST_NAME)
	$(RM) $(CVECTORM_TEST_OBJ)
# ============== TEST ==============


# ============== COVERAGE ==============
gcov_report:
	@mkdir -p $(GCOV_DIR)
	$(LOCAL_GCOVR) -f src/.*/.*\.c --html-details -o $(GCOV_DIR)/$(REPORT)
	ln -f -s $(GCOV_DIR)/$(REPORT) ./$(REPORT)
	@printf "\n\tREPORT REPORT FILE: '\033[38;5;46m$(REPORT)\033[0m'\n"
	@echo;

clean_gcov:
	$(RM) $(shell find . -name "*.gcda")
	$(RM) $(shell find . -name "*.gcno")
	$(RM) ./$(GCOV_DIR)/*
	$(RM) -d ./$(GCOV_DIR)
# ============== COVERAGE ==============


doc:
	doxygen $(DOC_DIR)/Doxyfile
	ln -fs $(DOC_DIR)/html/index.html $(DOCUMENTATION)


# ============== CHECK ==============
##### STYLE
check_static:
	cppcheck --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem --std=c11 $(SRC) $(HEADERS)

check_leak: $(CVECTORM_TEST_NAME) $(CVECTOR_TEST_NAME)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CVECTORM_TEST_NAME)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CVECTOR_TEST_NAME)
# ============== CHECK ==============

clean: clean_test clean_gcov clean_lib_static
	$(RM) $(OBJ)
	$(RM) $(REPORT)
	$(RM) $(DOCUMENTATION)
	$(RM) -d ./$(DOC_DIR)/html/search/*
	$(RM) -d ./$(DOC_DIR)/html/*
	$(RM) -d ./$(DOC_DIR)/latex/*
	$(RM) -d ./$(DOC_DIR)/html
	$(RM) -d ./$(DOC_DIR)/latex

