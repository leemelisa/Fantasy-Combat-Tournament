# Program Name: Fantasy Combat Tournament
# Author: Melisa Lee
# Date: 11/18/2018

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3LDFLAGS = -lboost_date_time
LDFLAGS = -lboost_date_time

HEADER = Barbarian.hpp BlueMen.hpp Character.hpp Combat.hpp HarryPotter.hpp Medusa.hpp Menu.hpp Queue.hpp QueueNode.hpp validate.hpp Vampire.hpp

OBJS = Barbarian.o BlueMen.o Character.o Combat.o HarryPotter.o Medusa.o Menu.o Queue.o validate.o Vampire.o main.o

SRCS = Barbarian.cpp BlueMen.cpp Character.cpp Combat.cpp HarryPotter.cpp Medusa.cpp Menu.cpp Queue.cpp validate.cpp Vampire.cpp main.cpp

Project4: ${OBJS} ${HEADER}
	${CXX} ${LDFLAGS} ${OBJS} -o Project4
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *o Project4
