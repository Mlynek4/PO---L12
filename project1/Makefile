# define the C++ compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS = -g -Wall -std=c++17

# define project directory
PROJECT_DIR = ./

# define any directories containing header files other than /usr/include
INCLUDES = -I$(PROJECT_DIR)include/CliChess

# define library paths in addition to /usr/lib
LFLAGS = 

# define any libraries to link into executable:
# LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# define the C++ source files
SRCS = src/App.cpp src/CliChess/GameRunner.cpp src/CliChess/Bishop.cpp src/CliChess/Board.cpp src/CliChess/King.cpp src/CliChess/Knight.cpp src/CliChess/Pawn.cpp src/CliChess/Piece.cpp src/CliChess/Queen.cpp src/CliChess/Rook.cpp

# define the C object files 
#   This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#   For each word in 'name' replace 'string1' with 'string2'
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = CliChess

.PHONY: clean

all:    $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled

$(MAIN): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS) $(LFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	del /f src\App.o src\GameRunner.cpp src\CliChess\Bishop.o src\CliChess\Board.o src\CliChess\King.o src\CliChess\Knight.o src\CliChess\Pawn.o src\CliChess\Piece.o src\CliChess\Queen.o src\CliChess\Rook.o CliChess.exe
