all:

		clear
		g++ -c Source/Main.cpp -o Output/Main.o
		g++ -c Source/HelpFunctions.cpp -o Output/HelpFunctions.o 	-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/Node.cpp -o Output/Node.o 					-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/Path.cpp -o Output/Path.o 					-lsfml-graphics -lsfml-system -lsfml-window
		
		g++ Output/Main.o -o Game -lsfml-graphics -lsfml-system -lsfml-window Output/HelpFunctions.o Output/Node.o Output/Path.o
		./Game
