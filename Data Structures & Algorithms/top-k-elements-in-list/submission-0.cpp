class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        map<int, vector<int>> freq;

        // Count frequency
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        // Group numbers by frequency
        for(auto x : m)
        {
            freq[x.second].push_back(x.first);
        }

        vector<int> result;

        // Traverse highest frequency to lowest
        for(auto it = freq.rbegin();
            it != freq.rend();
            it++)
        {
            for(int num : it->second)
            {
                result.push_back(num);

                if(result.size() == k)
                {
                    return result;
                }
            }
        }

        return result;
    }
};