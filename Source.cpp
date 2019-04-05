
#include <iostream>
#include "parser.h"

using namespace std;

extern int yyparse(); //syntax parser
//extern int yylex();

void readFiles(char *filename) {

	cout << flush;
	system("CLS");

	extern FILE *yyin;
	yyin = fopen(filename, "r");

	if (!yyin)
		cout << "Cannot open file: " << filename << endl;
	else
		//while (yylex());
		while(yyparse()); //once actions are implemented, yyparse will not be in while loop

	fclose(yyin);
}

void start() {

	int lex_length = 10, parse_length = 13, input;

	char *lex_testing_files[] = {
		"lt1.txt", "lt2.txt", "lt3.txt", "lt4.txt", "lt5.txt",
		"lt6.txt", "lt7.txt", "lt8.txt", "lt9.txt", "lt10.txt"
	};
	char *parse_testing_files[] = {
		"pt1.txt", "pt2.txt", "pt3.txt", "pt4.txt", "pt5.txt",
		"pt6.txt", "pt7.txt", "pt8.txt", "pt9.txt", "pt10.txt",
		"pt11.txt", "pt12.txt", "pt13.txt"
	};

	while (true) {
		cout << flush;
		system("CLS");
		int j = 1;
		for (int i = 0; i < parse_length; i++)
			//cout << "[" << j++ << "] " << lex_testing_files[i] << endl;
			cout << "[" << j++ << "] " << parse_testing_files[i] << endl;
		cout << "Enter file to test or -1 to exit: ";
		cin >> input;
		if (input == -1) break;
		//readFiles(lex_testing_files[--input]); //decrement before accessing to prevent out of bounds error
		readFiles(parse_testing_files[--input]);
		cout << "\n1 to test another file or 0 exit: ";
		cin >> input;
		if (input == 0) break;
	}
}

int main() {

	yyparse();
	//start();
	return 0;
}

void yyerror(const char* msg) {

	cout << "Error: " << msg << endl;
}