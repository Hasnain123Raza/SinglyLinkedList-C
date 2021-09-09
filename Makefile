all: driver build


driver:
	mkdir bin
	gcc src/driver.c src/SinglyLinkedList.c -Iincludes -o bin/driver

build:
	mkdir build
	gcc -c src/SinglyLinkedList.c -Iincludes -o build/SinglyLinkedList.o
	ar rcs build/libSinglyLinkedList.a build/SinglyLinkedList.o
	rm build/SinglyLinkedList.o
	gcc -fPIC -c src/SinglyLinkedList.c -Iincludes -o build/SinglyLinkedList.o
	gcc -shared build/SinglyLinkedList.o -o build/libSinglyLinkedList.so
	rm build/SinglyLinkedList.o

clean:
	rm -r build bin
