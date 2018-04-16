#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define DELAY 1000000
#define usleep(a);
#define N_POLES 3

void print_poles(vector<int> poles[N_POLES]) {
  int sizes[N_POLES];
  for (int i = 0; i < N_POLES; ++i) {
    sizes[i] = poles[i].size();
  }

  int max_size = sizes[0];
  for (int i = 1; i < N_POLES; ++i) {
    max_size = max_size > sizes[i] ? max_size : sizes[i];
  }

  system("clear");
  for (int i = max_size - 1; i >= 0; --i) {
    for (int j = 0; j < N_POLES; ++j) {
      if (i < sizes[j]) {
        cout << poles[j][i];
      }
      cout << '\t';
    }
    cout << endl;
  }
}


void move_disk(vector<int> poles[N_POLES],
                       int src_pole,
                       int dst_pole,
                       int num_disks) {
  if(num_disks == 1) {
    int disk = *(poles[src_pole].rbegin());
    poles[src_pole].pop_back();
    poles[dst_pole].push_back(disk);
    return;
  }


  int mid_dst_pole = 0;

  while (mid_dst_pole == src_pole || mid_dst_pole == dst_pole) {
    mid_dst_pole++;
  }

  move_disk(poles, src_pole, mid_dst_pole, num_disks - 1);
  print_poles(poles);
  usleep(1000000);
  move_disk(poles, src_pole, dst_pole, 1);
  print_poles(poles);
  usleep(1000000);
  move_disk(poles, mid_dst_pole, dst_pole, num_disks - 1);
  print_poles(poles);
  usleep(1000000);
}

void move_disk(vector<int> poles[N_POLES], int src_pole, int dst_pole) {
  move_disk(poles, src_pole, dst_pole, poles[src_pole].size());
}

int main(void)
{
  int disks;
  cin >> disks;

  vector<int> poles[N_POLES];
  for (int i = disks; i > 0; --i) {
    poles[0].push_back(i);
  }

  print_poles(poles);
  usleep(1000000);

  move_disk(poles, 0, 1);
  return 0;
}
