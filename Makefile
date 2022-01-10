#Copyright (c) 2022 user1687569
CXX = g++

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

VPATH = $(SRC_DIR)
INC_PATH = -I $(INC_DIR)

CXXFLAGS = $(INC_PATH)

TARGET := $(BIN_DIR)/bitcoin.exe

OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(wildcard $(SRC_DIR)/*.cpp)))

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY:clean
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*.exe

