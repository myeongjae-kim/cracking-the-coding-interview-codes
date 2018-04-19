#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Box {
  private:
    int width;
    int height;
    int depth;
    bool stacked;

  public:
    Box(int, int, int);
    bool operator<=(Box&);
    bool operator>=(Box&);
    void make_stacked(void);
    void make_unstacked(void);
    bool get_stack_status(void);

    int get_height(void);
};

Box::Box(int width, int height, int depth) {
  this->width = width;
  this->height = height;
  this->depth = depth;
  this->stacked = false;
}

bool Box::operator<=(Box& arg) {
  return this->width  <= arg.width &&
         this->height <= arg.height &&
         this->depth  <= arg.depth;
}

bool Box::operator>=(Box& arg) {
  return this->width  >= arg.width &&
         this->height >= arg.height &&
         this->depth  >= arg.depth;
}

void Box::make_stacked(void) {
  stacked = true;
}

void Box::make_unstacked(void) {
  stacked = false;
}


bool Box::get_stack_status(void) {
  return stacked;
}

int Box::get_height(void) {
  return height;
}

// return max height
int find_max_height(vector<Box> &boxes, Box &below_box,
                     int current_height) {
  int local_answer;
  int answer = current_height;

  for(auto it = boxes.begin(); it != boxes.end(); it++) {
    if (it->get_stack_status() == false && *it <= below_box) {
      it->make_stacked();

      local_answer = find_max_height(boxes, *it,
                         current_height + it->get_height());
      answer = local_answer > answer ? local_answer : answer;

      it->make_unstacked();
    }
  }

  return answer;
}

int main(void)
{
  int n_box;
  cin >> n_box;

  vector<Box> boxes;

  for(int i = 0; i < n_box; i++) {
    int width, height, depth;
    cin >> width >> height >> depth;

    Box buf_box(width, height, depth);
    boxes.push_back(buf_box);
  }

  // sort for only one dimension.

  sort(boxes.begin(), boxes.end(),
      [](Box& a, Box& b) -> bool {
        return a.get_height() > b.get_height();
      });



  Box dummy_box(INT_MAX, INT_MAX, INT_MAX);
  cout << find_max_height(boxes, dummy_box, 0) <<  endl;

  
  return 0;
}
