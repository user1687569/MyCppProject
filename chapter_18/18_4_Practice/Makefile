#Copyright (c) 2022 user1687569
CXX = g++

OBJ_DIR = obj


TARGET := bitcoin.exe

OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(wildcard *.cpp)))

all: $(OBJ_DIR)
$(OBJ_DIR):
	-if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY:clean
clean:
	-if exist *.exe del *.exe
	-if exist $(OBJ_DIR)\*.o del $(OBJ_DIR)\*.o
	-if exist $(OBJ_DIR) rd $(OBJ_DIR)