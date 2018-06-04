#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef struct plus {
  int area;
  int row;
  int col;
} plus_t;

bool comp(plus_t& a, plus_t& b) {
  return a.area > b.area;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
  vector<plus_t> v;
  
  for(int i = 0; i < grid.size(); i++) {
    for(int k = 0; k < grid[0].size(); k++) {
      if(grid[i][k] == 'G') {
        int local_answer = 1;
        
        plus_t temp;
        
        temp.area = local_answer;
        temp.row = i;
        temp.col = k;
        
        v.push_back(temp);
        
        int level = 1;
        
        while(
          i + level < grid.size() &&
          k + level < grid[0].size() &&
          0 <= i - level &&
          0 <= k - level &&
          
          grid[i + level][k] == 'G' &&
          grid[i][k + level] == 'G' &&
          grid[i - level][k] == 'G' &&
          grid[i][k - level] == 'G'
        ) {
          local_answer += 4;
          level++;
          
          temp.area = local_answer;
          temp.row = i;
          temp.col = k;

          v.push_back(temp);
        }
        
        
      }
    }
  }
  
  if(v.size() < 2) {
    return 0;
  }
  
  sort(v.begin(), v.end(), comp);
  
  int answer = 0;
  
  for(int i = 0; i < v.size() - 1; i++) {
    set<pair<int, int>> m;
    
    m.insert(pair<int,int>(v[i].row, v[i].col));
    for(int l = 1; l * 4 + 1 <= v[i].area; l++) {
      m.insert(pair<int,int>(v[i].row + l, v[i].col));
      m.insert(pair<int,int>(v[i].row - l, v[i].col));
      m.insert(pair<int,int>(v[i].row, v[i].col + l));
      m.insert(pair<int,int>(v[i].row, v[i].col - l));
    }
    
    for(int k = i + 1; k < v.size(); k++) {
      bool is_overlapped = false;
      
      if(m.find(pair<int,int>(v[k].row, v[k].col)) != m.end()) {
        is_overlapped = true;
        continue;
      }
      for(int l = 1; l * 4 + 1 <= v[k].area; l++) {
        if(  m.find(pair<int,int>(v[k].row + l, v[k].col)) != m.end()
          || m.find(pair<int,int>(v[k].row - l, v[k].col)) != m.end()
          || m.find(pair<int,int>(v[k].row, v[k].col + l)) != m.end()
          || m.find(pair<int,int>(v[k].row, v[k].col - l)) != m.end()) {
          is_overlapped = true;
          break;
        }
        if(is_overlapped) {
          break;
        }
      }
      
      if(is_overlapped == false) {
        answer = max(answer, v[i].area * v[k].area);
      }
    }
  }
  
  return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
