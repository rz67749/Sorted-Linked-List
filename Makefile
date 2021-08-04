GPP = g++
CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors

main: main.cpp SortedLinkedList.o ItemType.o
	$(GPP) $(CFLAGS) -o main main.cpp SortedLinkedList.o ItemType.o

ItemType.o: ItemType.cpp ItemType.h
	$(GPP) $(CFLAGS) -c ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h ListNode.h ItemType.h
	$(GPP) $(CFLAGS) -c SortedLinkedList.cpp

clean:
	rm -rf main
	rm -rf *.o
