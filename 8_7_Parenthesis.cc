// Input: the number of pairs of parenthesis

#include <iostream>

using namespace std;

void paren_pairs(int n_lparen, int n_rparen, std::string prefix) {
  if (n_lparen == 0 && n_rparen == 0) {
    cout << prefix << " ";
    return;
  } 

  if (n_rparen > n_lparen) {
    paren_pairs(n_lparen, n_rparen - 1, prefix + ')');
  }

  if (n_lparen > 0) {
    paren_pairs(n_lparen - 1, n_rparen, prefix + '(');
  }
}

int main(void) {
  int n;
  cin >> n;

  paren_pairs(n, n, "");
}
