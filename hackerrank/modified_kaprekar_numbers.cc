#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
bool is_k_number(long n) {
  long length = 0;
  
  long temp = n;
  while(temp) {
    length++;
    temp /= 10;
  }
  
  long square = n * n;
  
  long right_side = 0;
  int div = 1;
  
  for(long i = 0; i < length; i++) {
    div *= 10;
  }
  
  right_side = square % div;
  square /= div;
  
  if(square + right_side == n) {
    return true;
  } else {
    return false;
  }
}

vector<long> kaprekarNumbers(long p, long q) {
  vector<long> answer;
  
  for(long i = p; i <= q; i++) {
    if(is_k_number(i)) {
      answer.push_back(i);
    }
  }

  return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long> result = kaprekarNumbers(p, q);
  
    if(result.empty()) {
      fout << "INVALID RANGE" << endl;
    } else {

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
