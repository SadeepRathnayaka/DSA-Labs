#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {

  int data;
  Node* next;};

struct stack {
  Node* head;
  Node* top;

  stack() {
    head = NULL;
    top = NULL;
  }

   void push(int x) {
    Node* newNode = new Node();
   newNode->data = x;
    if (isEmpty()) {
    head = newNode;
    top = newNode;
    }
     else {
      top->next = newNode;
      top = newNode;
    }
  }

  void pop() {
    if (isEmpty() == 1) {
      cout << "Stack underflow" << "\n";
      }
       else {
      int x = top->data;
      if (top == head) 
      {
        head = NULL;
        top = NULL;
      } else {
        Node* temp = head;
        while (temp->next != top) {
          temp = temp->next;
        }
        cout << "popped :" << x << "\n";
        temp->next = NULL;
        top = temp;
      }}
  }

  void isFull() {
    Node* temp = new Node();
  if(temp == NULL) {
    cout << "Stack is full" << "\n";
  }
  delete temp;
  cout << "Stack is not full " << "\n";
}

  void display() {
    if (isEmpty()) {
    cout << "Stack is Empty" << "\n";
      } else {
     cout << "Elements : " ;
      Node* temp = head;
      while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
      }
      cout << "\n";
    }
  }

  bool isEmpty() {
    if (head == NULL && top == NULL) { return true;}
    return false ;
    
  }
};

int main() {
 stack arr;

  auto start = high_resolution_clock::now();

  arr.push(10);
  arr.push(20);
  arr.push(30);
  arr.push(50);
  arr.display();
  arr.pop();
  arr.isEmpty();
  arr.isFull() ;
  arr.push(7);
  arr.pop();
  arr.display();

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Time : " << duration.count() << " milliseconds" << endl;
  return 0;
}
