class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int profit =0;
        int n = prices.size();
        
        for(int i=0;i<n;i++)
        {
            if(prices[i]<minprice)
                minprice = prices[i];
            profit = max(profit, prices[i]-minprice);
        }
        return profit;
        
    }
};