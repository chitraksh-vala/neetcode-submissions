class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    int size= nums.size();
    for(int i=0;i<size;i++)
    {
        if (!s.count(nums[i]))
        {
          s.insert(nums[i]);
        }
        else return 1;
    }
        return 0;
    }
};