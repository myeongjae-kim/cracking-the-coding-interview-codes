#include <bits/stdc++.h>
#include <climits>

using namespace std;

vector<string> split_string(string);

// Complete the minimumDistances function below.
int minimumDistances(vector<int> a) {
  unordered_map<int, int> m; // m[value] == latest_idx;
  
  int answer = INT_MAX;
  
  for(int i = 0; i < a.size(); i++ ){
    auto it = m.find(a[i]);
    
    if(it == m.end()) {
      m[a[i]] = i;
    } else {
      answer = min(answer, abs(i - it->second));
      it->second = i;
    }
  }

  return answer == INT_MAX ? -1 : answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
