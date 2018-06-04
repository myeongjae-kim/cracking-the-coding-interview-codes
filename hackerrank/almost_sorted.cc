#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool is_sorted(vector<int> &A) {
  for(int i = 0; i  < A.size() - 1; i++) {
    if(A[i] > A[i + 1]) {
      return false;
    }
  }
  return true;
}

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
  if(is_sorted(arr)) {
    cout << "yes" << endl;
    return;
  }
  
  vector<int> sorted_arr = arr;
  
  sort(sorted_arr.begin(), sorted_arr.end());
  
  int idx_start;
  int idx_end;
  
  for(int i = 0; i < sorted_arr.size(); i++) {
    if(sorted_arr[i] != arr[i]) {
      idx_start = i;
      break;
    }
  }
  
  for(int i = sorted_arr.size() - 1; i >= 0; i--) {
    if(sorted_arr[i] != arr[i]) {
      idx_end = i;
      break;
    }
  }
  
  swap(arr[idx_start], arr[idx_end]);
  if(is_sorted(arr)) {
    cout << "yes" << endl;
    cout << "swap " << idx_start + 1 << ' ' << idx_end  + 1 << endl;
    return;
  }
  
  swap(arr[idx_start], arr[idx_end]);
  reverse(arr.begin() + idx_start, arr.begin() + idx_end + 1);
  if(is_sorted(arr)) {
    cout << "yes" << endl;
    cout << "reverse " << idx_start + 1<< ' ' << idx_end + 1 << endl;
    return;
  }
  
  
  cout << "no" << endl;
  return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
