class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int MAXi = 0, n = prices.size();
       int MAX = prices[n-1];
       for(int i = n-1; i >= 0; --i) {
           MAX = max(prices[i], MAX);
           MAXi = max(MAXi, MAX - prices[i]);
       } 
       return MAXi;
    }
};