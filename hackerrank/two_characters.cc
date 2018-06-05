#include <bits/stdc++.h>

using namespace std;

bool is_alter(string s) {
  for(int i = 0; i < s.length() - 1; i++) {
    if(s[i] == s[i + 1]) {
      return false;
    }
  }
  
  return true;
}

// Complete the twoCharaters function below.
int twoCharaters(string s) {
  if(s.length() < 2) {
    return 0;
  }
  
  
  unordered_set<char> hash;
  
  for(auto c : s) {
    hash.insert(c);
  }
  
  auto it = hash.begin();
  auto it_next = it;
  it_next++;
  
  int answer = 0;
  
  while(it_next != hash.end()) {
    while(it_next != hash.end()) {
      string temp;
      for(auto c : s) {
        if(c == *it_next || c == *it) {
          temp.push_back(c);
        }
      }
      
      if(is_alter(temp)) {
        answer = max(answer, (int)temp.length());
      }
      it_next++;
    }
    it++;
    it_next = it;
    it_next++;
  }
  
  return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = twoCharaters(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
