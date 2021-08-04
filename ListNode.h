#ifndef LISTNODE_H
#define LISTNODE_H
#include "ItemType.h"

struct ListNode
{
  ItemType item;
  ListNode *next;
  

};

/*class ListNode{
public:
    ItemType item;
    ListNode *next;

    ListNode(ItemType item);
    ListNode(ItemType item, ListNode node);
    ListNode getNext();
    void setNext(ListNode node);
    ItemType getItem();
    ItemType setItem(ItemType item);
private:
    // would i have to make getters and setters for item and next since they are public vars
    };*/

#endif
