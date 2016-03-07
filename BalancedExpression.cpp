#include <iostream>
#include <fstream>
#include <string>
#include "stacktype.cpp"

using namespace std;

bool isValid(string s);

int main() {
	string STRING;
	string STRING2;
	ifstream inputfile;
	inputfile.open("expression-input.txt");
	getline(inputfile, STRING);
	getline(inputfile, STRING2);
	isValid(STRING);
	cout << STRING << endl;
	isValid(STRING2);
	cout << STRING2 << endl;

	inputfile.close();
}
	
bool isValid(string s) {
	string str(s);
	stackType<int> stack(5);

	for (int i = 0; i < str.size(); i++) {
        //whenever left bracket is found push to stack
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			stack.push(10);
		}
        //whenever right bracket is found pop from stack
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			stack.pop();
		}
	}
    
    //if the number of left brackets is equal to the number of right brackets stack should be empty
	if (stack.isEmpty()) {
		cout << "The expression is balanced." << endl;
	}
	else {
		cout << "The expression is not balanced" << endl;
	}

}