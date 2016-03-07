//COSC 222
//Breanne Wiebe
//300219945

#include <fstream> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "linkedList.cpp"

using namespace std;

LinkedList list;
LinkedList list2;
LinkedList list3;
LinkedList addLists(LinkedList& temp1, LinkedList& temp2);

int main() {

	//reads data from files and writes them to list and list2
    //file must contain numbers in following format number. ex) 12356.
	ifstream infile; 
	infile.open("file1.txt"); 

	ifstream infile2; 
	infile2.open("file2.txt"); 

	char data;
	char data2;

   	while( data != '.' ) {
   		infile >> data; 
   		if (data == '.') break;
   		
   		list.addItemFront(data);
	}

   	while( data2 != '.' ) {
   		infile2 >> data2; 
   		if (data2 == '.') break;
   		
		list2.addItemFront(data2);
		
	}

	infile.close();
	infile2.close();

	//calls addLists, adds list and list2 created from file data
	list3 = addLists(list, list2);

	//creates string from result of add
	string st = list3.popItemsBack();

	//writes result to file
	ofstream myfile;
  	myfile.open ("file3.txt");
 	myfile << st;
  	myfile.close();

  	list3.deleteList();

	return 0;

}

LinkedList addLists(LinkedList& temp1, LinkedList& temp2) {
	int add;	
	int carry = 0;
	char d;
	char d2;
	LinkedList result;

	while (temp1.count > 0 || temp2.count > 0) {
		d = temp1.popTop();
		d2 = temp2.popTop();
		char added; 
		int id = d - '0';
		int id2 = d2 - '0';
		
		add = id + id2 + carry;

		if (temp1.count == 0 && temp2.count == 0 && add >= 10) {
			add = add - 10;
			added = add + '0';
			int second = 1;
			char secondc = second + '0';
			result.addItemFront(added);
			result.addItemFront(secondc);
			return result;
		}
		
		else if (add < 10 && carry > 0) {
			add = id + id2 + carry;
			carry--;
		}

		else if (add >= 10) {
			carry = 1; 
			add = add - 10;
		}

		added = add + '0';
		result.addItemFront(added);

	}
	return result;
}