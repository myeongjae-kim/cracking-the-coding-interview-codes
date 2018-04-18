// Input: A one string.

#include <iostream>
#include <set>

using namespace std;

void permutation(std::string remainder, int size,
                  std::string prefix) {
  if(size == 0) {
    cout << prefix << endl;
  }

  for (int i = 0; i < size; ++i) {
    prefix.push_back(remainder[i]);
    permutation(remainder.substr(0, i) + remainder.substr(i+1),
                 size - 1, prefix);
    prefix.pop_back();
  }
}

int main(void) {
  string input;
  cin >> input;
  
  permutation(input, input.length(), "");

  return 0;
}
