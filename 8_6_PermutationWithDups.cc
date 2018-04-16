#include <iostream>
#include <unordered_map>

using namespace std;

void permutation(const string& chars,
                  unordered_map<char, int> char_count,
                  int size,
                  std::string prefix) {
  if(size == 0) {
    cout << prefix << endl;
  }

  for (auto i : chars) {
    if (char_count[i] > 0) {
      char_count[i]--;
      size--;
      prefix.push_back(i);

      permutation(chars, char_count, size, prefix);

      prefix.pop_back();
      size++;
      char_count[i]++;
    }
  }

}

int main(void) {
  string input;
  cin >> input;
  
  unordered_map<char, int> char_count;
  string chars;
  for (auto i : input) {
    if(char_count.find(i) == char_count.end()) {
      char_count[i] = 1;
      chars.push_back(i);
    } else {
      char_count[i]++;
    }
  }

  permutation(chars, char_count, input.length(), "");

  return 0;
}
