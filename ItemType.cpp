#include "ItemType.h"
 
using namespace std;

// constructor
ItemType::ItemType()
{

}

// compares items 
Comparison ItemType::compareTo(ItemType item){
    if (value < item.value){
        return LESS;
    } else if (value > item.value){
        return GREATER;
    } else {
        return EQUAL;
    }   
}

// returns value of the item
int ItemType::getValue() const{
    return value;
}

// initializes an item
void ItemType::initialize(int num){
    value = num;
}
