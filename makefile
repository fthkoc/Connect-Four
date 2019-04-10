
all:
	g++ -c main.cpp -std=c++11
	g++ -o exe main.o

clean:
	rm *.o exe
