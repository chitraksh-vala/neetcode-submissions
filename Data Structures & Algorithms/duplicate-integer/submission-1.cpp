class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> num;
        for(int i=0;i<nums.size();i++)
        {
            if(num.count(nums[i]))
            {
                return true;
            }
            else
            {
                num.insert(nums[i]);
            }
        }   
        return false;
    }
};