//COSC 222
//Breanne Wiebe
//300219945
/*uses linked lists to multiply very large numbers must be given input in two files
  file1.txt & file2.txt
  which contain numbers in the following format:
  number.
  ex) 12345.
  then it writes the result to file3.txt
*/
#include <fstream> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "LinkedList.cpp"

using namespace std;

LinkedList list;
LinkedList list2;
LinkedList finalres;
LinkedList multLists();
LinkedList addLists(LinkedList& temp1, LinkedList& temp2);

int main() {

	//read data from files

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

	//finished reading data from files

	//call mult list, multiplies list and list2 created from file data
	finalres = multLists();

	//creates a string with the result of multiplying
	string st = finalres.popItemsBack();

	//writes result string to file
	ofstream myfile;
  	myfile.open ("file3.txt");
 	myfile << st;
  	myfile.close();

	return 0;
}

LinkedList multLists() {
	char temp;
	int carry = 0;
	int mult = 0;
	int digit1;
	int digit2;
	char d1;
	char d2;
	int l1count = list.count;
	int l2count = list2.count;
	LinkedList tempList; //copy of first list to pop off valuse
	LinkedList result; //multipied result from each iteration
	LinkedList final; //final linked list to return
	LinkedList finalTemp; // copy of final list when adding result and final together

	for (int x = 0; x < l2count; x++) { //loops through the second list 

		d2 = list2.popTop(); 
		digit2 = d2 - '0';

		tempList = list; 

		for (int i = 0; i < l1count; i++) { //loops through first list and multiplies it 
			d1 = tempList.popTop();        // by each value in the first list.
			digit1 = d1 - '0';

			if(((digit1 * digit2) + carry) >= 10) {  
				mult = (((digit1 * digit2) + carry) % 10); //last number in multiple
				temp = mult + '0';
				result.addItemFront(temp); // add last number to result list
				carry = (((digit1 * digit2) + carry) / 10); //carry over first number in multiple
			}

			else {
				mult = ((digit1 * digit2) + carry); //if not over 10 just add mult value to result list
				temp = mult + '0';
				result.addItemFront(temp);
				carry = 0;
			}

		}

		if (x > 0) { //if this is not the first iteration of the for loop add the previous and current results together
			for (int y = 0; y < x; y++) {
				char x = '0';
				result.addItemBack(x);
			}

			LinkedList final2;//copy to reverse
			LinkedList result2;//copy to reverse

			while (final.count != 0){ //reverse final
				char a = final.popTop();
                final2.addItemFront(a);
            }

            while (result.count != 0){ //reverse result
				char a = result.popTop();
                result2.addItemFront(a);
            }

			finalTemp = addLists(final2, result2); //add reversed lists together

			final.deleteList();
			while (finalTemp.count != 0){ //copy added list to the final result to return
				char y = finalTemp.popTop();
                final.addItemBack(y);
            }
		}
		else { //if this is the first iteration simply copy the result list to the final list
			while (result.count != 0){
				char y = result.popTop();
                final.addItemBack(y);
            }
		}
		//delete list values before next iteration
		tempList.deleteList();
		result.deleteList();
		finalTemp.deleteList();
	}

	return final;
}

LinkedList addLists(LinkedList& test1, LinkedList& test2) {
	int add;	
	int carry = 0;
	char d;
	char d2;
	//temp lists to pop off of
	LinkedList temp1 = test1; 
	LinkedList temp2 = test2;
	LinkedList result;

	//while there are still values in either list add the lists together
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
