// http://www.nayuki.io/page/next-lexicographical-permutation-algorithm
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
  bool is_found = false;
  int sort_starting_idx;
  
  int i;
  for(i = w.length() - 2; i >= 0; i--) {
    if(w[i] < w[i+1]) {
      is_found = true;
      break;
    }
  }
  
  if(is_found == false) {
    return "no answer";
  }
  
  for(int k = w.length() - 1; k > i; k--) {
    if(w[i] < w[k]) {
      swap(w[i], w[k]);
      sort_starting_idx = i + 1;
      break;
    }
  }
  
  reverse(w.begin() + sort_starting_idx, w.end());

  return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
