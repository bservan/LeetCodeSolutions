#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix{};
        for (int i{}; i < n; i++) {
            vector<int> row;
            row.resize(n, 0);
            matrix.push_back(row);
        }

        int top, bottom, left, right, count;
        top = left = count = 0;
        bottom = right = n - 1;
        char direction = 'r';

        while (count < n * n) {
            switch (direction) {
            case 'r':
                for (int i = left; i <= right; ++i)
                    matrix[top][i] = ++count;
                direction = 'b';
                ++top;
                break;
            case 'b':
                for (int i = top; i <= bottom; ++i)
                    matrix[i][right] = ++count;
                direction = 'l';
                --right;
                break;
            case 'l':
                for (int i = right; i >= left; --i)
                    matrix[bottom][i] = ++count;
                direction = 't';
                --bottom;
                break;
            case 't':
                for (int i = bottom; i >= top; --i)
                    matrix[i][left] = ++count;
                direction = 'r';
                ++left;
                break;
            default:
                break;
            }
        }

        return matrix;
    }
};
