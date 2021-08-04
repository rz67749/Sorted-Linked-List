#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

// constructor
SortedLinkedList::SortedLinkedList(){
    length = 0;
    head = NULL;
}

// destructor
SortedLinkedList::~SortedLinkedList()
{
    ListNode *tempNode = head;
    ListNode *nextNode;
    while(tempNode != NULL){
        nextNode = tempNode->next;
        delete tempNode;
        tempNode = nextNode;
    }
    length = 0;
}//~SortedLinkedList

// returns length of list
int SortedLinkedList::getLength() const{
    return length;
}

// inserts an item to the list
void SortedLinkedList::insertItem(ItemType item){
    ListNode *location;
    ListNode *newNode;
    ListNode *prevNode;
    bool moreToSearch;
    bool isDuplicate = false;
  
    location = head; // start from the beginning of list
    prevNode = NULL;
    moreToSearch = (location != NULL); // make sure there's more
    // find place of insertion
    while (moreToSearch){
        switch(item.compareTo(location->item)){
        case LESS:
            moreToSearch = false;
            break;
            
        case GREATER:
            prevNode = location;
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        
        case EQUAL:
            cout << "Item already present" << endl;
            isDuplicate = true;
            moreToSearch = false; 
            break;
         }
     }//while
    
    if (!isDuplicate){
    newNode = new ListNode();
    newNode->item = item;
    // insert
    if(head == NULL) //if no items in the list
    {      
      head = newNode; 
      newNode->next = NULL;
    }//if
    else if(prevNode == NULL){ // in case item goes before first item in list
        newNode->next = head;
        head = newNode;
    }
    else if(location != head){ //middle of the list
        newNode->next = location;
        prevNode->next = newNode;
    }//else if
    else {     //end of list
      prevNode->next = newNode;
      newNode->next = NULL;
    }
    length++;
    }
}

// deletes item of the list
void SortedLinkedList::deleteItem(ItemType item){
    ListNode *location = head;
    ListNode *tempLocation;
    ListNode *prevNode;
    bool itemFound = false;
    bool moreToSearch = (location != NULL);
    
    //Checks first item
    if(moreToSearch && item.compareTo(location->item) == EQUAL){
        tempLocation = location;
        head = head->next;
        itemFound = true;
    } else { // finds item to delete
        while (moreToSearch && !itemFound){
            if (item.compareTo(location->item) == EQUAL){
                itemFound = true;
                tempLocation = location;
                prevNode->next = location->next;
            } else {
                prevNode = location;
                location = location->next;
                moreToSearch = (location != NULL);
            } //if-else
      } // while
    } // if-else
    
    // delete item if found
    if (itemFound){
        delete tempLocation;
        length--;
    } else {
        cout << "Item not found" << endl;
    }
}//deleteItem

/*
 * Returns location of the item being searched
 * Returns -1 if not found;
 */
int SortedLinkedList::searchItem(ItemType &item)
{
    int itemCount = 0;
    bool itemFound = false;
    ListNode *location = head;
    bool moreToSearch = (location != NULL);

    while (moreToSearch && !itemFound){
        if (item.compareTo(location->item) == EQUAL){
            itemFound = true;          
        } else {
            itemCount++;
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
    
    if (itemFound){
        return itemCount;
    } else {
        cout << "Item not found" << endl;
        return -1;
    }
}//searchItem

// gets next item in iterator
ItemType SortedLinkedList::GetNextItem(){
    if(currentPos == NULL){
        currentPos = head;
    }//if
    ItemType helpItem = currentPos->item;
    currentPos = currentPos->next;
    return helpItem;
}

// resets iterator
void SortedLinkedList::ResetList(){
  currentPos = NULL;
}

//void SortedLinkedList::reverse(){
    
//}
     
 
