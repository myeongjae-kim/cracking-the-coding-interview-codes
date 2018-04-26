// input
/*
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// return is the size of LCS
int lcs(string str1, int len1, string str2, int len2) {
  int table[len1 + 1][len2 + 1];

  // str1 is row, str2 is col
  // first row and col is just dummy.
  //     s t r 2
  //   0 0 0 0 0
  // s 0 0 0 0 0
  // t 0 0 0 0 0
  // r 0 0 0 0 0
  // 1 0 0 0 0 0

  for(int i = 0; i <= len1; i++) {
    for(int j = 0; j <= len2; j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else if (str1[i-1] == str2[j-1]) { // table's idx is string's idx + 1
        table[i][j] = table[i-1][j-1] + 1;
      } else {
        table[i][j] = table[i-1][j] > table[i][j-1] ?
                        table[i-1][j] : table[i][j-1];
      }
    }
  }

  // printing table
  cout << str1 << endl;
  cout << str2 << endl;
  for (int i = 0; i <= len1; ++i) {
    for (int j = 0; j <= len2; ++j) {
      cout << table[i][j] << ' ';
    }
    cout << endl;
  }

  // printing LCS
  stack<char> lcs;
  int i = len1, j = len2;
  while (i != 0 && j != 0) {
    if (table[i-1][j] > table[i][j-1]) {
      i = i-1;
    } else if (table[i-1][j] < table[i][j-1]) {
      j = j - 1;
    } else {
      if (table[i][j] > table[i-1][j-1]) {
        lcs.push(str1[i-1]);
      }
      i = i-1;
      j = j-1;
    }
  }

  cout << "Found LCS: ";

  while(lcs.empty() == false) {
    cout << lcs.top();
    lcs.pop();
  }
  cout << endl;

  return table[len1][len2];
}


int main(void) {
  int t;
  cin >> t;

  for(int n_case = 1; n_case <= t; n_case++) {  
    int len1, len2;
    cin >> len1 >> len2;

    string str1, str2;

    str1.resize(len1);
    str1.resize(len2);

    cin >> str1 >> str2;

    int answer = lcs(str1, len1, str2, len2);
    
    cout << "Case #" << n_case << ": "  << answer << endl << endl;
  }

  return 0;
}
