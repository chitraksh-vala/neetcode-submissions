class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int maxprofit = 0;
        int min = 0;
        int minvalue = prices[0];

        for(int i = 1; i < size; i++)
        {
            if(prices[i] < minvalue)
            {
                min = i;
                minvalue = prices[min];
            }
            else
            {
                if(maxprofit < prices[i] - minvalue)
                {
                    maxprofit = prices[i] - minvalue;
                }
            }
        }

        return maxprofit;
    }
};