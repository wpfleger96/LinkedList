#include "ItemType.h"
#include <iostream>
#include <cstddef>

using namespace std;

ItemType::ItemType(){

}


RelationType ItemType::compareTo(ItemType &item){
	if(item.getValue() < this->getValue())
		return GREATER;
	else if(item.getValue() < this->getValue())
		return LESS;
	else
		return EQUAL;
}

void ItemType::print(){
	cout << this->value << endl;
}

void ItemType::initialize(int number){
	this->value=number;
}

int ItemType::getValue() const{
	return this->value;	
}
