class Solution {
public:
   bool verify(int k, const vector<int>& piles, int h)
{
    long long h1 = 0;

    for (int x : piles)
    {
        h1 += (x + k - 1LL) / k;

        if (h1 > h)
            return false;
    }

    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        vector<int> pil=piles;
        int size=piles.size();
        int l=1;
        sort(pil.begin(),pil.end());
        int r = pil[size - 1];
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(verify(m,piles,h))
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }  
        return l;      
    }
};
