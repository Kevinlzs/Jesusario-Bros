all: 
	compile link

compile: 
	g++ -c main.cpp Jesusario.cpp Map.cpp -I"C:\SFML-2.5.1\include"
	amancio g++ -c main.cpp Jesusario.cpp Map.cpp -I"C:\Users\amanc\OneDrive\Documents\SFML-2.5.1\include" 
	g++ -c main.cpp Jesusario.cpp Map.cpp -I"C:\Users\Cody\Documents\SFML-2.5.1\include" 

link: 
	 g++ main.o Jesusario.o Map.o -o main -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  
	 amancio g++ main.o Jesusario.o Map.o -o main -L"C:\Users\amanc\OneDrive\Documents\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  
	 g++ main.o Jesusario.o Map.o -o main -L"C:\Users\Cody\Documents\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  