#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#define HASH_TABLE_CAPACITY 20

typedef unsigned int uint;

/** hash table element*/
typedef struct _htItem{
	struct _htItem  *next;
	char *key_string;
	uint fid;
	
} htItem;

/** get the index of hash table */
uint htIndex( char *key, htItem **ht );

/** BKDR hash function */
uint bkdrHash( char *key );

/** set hashTable element */
uint htSet( char *key, uint val, htItem **ht );

/** get element from hashtable */
htItem* htGet( char *key, htItem **ht);

/** Delete element from hashTable */
int htDel( char *key, htItem **ht );

/** get hashTable elements */
uint htLen( htItem **ht);

/** init the hashTable */
void htInit( htItem **ht, uint length);
#endif