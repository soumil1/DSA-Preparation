class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j = prices.size();
        int maximum = 0;
        int maximumprofit = 0;

        for(int i=j-1;i>=0;i--) {
            maximum = max(maximum, prices[i]); // max element defined
            maximumprofit = max(maximumprofit, maximum - prices[i]); //lower current price (dp approach)
        }

        return maximumprofit;
    }
};
