#include <iostream>
#include <stdlib.h>

class Stack {
  private:
    static const int max = 100;
    int arr[max];
    int top;
  public:
    Stack () { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop();
    void push( int x ); 
};

bool Stack::isEmpty() {
  if (top == -1)
    return true;
  return false;
}

bool Stack::isFull() {
  if (top == max-1)
    return true;
  return false;
}

int Stack::pop() {
  if (!isEmpty()) {
    int x = arr[top];
    top--;
    return x;
  } else {
    abort();
  }
}

void Stack::push (int x) {
  if (!isFull()) {
    top++;
    arr[top] = x;
  }
  else {
    abort();
  }
}

class SpecialStack : Stack {
  Stack min;
  public:
    void push( int x );
    int pop();
    int getMin();
};

void SpecialStack::push (int x) {
  if (isEmpty()) {
    Stack::push(x);
    min.push(x);
  }
  else {
    Stack::push(x);
    int y = min.pop();
    min.push(y);
    if (x < y)
      min.push(x);
    else
      min.push(y);
  }
}

int SpecialStack::pop() {
  int x = Stack::pop();
  min.pop();
  return x;
}

int SpecialStack::getMin() {
  int x = min.pop();
  min.push(x);
  return x;
}

int main() {
  SpecialStack s;
  s.push(10);
  s.push(14);
  s.push(5);

  std::cout << s.getMin() << "\n";
  s.pop();
  std::cout << s.getMin() << "\n";
}