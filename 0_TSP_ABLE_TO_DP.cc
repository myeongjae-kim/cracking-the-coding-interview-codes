#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

int traveling_salesman(int **adj_mat,
                        vector<int>& vertices,
                        vector<int>& prefix,
                        const int& start_vertex) {
  // base case
  if (vertices.size() == 0) {
    return adj_mat[*prefix.rbegin()][start_vertex];
  }

  int local_answer;
  int best_answer = INT_MAX;

  vector<int> left_vertices;
  for(int i = 0; i < vertices.size(); i++) {
    left_vertices.clear();
    for(int k = 0; k < vertices.size(); k++) {
      if(k != i) {
        left_vertices.push_back(vertices[k]);
      }
    }

    int from;
    if (prefix.size() == 0) {
      from = start_vertex;
    } else {
      from = *prefix.rbegin();
    }
    int to = vertices[i];

    prefix.push_back(vertices[i]);

    local_answer = adj_mat[from][to];

    if (local_answer == 0) {
      return INT_MAX;
    }

    local_answer += traveling_salesman(adj_mat, left_vertices, prefix, start_vertex);
    if(local_answer < best_answer) {
      best_answer = local_answer;
    }
    prefix.pop_back();
  }


  return best_answer;
}

// It returns minimum cost
int traveling_salesman(int** adj_mat, int n_vertex, int start_vertex) {
  // permutation except start vertex
  vector<int> vertices;
  for(int i = 1; i < n_vertex; i++) {
    if (i != start_vertex) {
      vertices.push_back(i);
    }
  }

  vector<int> prefix;
  int answer = traveling_salesman(adj_mat, vertices, prefix, start_vertex);

  return answer;
}

void print_adj_mat(int** adj_mat, int n_vertex) {
  for(int i = 1; i < n_vertex; i++) {
    for(int k = 1; k < n_vertex; k++) {
      cout << setw(3) << adj_mat[i][k] << ' ';
    }
    cout << endl;
  }
}

int main(void) {
  int t;
  cin >> t;

  for(int n_case = 1; n_case <= t; n_case++) {
    int n_vertex;
    cin >> n_vertex;

    n_vertex++;

    int** adj_mat = new int*[n_vertex]();

    for(int i = 0; i < n_vertex; i++) {
      adj_mat[i] = new int[n_vertex]();
    }

    int n_edges;
    cin >> n_edges;

    int from, to, weight;

    for(int i = 0; i < n_edges; i++) {
      cin >> from >> to >> weight;
      adj_mat[from][to] = weight;
      adj_mat[to][from] = weight; // undirected graph
    }
    
    print_adj_mat(adj_mat, n_vertex);
    int answer = traveling_salesman(adj_mat, n_vertex, 1);
  
    for(int i = 0; i < n_vertex; i++) {
      delete[] adj_mat[i];
    }
    delete[] adj_mat;

    cout << "Case #" << t << ": " << answer << endl;
  }

  return 0;
}
