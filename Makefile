main: main.cpp
	clang main.cpp -o main -lstdc++

clean:
	unlink main