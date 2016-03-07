#include <iostream>
#include "stacktype.cpp"

using namespace std;

int main() {
	
	stackType<char> stack(3);

	stack.push('(');
    stack.dispTop();
	stack.push(')');
    stack.disp();
	stack.pop();
	stack.ifEmpty();
    stack.pop();
	stack.ifEmpty();
}

