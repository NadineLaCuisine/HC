CC=g++
CFLAGS=  -Wall  -Ofast -std=c++11  -flto -pipe -funit-at-a-time  -Wfatal-errors -fopenmp
LDFLAGS=-flto -lpthread -fopenmp



EXEC=bin

all: $(EXEC)



solve.o: solve.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

utils.o: utils.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

bin: main.o parser.o   utils.o solve.o
	$(CC) -o $@ $^ $(LDFLAGS)

parser.o: parser.cpp
	$(CC) -o $@ -c $< $(CFLAGS)



clean:
	rm -rf *.o
	rm -rf $(EXEC)


rebuild: clean $(EXEC)
