// No input

#define N_QUEENS 8
#define N_BOARD_SIZE 8

#include <iostream>
#include <cstring>

int distribute_queens(int left_queens, int row, int board[N_BOARD_SIZE]) {
  if (left_queens == 0) {
    return 1;
  }

  int ways = 0;
  if(left_queens + row < N_BOARD_SIZE) {
    // chance to skip a queen in this row
    ways += distribute_queens(left_queens, row + 1, board);
  }

  // compare distributed queens
  bool possible;
  for(int col = 0; col < N_BOARD_SIZE; col++) {
    // we do not have to consider rows.
    possible = true;

    // check cols
    for(int i = 0; i < row; i++) {
      if(board[i] == col) {
        possible = false;
        break;
      }
    }

    if(possible == false) { continue; }

    // check diagonal (row, col)

    for(int row_before = 0; row_before < row; row_before++) {
      if (board[row_before] == -1) {
        // No queens in before row
        continue;
      }

      int row_dist = row - row_before;
      int col_dist = col - board[row_before];

      //absolute value
      col_dist = col_dist < 0 ? -col_dist : col_dist;
      if(row_dist == col_dist) {
        possible = false;
      }
    }

    if(possible == false) {
      continue;
    } else { 
      board[row] = col;
      ways += distribute_queens(left_queens - 1, row + 1, board);
      board[row] = -1;
    }
  }
  return ways;
}

int main(void) {
  int left_queens = N_QUEENS;
  int board[N_BOARD_SIZE];

  memset(board, -1, sizeof(board));

  int ways = distribute_queens(left_queens, 0, board);

  std::cout << ways << std::endl;

  return 0;
}
