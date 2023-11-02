CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework 
DEPS = Sokoban.cpp Sokoban.hpp main.cpp CPPLINT.cfg

.PHONY: all Sokoban clean lint

all: Sokoban

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

Sokoban: main.o Sokoban.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o Sokoban

lint:
	cpplint *.cpp *.hpp
