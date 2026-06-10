class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> s;
        vector<int> result(2);
        for(int i=0;i<size;i++)
        {
            if(!s.count(target-nums[i]))
            {
                s[nums[i]]=i;
            }
            else
            {
                
                
            result[0]=s[target-nums[i]];
            result[1]=i;
                
                
            }
        }
        return result;
    }
};
