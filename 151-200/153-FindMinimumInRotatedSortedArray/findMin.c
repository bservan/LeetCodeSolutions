int findMin(int* nums, int numsSize){
    int lo = 0, hi = numsSize - 1;
    int mid = lo + (hi - lo) / 2;

    while (lo < hi) {
        if (nums[mid] > nums[hi] && (hi - lo) > 2) {
            lo = mid;
        } else if (nums[lo] > nums[mid] && (hi - lo) > 2) {
            hi = mid;
        } else {
            if ((mid - lo == 1) && (nums[lo] > nums[mid]))
                return nums[mid];
            else if ((hi - mid == 1) && (nums[mid] > nums[hi]))
                return nums[hi];
            return nums[lo];
        }
        mid = lo + (hi - lo) / 2;
    }

    return nums[mid];
}
