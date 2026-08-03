class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> res;
        stack<int> temp;
        int days = 0;
        for(int i=0;i<temperatures.size();i++)
        {
            temp.push(temperatures[temperatures.size()-i-1]);
        }
        for(int j=0;j<temperatures.size();j++)
        {
            stack<int> current=temp;
            int k = 0;
            while(k<j+1)          
            {
                current.pop();
                k++;
            }

            int days=0;
            while (!current.empty() && current.top() <= temperatures[j])
            {
                days++;
                current.pop();
            }
            if(current.empty())
            {
                res.push_back(0);
            }
            else res.push_back(days+1);   
        }
        return res;
    }
};