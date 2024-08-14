// Preciosa Moreno
// 201288508
// moren398@csusm.edu
// CS311- Assignment 1- 02/07/23

#include <iostream>
using namespace std;

// define the Node structure
struct Node {
  int num;
  Node *next;
};

// helper function to insert the nodes into the list
void insertNode(Node **front, int elem) {
  Node *tmp = new Node;
  tmp->num = elem;
  tmp->next = *front;
  *front = tmp;
}

// create linked list from an input array of integers.
// RETURN: head pointer of the created linked list.
// len = size of input array
Node *createLinkedList(int a[], int len) {
  Node *front = NULL;
  for (int i = len - 1; i >= 0; i--)
    insertNode(&front, a[i]);
  return front;
}

// merge an array of linked lists into one linked list.
// RETURN: the head pointer of merged linked list. DUPLICATES ARE ALLOWED.
// len = size of input array
Node *mergeLinkedLists(Node **LL, int len) {
  //use 2 for loops to iterate thru the values and 
  //then add them to the same merged list one by one
  //define some pointers
  Node *ptr1 = *LL;
  Node **newList;
  //loop to make sure 1st pointer is not null
  while(ptr1->next != NULL){
  for(int i = 0; i < len+1; i++){
    *(newList + i) = NULL;
    newList[i] = new Node;
    //insertNode(newList[i], &ptr1);
  }
    ptr1 = ptr1->next;
  }
  ptr1->next = *newList;
  return ptr1;
}

// REMOVE: duplicates from an input linked list ('L')
// RETURN: head pointer of the updated linked list
Node *removeDuplicate(Node *L) {

  Node *currFront = L;
  Node *nxtPtr = NULL;
  // loop through the list
  while (currFront != NULL) {
    nxtPtr = currFront->next;
    // make sure next node is not null
    while (nxtPtr != NULL) {
      // check for duplicate values
      if (currFront->num == nxtPtr->num) {
        // delete duplicate nodes
        currFront->next = nxtPtr->next;
        // free(nxtPtr);
        delete (nxtPtr);
        nxtPtr = currFront->next;
        //move on if no duplicates
      } else {
        nxtPtr = nxtPtr->next;
      }
      return nxtPtr;
    }
    currFront = currFront->next;
  }
  return nxtPtr;
}

// reverse a linked list without creating a new node
// RETURN: head pointer of reversed linked list
Node *reverseLinkedList(Node *L) {
  //initialize pointers for front, current, & previous nodes
  Node *Lfront = L;
  Node *curr = NULL;
  Node *prev = NULL;
  //loop thru list while not null
  while (Lfront != NULL) {
    prev = curr;
    curr = Lfront;
    Lfront = Lfront->next;
    curr->next = prev;
  }
  //set current node to front & return current one
  Lfront = curr;
  return curr;
}

// function for displaying the list
void displayList(Node *node1) {
  Node *tmp = node1;
  while (tmp != NULL) {
    cout << tmp->num << "->";
    tmp = tmp->next;
  }
  cout << endl;
}

int main() {
  // linked list from an input array
  int a[] = {1, 2, 3, 4, 5, 6};
  int len = sizeof(a) / sizeof(a[0]);
  Node *front = createLinkedList(a, len);
  cout << "Array into linked list:" << endl;
  displayList(front);

  // create the lists for merge 2 LL arrays
  Node *L1 = NULL;
  insertNode(&L1, 6);
  insertNode(&L1, 3);
  insertNode(&L1, 7);
  cout << "First LL Array (L1):" << endl;
  displayList(L1);
  Node *L2 = NULL;
  insertNode(&L2, 6);
  insertNode(&L2, 4);
  insertNode(&L2, 2);
  cout << "Second LL Array (L2):" << endl;
  displayList(L2);
  //call the merge functions
  Node *LL[2] = {L1, L2};
  //Node * mergedLL = mergeLinkedLists(LL,2);
  // output for merging 2 arrays of linked lists
  cout << "Merged Array:" << endl;
  //displayList(mergedLL);

  // remove duplicates from a linked list
  Node *L3 = NULL;
  insertNode(&L3, 5);
  insertNode(&L3, 7);
  insertNode(&L3, 8);
  insertNode(&L3, 8);
  insertNode(&L3, 8);
  cout << "List before removing duplicates:" << endl;
  displayList(L3);
  cout << "Remove Duplicates:" << endl;
  Node *dupList = removeDuplicate(L3);
  displayList(dupList);

  // reversing a linked list
  Node *L = NULL;
  insertNode(&L, 9);
  insertNode(&L, 13);
  insertNode(&L, 7);
  insertNode(&L, 11);
  cout << "List before reversal:" << endl;
  displayList(L);
  cout << "Reversed Linked List:" << endl;
  Node *revList = reverseLinkedList(L);
  displayList(revList);
}