# Executable file
EXECUTABLE = project

#
DIRECTORIES = ./src ./Game ./utils ./interface ./utils	

# Compiler and compiler flags
CXX = g++
#CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
CXXFLAGS = -g
CXXFLAGS += $(foreach dir, $(DIRECTORIES), -I$(dir))


# Directories
SRCDIR = .
OBJDIR = obj

#LIBS the libraries to link against
LIBS += -l pugixml -lncurses

#Source files
SOURCES = $(wildcard $(SRCDIR)/src/*.cpp) \
		  $(wildcard $(SRCDIR)/Game/*.cpp) \
          $(wildcard $(SRCDIR)/interface/*.cpp) \
          $(wildcard $(SRCDIR)/utils/*.cpp)
#SOURCES = $(wildcard $(DIRECTORIES)/*.cpp)
#INCLUDES = $(wildcard $(DIRECTORIES)/*.hpp)


INCLUDES = 	$(wildcard $(SRCDIR)/src/*.hpp) \
		  	$(wildcard $(SRCDIR)/Game/*.hpp) \
          	$(wildcard $(SRCDIR)/interface/*.hpp) \
          	$(wildcard $(SRCDIR)/utils/*.hpp)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo "Linking done"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilation done"

clean:
	@rm -rf $(OBJDIR)/* $(EXECUTABLE)
	@echo "Clean up done"


