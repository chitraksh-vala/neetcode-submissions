class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> blocks;
        int highest=0;
        int res=0;
        int area=0;
        for(int i=0;i<heights.size();i++)
        {
            highest=max(highest,heights[i]);
        }
        for(int i = 0; i <= highest; i++)
        {
            for(int j = 0; j < heights.size(); j++)
            {
                if(heights[j] >= i)
                {
                    blocks.push(heights[j]);
                }
                else
                {
                    res = max(res, (int)blocks.size());
                    area = max(area, res * i);
                    std::stack<int>().swap(blocks);
                }
            }

            // Process the last consecutive segment
            res = max(res, (int)blocks.size());
            area = max(area, res * i);
            std::stack<int>().swap(blocks);
            res = 0;
        }
        return area;
    }
};
