#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
  // find the 1 after t
  
  long tick_of_1 = 3;
  long delta = 2;
  long mul = 1;
  
  while(t > tick_of_1) {
    cout << tick_of_1 << ' ';
    mul += delta;
    delta *= 2;
    tick_of_1 = 3 * mul;
  }
  cout << tick_of_1 << endl;
  
  long sum = tick_of_1 + 1;

  return sum - t;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
