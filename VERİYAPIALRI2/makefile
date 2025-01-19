Tum: derleme calistirma

derleme: 
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/BinaryTree.o -c ./src/BinaryTree.cpp
	g++ -I ./include/ -o ./lib/LinkedList.o -c ./src/LinkedList.cpp
	g++ -I ./include/ -o ./lib/TreeNode.o -c ./src/TreeNode.cpp  
	g++ -I ./include/ -o ./bin/main ./lib/Node.o ./lib/BinaryTree.o ./lib/LinkedList.o ./lib/TreeNode.o ./src/main.cpp

calistirma:
	./bin/main

