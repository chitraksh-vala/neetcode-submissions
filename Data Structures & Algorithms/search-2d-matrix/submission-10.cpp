class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {   if (matrix.empty() || matrix[0].empty())
        return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=m*n-1;
        while(l<=r)
        {
            int m = l+ (r-l)/2;
            int m1=m/n;
            int m2=m%n;

            if(matrix[m1][m2] == target) return true;
            
            if(matrix[m1][m2] > target){
                r=m-1;
            }
            else {
                l=m+1;
            }
        }
        return false;
    }
};
