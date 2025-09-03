#include <cstring>
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
  char arr[MAX];
  int top;

public:
  Stack() { top = -1; }
  void push(char c) { arr[++top] = c; }
  char pop() { return arr[top--]; }
  bool isEmpty() { return top == -1; }
  char peek() { return arr[top]; }
};

bool isMatching(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']') ||
         (a == '{' && b == '}');
}

int main() {
  char expr[MAX];
  cout << "Enter expression: ";
  cin >> expr;

  Stack s;
  for (int i = 0; i < strlen(expr); i++) {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
      s.push(expr[i]);
    else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
      if (s.isEmpty() || !isMatching(s.pop(), expr[i])) {
        cout << "Not Balanced\n";
        return 0;
      }
    }
  }
  cout << (s.isEmpty() ? "Balanced\n" : "Not Balanced\n");
}
