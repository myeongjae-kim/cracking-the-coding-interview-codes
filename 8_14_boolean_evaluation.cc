/* input:
 
3
1^0|0|1 false
0&0&0&1^1|0 true
0^0&0^1|1 true

*/


#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

int countEval(const string exp, 
              bool expected_result,
              unordered_map<string, int> &memo) {
  if (exp.length() == 1) {
    if (expected_result == true) {
      return exp[0] == '0' ? 0 : 1;
    } else {
      return exp[0] == '0' ? 1 : 0;
    }
  }

  string key = (expected_result ? "1" : "0") + exp;

  if (memo.find(key) != memo.end()) {
    return memo[key];
  }

  int ways = 0;

  int exp_length = exp.length();
  for(int i = 0; i < exp_length; i++) {
    // Skip number
    if (exp[i] == '0' || exp[i] == '1') {
      continue;
    }

    int left[2];
    int right[2];

    left[true] = countEval(exp.substr(0, i), true, memo);
    left[false] = countEval(exp.substr(0, i), false, memo);

    right[true] = countEval(exp.substr(i + 1), true, memo);
    right[false] = countEval(exp.substr(i + 1), false, memo);
    
    switch(exp[i]) {
      case '&' :
        if(expected_result == true) {
          ways += left[true] * right[true];
        } else {
          ways += left[true] * right[false];
          ways += left[false] * right[true];
          ways += left[false] * right[false];
        }
        break;

      case '|' :
        if(expected_result == true) {
          ways += left[true] * right[true];
          ways += left[true] * right[false];
          ways += left[false] * right[true];
        } else {
          ways += left[false] * right[false];
        }
        break;

      case '^' :
        if(expected_result == true) {
          ways += left[true] * right[false];
          ways += left[false] * right[true];
        } else {
          ways += left[true] * right[true];
          ways += left[false] * right[false];
        }
        break;

      default:
        assert(false);
    }
  }

  int value = ways;

  memo.insert(pair<string, int>(key, value));

  return ways;
}


int main(void) {
  int t;
  cin >> t;

  for (int n_case = 0; n_case < t; ++n_case) {
    string exp;
    cin >> exp;

    string true_or_false;
    cin >> true_or_false;

    bool expected_result = true_or_false[0] == 't' ? true : false;

    unordered_map<string, int> memo;

    cout << countEval(exp, expected_result, memo) << endl;
  }

  return 0;
}
