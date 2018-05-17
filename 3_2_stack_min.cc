/* 3_2_stack_min

Input
1
7
2 4 3 9 8 1 6
9
m
t
p
m
t
p
m
t
p

Output
Case #1:
1
6
1
1
2
8

*/

#include <stack>
#include <iostream>
#include <climits>

using namespace std;

class stack_min_t {
private:
  stack<int32_t> main_stack;
  stack<int32_t> min_stack;

public:
  void push(const int32_t input) {
    main_stack.push(input);

    if (min_stack.empty()) {
      min_stack.push(input);
    } else {
      if (input < min_stack.top()) {
        min_stack.push(input);
      }
    }
  }

  int32_t top() {
    return main_stack.top();
  }

  void pop() {
    if (main_stack.empty()) {
      return;
    }

    if (min_stack.top() == main_stack.top()) {
      min_stack.pop();
    }

    main_stack.pop();

    return;
  }

  int32_t min() {
    return min_stack.top();
  }
};

int main(void)
{
  int32_t tc;
  cin >> tc;

  for (int t = 1; t <= tc; ++t) {
    int32_t size;
    cin >> size;

    stack_min_t stack;

    for (int i = 0; i < size; ++i) {
      int int_buf;
      cin >> int_buf;
      stack.push(int_buf);
    }

    int32_t num_commands;
    cin >> num_commands;

    cout << "Case #" << t << ": " << endl;

    for (int i = 0; i < num_commands; ++i) {
      char c_buf;

      do {
        cin >> c_buf;
      } while ( !(c_buf == 'm' || c_buf == 't' || c_buf == 'p') );

      switch (c_buf) {
        case 'm':
          cout << stack.min() << endl;
          break;
      
        case 't':
          cout << stack.top() << endl;
          break;

        case 'p':
          stack.pop();
          break;
      }

    }
    
  }
  
  return 0;
}
