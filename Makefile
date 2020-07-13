CC = g++
exe_file = crazy8
$(exe_file): card.o main.o deck.o game.o hand.o
	$(CC) card.o main.o deck.o game.o hand.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
main.o: main.cpp
	$(CC) -c main.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
game.o: game.cpp
	$(CC) -c game.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp


clean:
	rm –f *.out *.o $(exe_file)