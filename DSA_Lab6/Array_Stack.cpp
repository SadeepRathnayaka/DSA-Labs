#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class stack {
  private:
    int length;
    int* arr;
    int top;
  public:
    stack(int len) {
    
      length = len;
      top = -1;  
      arr = new int[length];
    }
    void push(int x) {

      if (top == length - 1) {
        cout << "stack Overflow" << "\n";}
        else {
        top += 1;
        arr[top] = x;

      }
    }

    void pop() {

      if (top == -1) {
        cout << "stack underflow" <<"\n";
        }
         else {
          cout << "popped : " << arr[top];}
           top -= 1;
           
      cout << "\n";
    }

    void isEmpty() {
      if (top == -1) {
        cout << "Stack is empty" << "\n";
        } cout << "Stack is not empty" << "\n";

    }

    void isFull() {
        if (top == length -1) {
            cout << "Stack is full" << "\n";
        } cout << "Stacl is not full" << "\n";
    }

    void StackTop() {
         cout << "Stack top : " << arr[top] << "\n" ;
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << "\n";
        }
        cout << "Elements : ";
        for (int i=0; i<top+1; i++) {
            cout << arr[i] << " ";
        }cout << "\n" ;
    }
};

int main() {
  stack arr(5);

  auto start = high_resolution_clock::now();

  arr.push(10);
  arr.push(20);
  arr.push(30);
  arr.push(50);
  arr.display();
  arr.pop();
  arr.isEmpty();
  arr.isFull() ;
  arr.StackTop() ;
  arr.push(7);
  arr.pop();
  arr.StackTop();
  arr.display();

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);
  cout << "Time : " << duration.count() << " nanoseconds" << endl;
  return 0;
}