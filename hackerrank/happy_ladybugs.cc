#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
  unordered_multiset<char> s;
  
  bool has_empty = false;
  
  if(b.length() == 1) {
    if(b[0] == '_') {
      return "YES";
    } else {
      return "NO";
    }
  }
  
  for(char c : b) {
    if(c == '_') {
      has_empty = true;
    } else {
      s.insert(c);
    }
  }
  
  if(has_empty == false) {
    //assert(has_empty);
    char before = b[0];
    int count = 0;
    
    for(char now : b) {
      if(before == now) {
        count++;
      } else {
        if(count < 2) {
          return "NO";
        }
        
        before = now;
        count = 1;
      }
    }
    
    if(b[b.length() - 1] != b[b.length() - 2]) {
      return "NO";
    }
    
    
    return "YES";
    
  } else {
    for(char c : s) {
      if(s.count(c) < 2) {
        return "NO";
      }
    }
  }

  return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
