/*
1_7_Rotate Matrix
Given an image represented by an NxN matrix, where each pixel
in the image is 4 bytes, write a method to rotate the image by 90
degrees. Can you do this in place?

Input
2
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3
4 5 6
7 8 9

Output
Case #1:
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
Case #2:
7 4 1
9 5 2
9 6 3

*/

#include <iostream>
#include <cstdint>

using namespace std;

void print_square(int** square, int len) {
  for (int i = 0; i < len; ++i) {
    for (int k = 0; k < len; ++k) {
      cout << square[i][k] << ' ';
    }
    cout << endl;
  }
}

void rotate_clockwise(int** square, int len) {
  int32_t num_of_layers = len / 2;
  int32_t max_idx = len-1;

  // temp = north
  // north = west
  // west = south
  // south = east
  // east = temp

  for (int32_t i = 0; i < num_of_layers; ++i) {
    for (int32_t k = i; k < len - i - 1; k++) {
      int32_t temp = square[i][k]; // (0,2)
      square[i][k] = square[max_idx-k][i]; // (0,2) = (3-2,0)
      square[max_idx-k][i] = square[max_idx-i][max_idx-k]; // (1,0) = (3,3-2)
      square[max_idx-i][max_idx-k] = square[k][max_idx-i]; // (3,1) = (2,3)
      square[k][max_idx-i] = temp; // (2,3) = (0,2)
    }
  }

}

int main(void)
{
  int32_t tc;

  cin >> tc;

  for (int t = 1; t <= tc; ++t) {
    int32_t **square;
    int32_t len;

    cin >> len;
    square = new int*[len]();
    for (int32_t i = 0; i < len; ++i) {
      square[i] = new int32_t[len]();
    }

    // get input
    for (int32_t i = 0; i < len; ++i) {
      for (int32_t k = 0; k < len; ++k) {
        cin >> square[i][k];
      }
    }

    // rotate input
    rotate_clockwise(square, len);
    
    cout << "Case #" << t << ": " << endl;
    //printing answer
    print_square(square, len);
    

    for (int32_t i = 0; i < len; ++i) {
      delete[] square[i];
    }
    delete[] square;
  }


  return 0;
}
