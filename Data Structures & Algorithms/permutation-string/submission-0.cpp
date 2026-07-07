class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        int s1size= s1.size();
        int s2size= s2.size();
        for(int i=0;i<s1size; i++)
        {
            freq1[s1[i]]++;
        }
        int l=0;
        for(int r=0;r<s2size;r++)
        {
            freq2[s2[r]]++;
            if(freq1==freq2)
            {
                return 1;
            }
            if(r-l+2>s1size)
            {
                freq2[s2[l]]--;
                if(freq2[s2[l]] == 0)
                    freq2.erase(s2[l]);
                l++;
            }
        }
        return 0;
    }
};
