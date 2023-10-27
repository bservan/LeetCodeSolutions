#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[lo] == target) return lo;
            else if (nums[hi] == target) return hi;
            
            else if ((nums[lo] < target) && (target < nums[mid])) {
                hi = mid - 1;
            }

            else if ((nums[hi] > target) && (target > nums[mid])) {
                lo = mid + 1;
            }

            else if ((nums[mid] > target) && (nums[lo] > target) && (nums[mid] < nums[hi])) {
                hi = mid - 1;
            }

            else if ((nums[mid] < target) && (nums[lo] < target) && (nums[mid] < nums[hi])) {
                hi = mid - 1;
            }

            else if ((nums[mid] > target) && (nums[hi] > target) && (nums[lo] < nums[mid])) {
                lo = mid + 1;
            }

            else if ((nums[mid] < target) && (nums[hi] < target) && (nums[lo] < nums[mid])) {
                lo = mid + 1;
            }

            else return -1;
        }

        return -1;
    }
};
