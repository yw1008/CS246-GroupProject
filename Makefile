CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -MMD -Werror=vla
EXEC = chess

OBJECTS = main.o game.o board.o piece.o player.o human.o computer.o textdisplay.o subject.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

%.o: %.cc
	${CXX} ${CXXFLAGS} -c $< -o $@

-include ${DEPENDS}

.PHONY: clean
clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}
