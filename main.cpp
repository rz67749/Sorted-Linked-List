#include <fstream>
#include <iostream>
#include "ListNode.h"
#include "SortedLinkedList.h"
#include "ItemType.h"
using namespace std;

int main(int argc, char** argv)
{
    // read input file
  SortedLinkedList list;
  ItemType item;
  int input;
  fstream fs;
  fs.open(argv[1], fstream::in);
  if(fs.is_open())
  {
    fs >> input;
    while(!fs.eof())
    {
      
      item.initialize(input);
      
      list.insertItem(item);
      
      fs >> input;
    }//while
  }//if
  else {
    cout << "Failed to open the input file" << endl;
    return 0;
  }//else
  

  cout << "Commands: " << endl;
  cout << "(i) - Insert value" << endl;
  cout << "(d) - Delete value" << endl;
  cout << "(s) - Search value" << endl;
  cout << "(n) - Print next iterator value" << endl;
  cout << "(r) - Reset iterator" << endl;
  cout << "(p) - Print list" << endl;
  cout << "(l) - Print length" << endl;
  cout << "(b) - Reverse" << endl;
  cout << "(q) - Quit program" << endl;

  // commands
  char userInput = ' ';
  while(input != 'q')
  {
   
    cout << "Enter a command: ";
    cin >> userInput;
    ItemType newItem;
    
    switch(userInput) {
        // insert
    case 'i':
      
      int lengthOfList;
      lengthOfList= list.getLength();
      list.ResetList();
      for(int i = 0; i < lengthOfList; i++) {
        ItemType tempItem = list.GetNextItem();
        cout << tempItem.getValue() << " ";
      }//for
      cout << endl;
      cout << "Enter a number: ";
      int enteredNum;
      cin >> enteredNum;
      
      newItem.initialize(enteredNum);
      list.insertItem(newItem);
      
      lengthOfList = list.getLength();
      list.ResetList();
      for(int i = 0; i < lengthOfList; i++) {
        ItemType tempItem = list.GetNextItem();
        cout << tempItem.getValue() << " ";
      }//for
      cout << endl;

      break;

      // delete
    case 'd':
      int wholeListLength;
      wholeListLength= list.getLength();
      list.ResetList();
      for(int i = 0; i < wholeListLength; i++) {
        ItemType tempItem = list.GetNextItem();
        cout << tempItem.getValue() << " ";
      }//for
      cout << endl;

      cout << "Enter value to delete: ";
      int userInputVal;
      cin >> userInputVal;
      newItem.initialize(userInputVal);
      list.deleteItem(newItem);

      
      wholeListLength = list.getLength();
      list.ResetList();
      for(int i = 0; i < wholeListLength; i++) {
        ItemType tempItem = list.GetNextItem();
        cout << tempItem.getValue() << " ";
      }//for
      cout << endl;
      break;

      // search
    case 's':
        cout << "Enter a value to search: ";
        int searchValue;
        cin >> searchValue;
        newItem.initialize(searchValue);
        if (list.searchItem(newItem) != -1){
            cout << "Index " << list.searchItem(newItem) << endl;
        }
        break; 

        // iterator
    case 'n':
        if (list.getLength() > 0){
            cout << list.GetNextItem().getValue() << endl;
        } else {
            cout << "List is empty" << endl;
        }
      break;

      // reset
    case 'r':
      list.ResetList();
      cout << "Iterator reset." << endl;
      break;

      // print
    case 'p':
      int listLength;
      listLength= list.getLength();
      list.ResetList();
      for(int i = 0; i < listLength; i++) {
	ItemType tempItem = list.GetNextItem();
	cout << tempItem.getValue() << " ";
      }//for
      cout << endl;
      break;

      // length
    case 'l':
      cout << "List Length is " << list.getLength() << endl;
      break;

      // bonus
    case 'b':
        ////////// bonus stuff
      break;

      // quit
    case 'q':
      cout << "Quitting program..." << endl;
      return 0;
      
    default:
      cout << "Invalid Input" << endl;
      break;
      
    }//switch
  }//while
  

  

  return 0;
}//main
