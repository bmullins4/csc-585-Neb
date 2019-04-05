
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

void insert(char* name, int lineno, int location);
int lookup(char* name);
void remove(char* name);

#endif
