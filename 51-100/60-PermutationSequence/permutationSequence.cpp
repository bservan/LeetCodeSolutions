#include <set>
#include <string>

using std::set;
using std::string;

class Solution {
    int findPermutation(int n) {
        if (n == 0 || n == 1) return 1;
        return n * findPermutation(n - 1);
    }
public:
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        set<char> digitsToK {};
        string result {};

        for (int i {1}; i <= n; ++i)
            digitsToK.insert(i - 1 + '1');
        
        while (digitsToK.size() != 0) {
            int perm = findPermutation(n - 1);
            int id;
            if (k % perm == 0) {
                id = k / perm - 1;
            }
            else id = k / perm;
            int idcpy = id;

            set<char>::iterator it = digitsToK.begin();
            while (id-- > 0) it++;
            result += *it;
            digitsToK.erase(it);

            k -= idcpy * perm;
            --n;
        }

        return result;
    }
};
