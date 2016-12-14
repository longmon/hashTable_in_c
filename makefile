tmpobj = sample.o hashTable.o
cc = gcc

pool	:$(tmpobj)
	cc -o sample $(tmpobj)
sample.o : sample.c
hashTable.o  : hashTable.c hashTable.h

clean  : 
	rm -f sample $(tmpobj)
