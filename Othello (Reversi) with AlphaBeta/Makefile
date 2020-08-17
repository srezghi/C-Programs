reversi.exe: reversi.o board.o player.o 
	g++ -o reversi.exe reversi.o board.o player.o
		
reversi.o: reversi.cpp
	g++ -c reversi.cpp
	
board.o: board.cpp board.hpp
	g++ -c board.cpp
	
player.o: player.cpp
	g++ -c player.cpp

clean:
	rm -f *.exe *.o *.stackdump *~
