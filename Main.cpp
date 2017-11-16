#include "ItemType.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int, char**);

static bool isValid(char);

int main(int argc, char*argv[]){

	LinkedList list;
	ItemType item;
	int input;
	static fstream fs;

	//Opens the input file
	fs.open(argv[1],fstream::in);

	//Reads through the input file and adds the items to the list
	if(fs.is_open()){
		fs>>input;
		while(!fs.eof()){
			item.initialize(input);
			list.insertItem(item);
			fs>>input;
		}
	}

	else{
		cout << "File could not be opened. Try again." << endl;
		return 0;
	}


	cout << "Commands - insert (i), delete (d), make empty (e), length (l), print (p), get next item (g), quit (q)" << endl;
	char cmd;
	cout << "Enter a command: ";
	cin >> cmd;
	cout << endl;
	//Main command loop
	while( cmd != 'q'){
		//Tests for valid user input
		if(!(isValid(cmd))){
			cout << "Command not recognized. Try again" << endl;
			cout << "Enter a command: ";
			cin >> cmd;
			continue;
		}
		
		//User wants to insert an item
		if(cmd == 'i'){
			cout << "Enter the number to insert: ";
			int num;
			cin >> num;
			ItemType temp;
			temp.initialize(num);
			list.insertItem(temp);
			list.print();
		}
		//User wants to delete an item
		else if(cmd == 'd'){
			cout << "Enter the number to delete: ";
			int num;
			cin >> num; 
			ItemType temp;
			temp.initialize(num);
			list.deleteItem(temp);
			list.print();
		}
		//User wants to make the list empty
		else if(cmd == 'e'){
			list.makeEmpty();
			cout << "List is now empty" << endl;
		}
		//User wants the list's length
		else if(cmd == 'l'){
			cout << "Length: " << list.lengthIs() << endl;
		}
		//User wants to print the list
		else if(cmd == 'p'){
			list.print();
		}
		//User wants to get the next item
		else if(cmd == 'g'){
			ItemType temp;
			list.getNextItem(temp);
			cout << "Next item: " << temp.getValue() << endl;
		}
		//User wants to reset the list
		else if(cmd == 'r'){
			list.resetList();
			cout << "List reset" << endl;
		}

		cout << "Enter a command: ";
		cin >> cmd;
		cout << endl;
	}


	return 0;
}

//Function to validate the user input
static bool isValid(char inp){
	if(!(inp == 'i' || inp == 'd' || inp == 'e' || inp == 'l' || inp == 'p' || inp == 'g' || inp == 'q' || inp == 'r'))
		return false;
	else
		return true;
}