#define MIN(num1, num2) ((num1) < (num2)) ? (num1) : (num2)
#define MAX(num1, num2) ((num1) > (num2)) ? (num1) : (num2)

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        min = MIN(min, prices[i]);
        max = MAX(max, prices[i] - min);
    }
    return max;
}
