#include "ItemType.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct NodeType{
	ItemType info;
	NodeType *prev;
	NodeType *next;
};

class LinkedList{
	public:
		LinkedList();
		~LinkedList();
		int lengthIs() const;
		void retrieveItem(ItemType &item, bool &found);
		void insertItem(ItemType &item);
		void deleteItem(ItemType &item);
		void resetList();
		void getNextItem(ItemType &item);
		void makeEmpty();
		void print();

	private:
		NodeType* list;
		int length;
		NodeType* currentPos;
		
};
#endif