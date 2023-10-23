#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
  bool isWellFormed(string parenthesis) {
    int cnt{};
    for (const auto pr : parenthesis) {
      if (pr == '(') ++cnt;
      else --cnt;
      if (cnt < 0) return false;
    }
    return cnt == 0;
  }

  int pow2(int exp) {
    if (exp == 0) return 1;
    else if (exp < 0) return 0;
    return 2 * pow2(exp - 1);
  }

  vector<string> generateParenthesis(int n) {
    vector<string> parenthesis {};
    string pr {};
    int num = pow2(2 * n);
    while (num--) {
      int m = num;
      int len = 2 * n;
      while (len--) {
        if (m % 2 == 0)
          pr.push_back('(');
        else
          pr.push_back(')');
        m /= 2;
      }
      if (isWellFormed(pr))
        parenthesis.push_back(pr);
      pr = string("");
    }
    return parenthesis;
  }
};
