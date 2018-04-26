#include <iostream>
#include <string>

using namespace std;

int lcs(string str1, string str2) {
  if (str1.length() == 0 || str2.length() == 0) {
    return 0;
  }

  if (str1[str1.length()-1] == str2[str2.length()-1]) {
    return 1 + lcs(str1.substr(0, str1.length()-1), 
                    str2.substr(0, str2.length()-1) );
  } else {
    return lcs(str1.substr(0, str1.length()), 
                    str2.substr(0, str2.length()-1) )
            + lcs(str1.substr(0, str1.length()-1), 
                    str2.substr(0, str2.length()) );
  }
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

    int answer = lcs(str1, str2);
    
    cout << "Case #" << n_case << ": "  << answer << endl;
  }

  return 0;
}
