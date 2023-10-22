#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int sz = s.size();
        unordered_set<char> charSet {};
        int len {}, i {}, j {};

        while (i < sz && j < sz) {
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j++]);
                len = max(len, j - i);
            }   
            else charSet.erase(s[i++]);
        }

        return len;
    }
};
