Tum: Derle Calistir

Derle:
	g++ -I ./include/ -o ./lib/Naming.o -c ./src/Naming.cpp
	g++ -I ./include/ -o ./lib/RandomNumberGenerator.o -c ./src/RandomNumberGenerator.cpp
	g++ -I ./include/ -o ./lib/Move.o -c ./src/Move.cpp
	g++ -I ./include/ -o ./lib/Position.o -c ./src/Position.cpp
	g++ -I ./include/ -o ./lib/PositionList.o -c ./src/PositionList.cpp
	g++ -I ./include/ -o ./lib/Print.o -c ./src/Print.cpp
	g++ -I ./include/ -o ./lib/Game.o -c ./src/Game.cpp
	g++ -I ./include/ -o ./lib/PvP.o -c ./src/PvP.cpp
	g++ -I ./include/ -o ./lib/PvC.o -c ./src/PvC.cpp
	g++ -I ./include/ -o ./lib/CvC.o -c ./src/CvC.cpp
	g++ -I ./include/ -o ./lib/GameManager.o -c ./src/GameManager.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Naming.o ./lib/RandomNumberGenerator.o ./lib/Move.o ./lib/Position.o ./lib/PositionList.o ./lib/Print.o ./lib/Game.o ./lib/PvP.o ./lib/PvC.o ./lib/CvC.o ./lib/GameManager.o ./src/Main.cpp

Calistir:
	./bin/Test