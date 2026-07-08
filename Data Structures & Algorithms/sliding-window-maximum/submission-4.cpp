class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int current_max=nums[0];
        vector<int> output;
        if(k==1)
        {
            return nums;
        }
        for(int r=0;r<nums.size();r++)
        {
            int l=r-k+1;
            current_max=max(current_max,nums[r]);
            if(l>=0)
            {
                output.push_back(current_max);
                if(nums[l]==current_max)
                {
                    current_max=nums[l+1];
                    for(int i=l+1;i<r+1;i++)
                    {
                        current_max=max(current_max,nums[i]);
                    }
                }
            }            
        }
        return output;
    }
};
 