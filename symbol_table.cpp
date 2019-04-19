
#include <string>
#include "symbol_table.h"

const int MAX_SIZE = 211;
const int SHIFT = 4;

static bucket_list* hashTable[MAX_SIZE];

int hash(char* key) {

	int h = 0, i = 0;

	while (key[i] != '\0') {
		h = ((h << SHIFT) + key[i]) % MAX_SIZE;
		i++;
	}

	return h;
}

//void insert(char* name, int lineno, int location) {
void insert(char* name) {

	int h = hash(name);
	bucket_list* bl = hashTable[h];

	while((bl != NULL) && (strcmp(name, bl -> name) != 0))
		bl = bl -> next;

	if(bl == NULL) {
		bl = new bucket_list;
		bl -> name = name;
		bl -> lines = new line_list;
		//bl -> lines -> lineno = lineno;
		//bl -> location = location;
		bl -> lines -> next = NULL;
		bl -> next = hashTable[h];
		hashTable[h] = bl;
	} else {
		line_list* ll = bl -> lines;
		while(ll -> next != NULL)
			ll = ll -> next;
		ll -> next = new line_list;
		//ll -> next -> lineno = lineno;
		ll -> next -> next = NULL;
	}
}

int lookup(char* name) {

	int h = hash(name);
	bucket_list* bl = hashTable[h];

	while ((bl != NULL) && (strcmp(name, bl->name) != 0))
		bl = bl->next;

	if (bl == NULL) return -1;
	else return bl -> location;
}

void remove(char* name) {

	int h = hash(name);
	bucket_list* bl = hashTable[h];

	if(bl == NULL) return;

	if(bl -> next == NULL && !strcmp(bl -> name, name))
		hashTable[h] = NULL;
	else if(!strcmp(bl->name, name))
		hashTable[h] = bl -> next;
	else {
		bl = bl -> next;
		if (bl != NULL) {
			bucket_list* temp = bl -> next;
			bl -> next = temp -> next;
			delete temp;
		}
	}
}