#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void rotate_2(vector<int> &A, int start_idx) {
  int temp = A[start_idx + 2];
  A[start_idx + 2] = A[start_idx + 1];
  A[start_idx + 1] = A[start_idx];
  A[start_idx] = temp;
}

void rotate_1(vector<int> &A, int start_idx) {
  int temp = A[start_idx];
  A[start_idx] = A[start_idx + 1];
  A[start_idx + 1] = A[start_idx + 2];
  A[start_idx + 2] = temp;
}


// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
  for(int i = 0; i < A.size() - 2; i++) {
    // get idx of smallest
    // if smallest idx is i + 1, rotate_1()
    // if smallest idx is i + 2, rotate_2()
    
    int idx = A[i] < A[i+1] ? i : i + 1;
    idx = A[idx] < A[i + 2] ? idx : i + 2;
    
    if(idx == i + 1) {
      rotate_1(A, i);
      i = -1; // go back to front
    } else if (idx == i + 2){
      rotate_2(A, i);
      i = -1; // go back to front
    } else {
      //do nothing
    }
  }
  
  for(int i = 0; i < A.size() - 1; i++) {
    if(A[i] > A[i+1]) {
      return "NO";
    }
  }
  return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

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
