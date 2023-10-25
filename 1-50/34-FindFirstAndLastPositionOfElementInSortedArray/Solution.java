class Solution {
    private int binarySearch(int arr[], int first, int last, int key) {  
        if (last >= first) {  
            int mid = first + (last - first)/2; 

            if (arr[mid] == key){  
                return mid;  
            } else if (arr[mid] > key) {  
                return binarySearch(arr, first, mid - 1, key);  
            } else {  
                return binarySearch(arr, mid + 1, last, key); 
            }  
        }

        return -1;  
    }  
    public int[] searchRange(int[] nums, int target) {
        int[] returnRange = new int[] {-1 ,-1};
        int first = 0, last = nums.length - 1;
        int resLeft = binarySearch(nums, first, last, target);
        int resRight = binarySearch(nums, first, last, target);

        if (resLeft != -1) {
            returnRange[0] = returnRange[1] = resLeft;
        }

        boolean doBinSearchLeft = true;
        boolean doBinSearchRight = true;

        while (doBinSearchLeft || doBinSearchRight) {
            first = 0;
            last = resLeft - 1;

            if (doBinSearchLeft) {
                resLeft = binarySearch(nums, first, last, target);
            }

            first = resRight + 1;
            last = nums.length - 1;

            if (doBinSearchRight) {
                resRight = binarySearch(nums, first, last, target);
            }
            if (resLeft != -1 && resLeft < returnRange[0]) {
                returnRange[0] = resLeft;
            } else {
                doBinSearchLeft = false;
            }
            if (resRight != -1 && resRight > returnRange[1]) {
                returnRange[1] = resRight;
            } else {
                doBinSearchRight = false;
            }
        }

        return returnRange;
    }
}
