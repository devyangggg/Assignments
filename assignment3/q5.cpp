#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
  int arr[MAX];
  int top;

public:
  Stack() { top = -1; }
  void push(int x) { arr[++top] = x; }
  int pop() { return arr[top--]; }
};

int main() {
  char postfix[MAX];
  cout << "Enter postfix: ";
  cin >> postfix;

  Stack s;
  for (int i = 0; i < strlen(postfix); i++) {
    char c = postfix[i];
    if (isdigit(c))
      s.push(c - '0');
    else {
      int b = s.pop();
      int a = s.pop();
      switch (c) {
      case '+':
        s.push(a + b);
        break;
      case '-':
        s.push(a - b);
        break;
      case '*':
        s.push(a * b);
        break;
      case '/':
        s.push(a / b);
        break;
      }
    }
  }
  cout << "Result: " << s.pop() << "\n";
}
