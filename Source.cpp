
#include <iostream>
#include "parser.h"

using namespace std;

//extern int yyparse(); //syntax parser
extern int yylex();

void readFiles(char *filename) {

	cout << flush;
	system("CLS");

	extern FILE *yyin;
	yyin = fopen(filename, "r");

	if(!yyin)
		cout << "Cannot open file: " << filename << endl;
	else
		while (yylex());

	fclose(yyin);
}

void start() {

	int length = 10, input;
	char *files[] = {
		"t1.txt", "t2.txt", "t3.txt", "t4.txt", "t5.txt",
		"t6.txt", "t7.txt", "t8.txt", "t9.txt", "t10.txt"
	};

	while (true) {
		cout << flush;
		system("CLS");
		int j = 1;
		for (int i = 0; i < length; i++)
			cout << "[" << j++ << "] " << files[i] << endl;
		cout << "Enter file to test or -1 to exit: ";
		cin >> input;
		if (input == -1) break;
		readFiles(files[--input]); //decrement before accessing to prevent out of bounds error
		cout << "\n1 to test another file or 0 exit: ";
		cin >> input;
		if (input == 0) break;
	}
}

int main() {

	//yyparse();
	start();
	return 0;
}

void yyerror(const char* msg) {

	cout << "Error: " << msg << endl;
}