flags = -g -Wall -std=gnu99

a.out: main.o Node.o NodeQueue.o NodeQueueOperation.o AhoCorasick.o RawOperation.o
	gcc -o a.out main.o Node.o NodeQueue.o NodeQueueOperation.o AhoCorasick.o RawOperation.o
main.o: main.c Node.h AhoCorasick.h RawOperation.h MatchingResult.h
	gcc $(flags) -c main.c
Node.o: Node.c Node.h
	gcc $(flags) -c Node.c
NodeQueue.o: NodeQueue.c NodeQueue.h
	gcc $(flags) -c NodeQueue.c
NodeQueueOperation.o: NodeQueueOperation.c NodeQueueOperation.h
	gcc $(flags) -c NodeQueueOperation.c
AhoCorasick.o: AhoCorasick.c AhoCorasick.h
	gcc $(flags) -c AhoCorasick.c
RawOperation.o: RawOperation.c RawOperation.h
	gcc $(flags) -c RawOperation.c