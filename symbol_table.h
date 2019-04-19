
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

struct line_list {
	int lineno;
	line_list* next;
};

struct bucket_list {
	char* name;
	line_list* lines;
	int location;
	bucket_list* next;
};

void insert(char* name); //test
void insert(char* name, int lineno, int location);
int lookup(char* name);
void remove(char* name);

#endif
