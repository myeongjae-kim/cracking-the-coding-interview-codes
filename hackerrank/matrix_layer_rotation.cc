#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// level: 0 ~ (n_of_layers - 1)
// rotate one time
void rotate(vector<vector<int>> &m,
            const int level,
            const int times) {
  // direction: right bottom left top
  
  int row = m.size();
  int col = m[0].size();
  
  int min_r = level;
  int min_c = level;
  
  int max_r = (row - 1) - level;
  int max_c = (col - 1) - level;
  
  int r = min_r;
  int c = min_c;
  
  
  for(int i = 0; i < times; i++) {
    int temp = m[r][c];
    // right
    while(c < max_c) {
      m[r][c] = m[r][c + 1];
      c++;
    }

    // bottom
    while(r < max_r) {
      m[r][c] = m[r + 1][c];
      r++;
    }

    // left
    while(min_c < c) {
      m[r][c] = m[r][c - 1];
      c--;
    }

    // top
    while(min_r < r) {
      m[r][c] = m[r-1][c];
      r--;
    }
  
    m[min_r + 1][min_c] = temp;
  }
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int times) {
  const int row = matrix.size();
  const int col = matrix[0].size();
  
  bool is_row_smaller = (row < col);
  
  int n_of_layers = min(matrix.size(), matrix[0].size()) / 2;
  
  vector<int> elems(n_of_layers);
  
  for(int i = 0; i < n_of_layers; i++) {
    elems[i] = ((row - i*2) + (col - i*2) - 2) * 2;
  }
  
  
  // rotate
  
  for(int i = 0; i < n_of_layers; i++) {
    rotate(matrix, i, times % elems[i]);
  }
  
  for(auto & v : matrix) {
    for(auto i : v) {
      cout << i << ' ';
    }
    cout << endl;
  }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split_string(mnr_temp);

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    matrixRotation(matrix, r);

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
