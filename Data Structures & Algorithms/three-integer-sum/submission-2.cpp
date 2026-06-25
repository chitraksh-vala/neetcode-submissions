class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> output;
        int size= nums.size();
        int left = 0;
        int middle;
        int right= size-1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<size-1;i++)
        {
            middle= i;
            left = 0;
            right = size - 1;
            while(!(left==middle||middle==right))
            {
                if(nums[left]+nums[middle]+nums[right]==0)
                {   

                    vector<int> temp = {nums[left], nums[middle], nums[right]};

                    if (find(output.begin(), output.end(), temp) == output.end())
                    {
                        output.push_back(temp);
                    }
                    left++;
                    right--;
                }
                else if(nums[left]+nums[middle]+nums[right]<0)
                {   if(left+1 != middle)
                    {
                        left++;
                    }
                    else{break;}    

                }
                else if(nums[left]+nums[middle]+nums[right]>0)
                {
                    if(middle+1 != right)
                    {
                        right--;
                    }
                    else{break;} 
                }
            }
        }
        return output;
    }
};
