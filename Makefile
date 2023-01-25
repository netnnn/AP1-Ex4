sever.out: Server.o client.out CanberraDistance.o ChebyshevDistance.o CLI.o Command.o CommandOne.o CommandTwo.o CommandThree.o CommandFour.o CommandFive.o DefaultIO.o Distance.o EuclidianDistance.o KNN.o ManhattanDistance.o MinkowskiDistance.o SocketIO.o StandardIO.o StringfileToMap.o StrToVector.o
	g++ -std=c++11 Server.o CanberraDistance.o ChebyshevDistance.o CLI.o Command.o CommandOne.o CommandTwo.o CommandThree.o CommandFour.o CommandFive.o DefaultIO.o Distance.o EuclidianDistance.o KNN.o ManhattanDistance.o MinkowskiDistance.o SocketIO.o StandardIO.o StringfileToMap.o StrToVector.o -o server.out

client.out: Client.o CanberraDistance.o ChebyshevDistance.o CLI.o Command.o CommandOne.o CommandTwo.o CommandThree.o CommandFour.o CommandFive.o DefaultIO.o Distance.o EuclidianDistance.o KNN.o ManhattanDistance.o MinkowskiDistance.o SocketIO.o StandardIO.o StringfileToMap.o StrToVector.o
	g++ -std=c++11 Client.o CanberraDistance.o ChebyshevDistance.o CLI.o Command.o CommandOne.o CommandTwo.o CommandThree.o CommandFour.o CommandFive.o DefaultIO.o Distance.o EuclidianDistance.o KNN.o ManhattanDistance.o MinkowskiDistance.o SocketIO.o StandardIO.o StringfileToMap.o StrToVector.o -o client.out


Client.o: Client.cpp
	g++ -std=c++11 -c Client.cpp
Server.o: Server.cpp
	g++ -std=c++11 -c Server.cpp
CanberraDistance.o: CanberraDistance.cpp CanberraDistance.h
	g++ -std=c++11 -c CanberraDistance.cpp
ChebyshevDistance.o: ChebyshevDistance.cpp ChebyshevDistance.h
	g++ -std=c++11 -c ChebyshevDistance.cpp

CLI.o: CLI.cpp CLI.h
	g++ -std=c++11 -c CLI.cpp
Command.o: Command.cpp Command.h
	g++ -std=c++11 -c Command.cpp
CommandOne.o: CommandOne.cpp CommandOne.h
	g++ -std=c++11 -c CommandOne.cpp
CommandTwo.o: CommandTwo.cpp CommandTwo.h
	g++ -std=c++11 -c CommandTwo.cpp
CommandThree.o: CommandThree.cpp CommandThree.h
	g++ -std=c++11 -c CommandThree.cpp
CommandFour.o: CommandFour.cpp CommandFour.h
	g++ -std=c++11 -c CommandFour.cpp
CommandFive.o: CommandFive.cpp CommandFive.h
	g++ -std=c++11 -c CommandFive.cpp
DefaultIO.o: DefaultIO.cpp DefaultIO.h
	g++ -std=c++11 -c DefaultIO.cpp

Distance.o: Distance.cpp Distance.h
	g++ -std=c++11 -c Distance.cpp
EuclidianDistance.o: EuclidianDistance.cpp EuclidianDistance.h
	g++ -std=c++11 -c EuclidianDistance.cpp
KNN.o: KNN.cpp KNN.h
	g++ -std=c++11 -c KNN.cpp
ManhattanDistance.o: ManhattanDistance.cpp ManhattanDistance.h
	g++ -std=c++11 -c ManhattanDistance.cpp
MinkowskiDistance.o: MinkowskiDistance.cpp MinkowskiDistance.h
	g++ -std=c++11 -c MinkowskiDistance.cpp

SocketIO.o: SocketIO.cpp SocketIO.h
	g++ -std=c++11 -c SocketIO.cpp
StandardIO.o: StandardIO.cpp StandardIO.h
	g++ -std=c++11 -c StandardIO.cpp
StringfileToMap.o: StringfileToMap.cpp StringfileToMap.h
	g++ -std=c++11 -c StringfileToMap.cpp

StrToVector.o: StrToVector.cpp StrToVector.h
	g++ -std=c++11 -c StrToVector.cpp