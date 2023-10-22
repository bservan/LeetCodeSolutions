int searchInsert(int* nums, int numsSize, int target) {
    int lo = 0, hi = numsSize - 1;
    int mid = lo + (hi - lo) / 2;

    while (lo <= hi) {
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
        mid = lo + (hi - lo) / 2;
    }

    return mid;
}
