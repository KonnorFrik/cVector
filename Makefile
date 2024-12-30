PROJECT_NAME = cVector
PROJECT_VERSION = 0_1_0

CC = gcc
LOCAL_GCOVR = gcovr

CFLAGS = -std=c11 -pedantic -g -Wall -Wextra
# CFLAGS += -Werror
COVERAGE_FLAGS = -lgcov --coverage
TEST_CFLAGS = $(COVERAGE_FLAGS)

REPORT = REPORT.html
GCOV_DIR = report



# ============== LIBRARY ==============
CREATOR_SRC = src/creators
ACCESSORS_SRC = src/accessors
MODIFIERS_SRC = src/modifiers
CAPACITY_SRC = src/capacity

ALL_SRC_DIRS = $(CREATOR_SRC) $(ACCESSORS_SRC) $(MODIFIERS_SRC) $(CAPACITY_SRC)

# HEADERS = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.h)) cvector_macros.h cvector.h
HEADERS = $(shell find . -name "*.h")
SRC = $(foreach dir, $(ALL_SRC_DIRS), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

LIB_NAME = cvector
LIB = lib$(LIB_NAME)

lib_static: $(LIB).a

$(LIB).a: $(OBJ)
	$(AR) src $@ $^

clean_lib_static:
	$(RM) $(LIB).a

clean_artefacts:
	$(RM) $(OBJ)
# ============== LIBRARY ==============


# ============== TEST ==============
# === test cvector
MAIN_TESTS_DIR = tests

CVECTOR_TEST_DIRS = $(MAIN_TESTS_DIR)/test_cvector

CVECTOR_TEST_SRC = $(foreach dir, $(CVECTOR_TEST_DIRS), $(wildcard $(dir)/*.c))
CVECTOR_TEST_SRC += $(MAIN_TESTS_DIR)/test_cvector_main.c
CVECTOR_TEST_OBJ = $(CVECTOR_TEST_SRC:.c=.o)
CVECTOR_TEST_NAME = cvector_test

test_cvector: $(CVECTOR_TEST_NAME)
	./$(CVECTOR_TEST_NAME)

$(CVECTOR_TEST_NAME): CFLAGS += $(TEST_CFLAGS) $(shell pkg-config --cflags cmocka)
$(CVECTOR_TEST_NAME): LDFLAGS = $(shell pkg-config --libs cmocka)
$(CVECTOR_TEST_NAME): $(CVECTOR_TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# === test cvectorm (macros version)
CVECTORM_TEST_DIRS = $(MAIN_TESTS_DIR)/test_cvectorm_int $(MAIN_TESTS_DIR)/test_cvectorm_struct_1
CVECTORM_TEST_SRC = $(foreach dir, $(CVECTORM_TEST_DIRS), $(wildcard $(dir)/*.c))
CVECTORM_TEST_SRC += $(MAIN_TESTS_DIR)/test_cvectorm_int_main.c
CVECTORM_TEST_OBJ = $(CVECTORM_TEST_SRC:.c=.o)
CVECTORM_TEST_NAME = cvector_macros_test

test_cvectorm: $(CVECTORM_TEST_NAME)
	./$(CVECTORM_TEST_NAME)

$(CVECTORM_TEST_NAME): CFLAGS += $(TEST_CFLAGS) $(shell pkg-config --cflags cmocka)
$(CVECTORM_TEST_NAME): LDFLAGS = $(shell pkg-config --libs cmocka)
$(CVECTORM_TEST_NAME): $(CVECTORM_TEST_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# === test all
test: test_cvectorm test_cvector

clean_test:
	$(RM) $(CVECTOR_TEST_NAME)
	$(RM) $(CVECTOR_TEST_OBJ)
	$(RM) $(CVECTORM_TEST_NAME)
	$(RM) $(CVECTORM_TEST_OBJ)
# ============== TEST ==============


# ============== COVERAGE ==============
gcov_report:
	mkdir -p $(GCOV_DIR)
	$(LOCAL_GCOVR) -f src/.*/.*\.c -f tests/test_cvectorm.* --html-details -o $(GCOV_DIR)/$(REPORT)
	ln -f -s $(GCOV_DIR)/$(REPORT) ./$(REPORT)
	@printf "\n\tREPORT REPORT FILE: '\033[38;5;46m$(REPORT)\033[0m'\n"
	@echo;

clean_gcov:
	$(RM) $(shell find . -name "*.gcda")
	$(RM) $(shell find . -name "*.gcno")
	$(RM) ./$(GCOV_DIR)/*
	$(RM) -d ./$(GCOV_DIR)

clean_report:
	$(RM) $(REPORT)
# ============== COVERAGE ==============


# ============== DOCUMENTATION ==============
DOC_DIR = documentation
DOCUMENTATION_NAME = $(PROJECT_NAME)_$(PROJECT_VERSION)_doc
DOCUMENTATION_HTML = $(DOCUMENTATION_NAME).html

doc:
	doxygen $(DOC_DIR)/Doxyfile
	ln -fs $(DOC_DIR)/html/index.html $(DOCUMENTATION)

clean_doc_artefacts:
	$(RM) -d ./$(DOC_DIR)/html/search/*
	$(RM) -d ./$(DOC_DIR)/html/*
	$(RM) -d ./$(DOC_DIR)/latex/*
	$(RM) -d ./$(DOC_DIR)/html
	$(RM) -d ./$(DOC_DIR)/latex

clean_doc:
	$(RM) $(DOCUMENTATION)
# ============== DOCUMENTATION ==============


# ============== CHECK ==============
check_static:
	cppcheck --enable=all --suppress=unusedFunction --suppress=missingIncludeSystem --std=c11 $(SRC) $(HEADERS)

check_leak: $(CVECTORM_TEST_NAME) $(CVECTOR_TEST_NAME)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CVECTORM_TEST_NAME)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(CVECTOR_TEST_NAME)
# ============== CHECK ==============


clean: clean_test clean_gcov clean_report clean_doc_artefacts clean_doc clean_artefacts

