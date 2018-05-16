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

bool is_palindrome(node_t **front, node_t *back, int32_t *comparison_count) {
  if (!back) {
    // last elem
    return true;
  }

  bool answer = is_palindrome(front, back->next, comparison_count);

  if (answer == false) {
    return false;
  }

  if (*comparison_count > 0) {
    if((*front)->elem == back->elem) {
      (*comparison_count)--;
      *front = (*front)->next;
      return true;
    } else {
      return false;
    }
  }

  return true;
}

bool is_palindrome(node_t *head) {
  int32_t size = 0;
  node_t *iter = head->next;

  while (iter) {
    size++;
    iter = iter->next;
  }

  int32_t half_of_size = size / 2;

  iter = head->next;
  return is_palindrome(&iter, iter, &half_of_size);
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

    cout << "Case #" << t <<": " << (is_palindrome(head) ? "true" : "false") << endl;

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
