all:

		clear
		g++ -c Source/Main.cpp -o Output/Main.o

		g++ -c Source/HelpFunctions.cpp -o Output/HelpFunctions.o	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		g++ -c Source/StateMachine.cpp -o Output/StateMachine.o		-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		g++ -c Source/ScreenSetup.cpp -o Output/ScreenSetup.o		-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		g++ -c Source/Node.cpp -o Output/Node.o						-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		g++ -c Source/Path.cpp -o Output/Path.o						-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		g++ -c Source/SoundManager.cpp -o Output/SoundManager.o	 	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

		echo "\n\n"
		g++ Output/Main.o -o Game Output/HelpFunctions.o Output/StateMachine.o Output/ScreenSetup.o Output/Node.o Output/Path.o Output/SoundManager.o -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
		
		./Game
