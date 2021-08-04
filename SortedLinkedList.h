#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"
#include "ItemType.h"

class SortedLinkedList{
public:
    SortedLinkedList();
    ~SortedLinkedList();
    int getLength() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType &item);
    ItemType GetNextItem();
    void ResetList();
    //void reverse(); (extra credit)
private:
    int length;
    ListNode *head;
    ListNode *currentPos;
};
#endif
