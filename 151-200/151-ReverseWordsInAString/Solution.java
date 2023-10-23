class Solution {
    private void reverseArray(String[] strArr) {
        for (int i = 0, j = strArr.length - 1; i < j; ++i, --j) {
            String tmp = strArr[i];
            strArr[i] = strArr[j];
            strArr[j] = tmp;
        }
    }
    public String reverseWords(String s) {
        String[] words = s.split("\s+");
        reverseArray(words);
        return String.join(" ", words).trim();
    }
}
