#include "hashTable.h"

/** BKDR hash function */
uint bkdrHash( char *key )
{
        uint seed = 131;
        uint hash = 0;
        while( *key != '\n' && *key != 0 )
        {
                hash = hash * seed + ( *key++ );
        }
        return ( hash & 0x7FFFFFFF );
}

/** get the index of hash table */
uint htIndex( char *key, htItem **ht ){
        uint hashedKey = bkdrHash( key );
	uint length = (ht[0]->fid-1);
        return (uint)hashedKey % length+1;
}

/** get hashTable elements */
htItem* htGet( char *key, htItem **ht ){
        uint i = htIndex( key, ht);
        htItem *item = ht[i]->next;
	htItem *tmp = (htItem*)malloc(sizeof(htItem));
	memset(tmp, 0, sizeof(htItem));
        while( item )
        {
                if( strcmp(key, item->key_string) == 0 ){
			tmp->fid = item->fid;
			tmp->key_string = item->key_string;
                        return tmp;
                }
		item = item->next;
        }
        return;
}
/** set hashTable element */
uint htSet( char *key, uint fid,  htItem **ht ){
	uint i = htIndex( key, ht );
	htItem *item = ht[i];
	while( item->next )
	{
		if( strcmp(key, item->next->key_string) == 0 ){
			item->next->fid = fid;
			return 0;
		}else{
			item = item->next;
		}
	}
	item->next = (htItem*)malloc(sizeof(htItem));
	item->next->fid = fid;
	item->next->key_string = key;
	return 0;
}

void htInit( htItem **ht, uint length ){
	int i;
	for( i=0; i<length; i++ ){
		ht[i] = (htItem*)malloc(sizeof(htItem));
		memset( ht[i], 0, sizeof(htItem) );
	}
	ht[0]->fid = length;
}

int htDel(char *key, htItem **ht){
	uint i = htIndex(key, ht);
	htItem *item = ht[i];
	while(item->next){
		if(strcmp(key, item->next->key_string) == 0 ){
			htItem *tmp = item->next;
			item->next = tmp->next;
			free(tmp);	
			return 0;
		}
		item = item->next;
	}	
	return -1;
}

uint htLen(htItem **ht){
	return 0;
}