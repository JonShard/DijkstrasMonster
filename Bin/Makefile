all:

		clear
		g++ -c Source/Main.cpp -o Output/Main.o -g -O0
		
		g++ -c Source/HelpFunctions.cpp -o Output/HelpFunctions.o -g -O0	-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/StateMachine.cpp -o Output/StateMachine.o -g -O0		-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/ScreenSetup.cpp -o Output/ScreenSetup.o -g -O0		-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/Node.cpp -o Output/Node.o -g -O0						-lsfml-graphics -lsfml-system -lsfml-window
		g++ -c Source/Path.cpp -o Output/Path.o -g -O0						-lsfml-graphics -lsfml-system -lsfml-window
		
		g++ Output/Main.o -o Game -g -O0 -lsfml-graphics -lsfml-system -lsfml-window Output/HelpFunctions.o Output/StateMachine.o Output/ScreenSetup.o Output/Node.o Output/Path.o
		
		./Game
