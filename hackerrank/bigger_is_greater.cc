#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
// hefg -> hegf
string biggerIsGreater(string w) {
  bool is_found = false;
  int sort_starting_idx;
  
  for(int i = w.length() - 2; i >= 0; i--) {
    for(int k = w.length() - 1; k > i; k--) {
      if(w[i] < w[k]) {
        is_found = true;
        swap(w[i], w[k]);
        sort_starting_idx = i + 1;
        break;
      }
    }
    if(is_found) {
      break;
    }
  }
  
  if(is_found == false) {
    return "no answer";
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
