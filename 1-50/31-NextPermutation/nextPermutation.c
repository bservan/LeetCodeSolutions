static void swapNums(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 1;

    while (i > 0 && nums[i - 1] >= nums[i]) --i;
    if (i == 0) {
        while (i < numsSize / 2)
            swapNums(nums + i++, nums + numsSize - 1 - i);
        return;
    }

    int j = numsSize - 1;

    while (j > 0 && nums[i - 1] >= nums[j]) --j;
    swapNums(nums + i - 1, nums + j);

    j = numsSize - 1;

    while (i < j) swapNums(nums + i++, nums + j--);
}
