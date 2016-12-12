#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"

int main()
{
	htItem *item[101];
	htInit(item, 101);

	htSet("longmon",100,item);
	htSet("natalie", 1000,item);
	htSet("xiaoqiong",99, item);

	print_hashTable(item);	

	printf("Geting ...\n");

	htItem *tmp = htGet("longmon",item);
	
	printf("Key %s => %d\n", tmp->key_string, tmp->fid);

        htItem *tmp1 = htGet("natalie",item);

        printf("Key %s => %d\n", tmp1->key_string, tmp1->fid);

        htItem *tmp2 = htGet("xiaoqiong",item);

        printf("Key %s => %d\n", tmp2->key_string, tmp2->fid);

	printf("\nDelete natalie ...\n");
	
	htDel("natalie", item);

	printf("deleted \n");

	print_hashTable(item);
	
	htItem *tmp3 = htGet("natalie",item);
	
	printf("tmp3 pointer:%u\n", tmp3);
	if( tmp3->key_string ) {
	        printf("Key %s => %d\n", tmp3->key_string, tmp3->fid);
	}
}
