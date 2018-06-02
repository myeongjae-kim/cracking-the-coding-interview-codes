#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, const vector<string> grid) {
  // initial state
  if(n == 1) {
    return grid;
  }
  
  vector<string> full = grid;
  for(auto &v : full) {
    for(auto &c : v) {
      c = 'O';
    }
  }
  
  int row = grid.size();
  int col = grid[0].size();
  
  vector<string> v_3 = full;
  for(int i = 0; i < row; i++) {
    for(int k = 0; k < col; k++) {
      if(grid[i][k] == 'O') {
        v_3[i][k] = '.';
        
        if(i + 1 < row) {
          v_3[i+1][k] = '.';
        }
        
        if(0 <= i - 1) {
          v_3[i-1][k] = '.';
        }
        
        if(k + 1 < col) {
          v_3[i][k+1] = '.';
        }
        
        if(0 <= k -1) {
          v_3[i][k-1] = '.';
        }
      }
    }
  }
  
  vector<string> v_5 = full;
  for(int i = 0; i < row; i++) {
    for(int k = 0; k < col; k++) {
      if(v_3[i][k] == 'O') {
        v_5[i][k] = '.';
        
        if(i + 1 < row) {
          v_5[i+1][k] = '.';
        }
        
        if(0 <= i - 1) {
          v_5[i-1][k] = '.';
        }
        
        if(k + 1 < col) {
          v_5[i][k+1] = '.';
        }
        
        if(0 <= k -1) {
          v_5[i][k-1] = '.';
        }
      }
    }
  } 
  
  if(n % 2 == 0) {
    return full;
  }
  
  if(n % 4 == 1) {
    return v_5;
  } else {
    return v_3;
  }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
