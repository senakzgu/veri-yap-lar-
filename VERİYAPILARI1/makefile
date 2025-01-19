Tum: derleme calistirma

derleme: 
	g++ -I ./include/ -o ./lib/gen.o -c ./src/gen.cpp
	g++ -I ./include/ -o ./lib/kromozom.o -c ./src/kromozom.cpp
	g++ -I ./include/ -o ./lib/Dna.o -c ./src/Dna.cpp
	g++ -I ./include/ -o ./bin/main ./lib/gen.o ./lib/kromozom.o ./lib/Dna.o  ./src/main.cpp

calistirma:
	./bin/main