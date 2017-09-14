#makefile

final: main.o Vector.o Matrix.o
	g++ main.o Vector.o Matrix.h

main.o: main.cpp Vector.h Matrix.h
	g++ -Wall -c  main.cpp Vector.h Matrix.h

Vector.o: Vector.cpp Vector.h
	g++ -Wall -c Vector.cpp Vector.h

Matrix.o: Vector.h Matrix.h Matrix.cpp
	g++ -Wall -c Vector.h Matrix.h Matrix.cpp

clean:
	rm *.o *.h.gch
