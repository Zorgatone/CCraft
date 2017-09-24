# Makefile for CCraft
NAME = ccraft
CC = gcc
BUILD_FOLDER = build
SRC_FOLDER = src
OBJECT_FILES = $(BUILD_FOLDER)/main.o $(BUILD_FOLDER)/player.o $(BUILD_FOLDER)/die.o $(BUILD_FOLDER)/save_manager.o $(BUILD_FOLDER)/util.o $(BUILD_FOLDER)/version.o
RM = rm -rf
MKDIR = mkdir -p
EXECUTABLE = $(BUILD_FOLDER)/$(NAME).exe
CC_FLAGS = -g -O0 -pedantic -Wall -std=c11 -D__STDC_WANT_LIB_EXT1__=1 -D__STDC_WANT_LIB_EXT2__=1

.PHONY: all $(EXECUTABLE)
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) $(OBJECT_FILES) -o $(EXECUTABLE)

$(BUILD_FOLDER)/main.o: $(SRC_FOLDER)/main.c $(SRC_FOLDER)/player.h $(SRC_FOLDER)/version.h $(SRC_FOLDER)/save_manager.h $(SRC_FOLDER)/util.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/main.c -o $(BUILD_FOLDER)/main.o 

$(BUILD_FOLDER)/player.o: $(SRC_FOLDER)/player.c $(SRC_FOLDER)/player.h $(SRC_FOLDER)/ext_string.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/player.c -o $(BUILD_FOLDER)/player.o

$(BUILD_FOLDER)/die.o: $(SRC_FOLDER)/die.c $(SRC_FOLDER)/die.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/die.c -o $(BUILD_FOLDER)/die.o

$(BUILD_FOLDER)/save_manager.o: $(SRC_FOLDER)/save_manager.c $(SRC_FOLDER)/save_manager.h $(SRC_FOLDER)/util.h $(SRC_FOLDER)/version.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/save_manager.c -o $(BUILD_FOLDER)/save_manager.o

$(BUILD_FOLDER)/util.o: $(SRC_FOLDER)/util.c $(SRC_FOLDER)/util.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/util.c -o $(BUILD_FOLDER)/util.o

$(BUILD_FOLDER)/version.o: $(SRC_FOLDER)/version.c $(SRC_FOLDER)/version.h
	$(CC) $(CC_FLAGS) -c $(SRC_FOLDER)/version.c -o $(BUILD_FOLDER)/version.o

$(SRC_FOLDER)/version.h: $(SRC_FOLDER)/order32.h
$(SRC_FOLDER)/util.h: $(SRC_FOLDER)/order32.h $(SRC_FOLDER)/die.h
$(SRC_FOLDER)/save_manager.h: $(SRC_FOLDER)/player.h

#$(BUILD_FOLDER)/:
#	$(MKDIR) $(BUILD_FOLDER)/

.PHONY: clean
clean:
	$(RM) $(OBJECT_FILES) $(EXECUTABLE)
	$(RM) **/*.o **/*.out **/*.exe **/*.obj **/*.dll **/*.dylib **/*.lib *.o *.out *.exe *.obj *.dll *.dylib *.lib
	$(RM) **/\#*\# **/*\~ */\#*\# *\~
