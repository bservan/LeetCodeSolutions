int trailingZeroes(int n){
    int cnt = 0;
    while (n /= 5) cnt += n;
    return cnt;
}
