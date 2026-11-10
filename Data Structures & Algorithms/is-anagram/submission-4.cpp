class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<int, int> s_set;
        unordered_map<int, int> t_set;
        for(int i=0;i<s.size();i++)
        {
            s_set[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            t_set[t[i]]++;
        }
        if(s_set==t_set)
        {
            return true;
        }
        else
        {
         return false;
        
        }


    }
};
