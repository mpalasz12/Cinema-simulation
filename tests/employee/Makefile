CC=g++
FILE=worker
DIR=../../src/

all : cc

cc:
	$(CC) -g *.cpp $(DIR)$(FILE).cpp $(DIR)schedule.cpp $(DIR)day.cpp $(DIR)register.cpp -o ../$(FILE)_tests.exe -Wall -Werror -std=c++20

clean :
	rm $(FILE)_tests.exe
