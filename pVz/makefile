pvz: main.o Menu.o Play.o gameover.o gameplay.o line.o  square.o plant.o zombie.o bullet.o card.o sun.o
	g++ -std=c++20 main.o Menu.o Play.o gameover.o gameplay.o line.o square.o bullet.o plant.o zombie.o card.o sun.o -o pvz.out  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -std=c++20 -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++20 -c Menu.cpp

Play.o: Play.cpp
	g++ -std=c++20 -c Play.cpp

gameover.o: gameover.cpp
	g++ -std=c++20 -c gameover.cpp

gameplay.o: gameplay.cpp
	g++ -std=c++20 -c gameplay.cpp

line.o: line.cpp
	g++ -std=c++20 -c line.cpp

square.o: square.cpp
	g++ -std=c++20 -c square.cpp

bullet.o: bullet.cpp
	g++ -std=c++20 -c bullet.cpp

plant.o: plant.cpp
	g++ -std=c++20 -c plant.cpp

zombie.o: zombie.cpp
	g++ -std=c++20 -c zombie.cpp

card.o: card.cpp
	g++ -std=c++20 -c card.cpp

sun.o: sun.cpp
	g++ -std=c++20 -c sun.cpp

clean:
	rm *.o pvz.out

