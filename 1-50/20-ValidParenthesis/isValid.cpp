#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
public:
    bool isValid(string s) {
        stack<char> pars {};
        int s_len = s.size();

        for (int i {}; i < s_len; i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    pars.push(s[i]);
                    break;
                case ')':
                    if (!pars.empty() && pars.top() == '(') pars.pop();
                    else return false;
                    break;
                case ']':
                    if (!pars.empty() && pars.top() == '[') pars.pop();
                    else return false;
                    break;
                case '}':
                    if (!pars.empty() && pars.top() == '{') pars.pop();
                    else return false;
                    break;
            }
        }

        return pars.empty();
    }
};
