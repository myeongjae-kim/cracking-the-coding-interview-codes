/* 2_6_Palindrome: Implement a function to check if 
 * a singly linked list is palindrome 

Input
6
a
aa
ab
abcdedcba
abcddcba
notapalindrome

Output
Case #1: true
Case #2: true
Case #3: false
Case #4: true
Case #5: true
Case #6: false

*/

#include <list>
#include <iostream>
#include <cstdint>
#include <stack>

using namespace std;

typedef struct node {
  unsigned char elem;
  struct node* next;
} node_t;

void print_list(node_t *head) {
  if (!head) {
    return;
  }

  head = head->next;

  while (head) {
    cout << head->elem;
    head = head->next;
  }
  cout << endl;
}

// Answer of book
// Fast runner : 1st, 3rd, 5th ...nodes
bool is_palindrome_book(node_t *head) {
  node_t *slow_iter = head->next;
  node_t *fast_iter = head->next;

  stack<unsigned char> front_half;

  while (fast_iter && fast_iter->next) {
    front_half.push(slow_iter->elem);
    slow_iter = slow_iter->next;
    fast_iter = fast_iter->next->next;
  }

  if (fast_iter != nullptr) {
    slow_iter = slow_iter->next;
  }

  while(slow_iter != nullptr && !front_half.empty()) {
    if (front_half.top() != slow_iter->elem) {
      return false;
    }

    front_half.pop();
    slow_iter = slow_iter->next;
  }

  return true;
}



// My answer
// Fast runner : 2nd, 4th, 6th ... nodes
bool is_palindrome(node_t *head) {
  node_t *slow_iter = head->next;
  node_t *fast_iter = head->next;

  if (!slow_iter) {
    // no element
    return false;
  }

  if (!fast_iter->next) {
    // one element
    return true;
  }

  fast_iter = fast_iter->next;

  stack<unsigned char> front_half;

  while(fast_iter) {
    front_half.push(slow_iter->elem);

    fast_iter = fast_iter->next;
    if (!fast_iter) {
      // even element
      break;
    }
    slow_iter = slow_iter->next;
    fast_iter = fast_iter->next;
    if (!fast_iter) {
      // odd element
      break;
    }
  }

  while(front_half.empty() == false) {
    slow_iter = slow_iter->next;

    if (front_half.top() != slow_iter->elem) {
      return false;
    }

    front_half.pop();
  }

  return true;
}

int main(void)
{
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; ++t) {
    string str_buf;
    cin >> str_buf;

    node_t *head = new node_t();
    node_t *iter = head;

    // input
    for (auto i : str_buf) {
      node_t *next_node = new node_t();
      next_node->elem = i;

      iter->next = next_node;
      iter = iter->next;
    }

    cout << "Case #" << t <<": " << (is_palindrome_book(head) ? "true" : "false") << endl;

    // delete node
    iter = head;
    while(iter) {
      node_t *next = iter->next;
      delete iter;
      iter = next;
    }
  }
  
  return 0;
}
