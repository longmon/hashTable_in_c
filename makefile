tmpobj = sample.o hashTable.o
cc = gcc

pool	:$(tmpobj)
	cc -o pool $(tmpobj)
sample.o : sample.c
hashTable.o  : hashTable.c hashTable.h

clean  : 
	rm -f pool $(tmpobj)