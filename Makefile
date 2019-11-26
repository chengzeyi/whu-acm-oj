# tool marcros
CC := clang++
CCFLAG := -std=gnu++14 -Wall
DBGFLAG := -g -DDEBUG
CCOBJFLAG := $(CCFLAG) -c

# path marcros
BIN_PATH := bin
OBJ_PATH := obj
SRC_PATH := src
DBG_PATH := debug

MKDIR := mkdir -p

# compile marcros
TARGET_NAME := main
ifeq ($(OS),Windows_NT)
	TARGET_NAME := $(addsuffix .exe, $(TARGET_NAME))
endif
TARGET := $(BIN_PATH)/$(TARGET_NAME)

TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*, .c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DBG_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ) \
	$(OBJ_DEBUG)
CLEAN_LIST := $(TARGET) \
	$(TARGET_DEBUG) \
	$(DISTCLEAN_LIST)

# non-phony targets
$(TARGET): $(OBJ)
	$(MKDIR) $(BIN_PATH)
	$(CC) $(CCFLAG) -o $@ $^

$(TARGET_DEBUG): $(OBJ_DEBUG)
	$(MKDIR) $(DBG_PATH)
	$(CC) $(CCFLAG) $(DBGFLAG) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(MKDIR) $(OBJ_PATH)
	$(CC) $(CCOBJFLAG) -o $@ $<

$(DBG_PATH)/%.o: $(SRC_PATH)/%.c*
	$(MKDIR) $(DBG_PATH)
	$(CC) $(CCOBJFLAG) $(DBGFLAG) -o $@ $<

# phony rules

# default rule
.PHONY: default
default: build

.PHONY: build
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo DISTCLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)

.PHONY: run
run: $(TARGET)
	@./$(TARGET)

.PHONY: rundebug
rundebug: $(TARGET_DEBUG)
	@./$(TARGET_DEBUG)

