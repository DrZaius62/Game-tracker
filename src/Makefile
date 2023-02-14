#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Game.cpp utils.cpp xml_utils.cpp interface.cpp


#CC specifies which compiler to use
CC = g++

#COMPILER_FLAGS specifies the additional compilation options 
COMPILER_FLAGS = -w -g

#LINKER_FLAGS specifies the libraries to link against
LINKER_FLAGS = -l pugixml -lncurses

#OBJ_NAME name of the executable
OBJ_NAME = a.out 

#This is the target that compiles the executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
