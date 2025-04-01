// Definition of a Node in a doubly linked list
#include <iostream>
using namespace std;

struct Node {
  
    // Data part of the node
    int data;

    // Pointer to the next node in the list
    Node* next;

    Node* prev; 

   // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

int main()
{
     Node* n1 = new Node(1); // n1 stores adr_3923

  // n1 is a pointer, is stores the addres of a newly created node
  /*
  New Node
  __________________
 | adr_3923 |  1   |
 -------------------
  */

 // n1 - address (adr_3923)
 // *n1 - the object at the addres (obj with value 1)

   Node n2(2); // n2 stores the obj with value 2

   //here we just define an object of type Node

   cout << (*n1).data; // output: 1
   cout << n1->data; // output: 1
   cout << n2.data; // output: 2

  

    return 0;
}

/*

pointers in cpp:

pointer -> address in memory 

objects in memory: 
  
 _______________
| adr  |  val   |
----------------


? how do we acces an element in memory 
-> we can do that with their address


POINTERS:

Type* name; //declaration (* indicates that we re declaring pointers, not objects!)

Node1:
 _______________
| adr1 |  val1   |
----------------

Node* next = address in memory of the next node (adr2)
// we only have the address of the next element
--> to get the value, we need to dereference

next == adr2 
(*next) == val2

Node2:
 _______________
| adr2 |  val2   |
----------------

*/