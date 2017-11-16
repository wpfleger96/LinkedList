#include "LinkedList.h"
#include <cstddef>

using namespace std;

LinkedList::LinkedList(){
	list=NULL;
	currentPos=NULL;
}

LinkedList::~LinkedList(){
	makeEmpty();
}

int LinkedList::lengthIs() const{
	return length;
}

void LinkedList::retrieveItem(ItemType &item, bool &found){
	found=true;
}

void LinkedList::insertItem(ItemType& item){
	NodeType* newNode = new NodeType();
	currentPos->next = newNode;
	newNode -> prev = currentPos;
	currentPos = newNode;
	newNode->info = item;
	newNode->next=NULL;

}

void LinkedList::deleteItem(ItemType &item){
	NodeType* temp=list;
	while(temp->info.compareTo(item)!=RelationType::EQUAL){
		temp=temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
}

void LinkedList::resetList(){
	currentPos=NULL;
}

void LinkedList::getNextItem(ItemType &item){
	item = currentPos->info;
	currentPos = currentPos->next;
}

void LinkedList::makeEmpty(){
	NodeType* temp = list;
	while(temp!=NULL){
		temp=temp->next;
		delete list;
		list = temp;
	}
}

void LinkedList::print(){
	NodeType* temp=list;
	while(temp!=NULL){
		temp->info.print();
		temp=temp->next;
	}
}