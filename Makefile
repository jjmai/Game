COMPILE	= g++ -std=c++11 -Wall -c
LINK = g++ -std=c++11 -Wall -o

all		:	Game

Game		:	Game.o header.o
		$(LINK) Game Game.o header.o -g

Game.o		:	Game.cpp
		$(COMPILE) -cpp Game.cpp

header.o	:	header.cpp
		$(COMPILE) -cpp header.cpp

clean		:
		rm -rf *.o Game 

format		:
		clang-format -i -style=file *.cpp *.h
