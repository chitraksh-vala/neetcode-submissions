class Solution {
public:
string minWindow(string s, string t) 
{
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    unordered_map<char, int> windowCount;
    int required = need.size();   // distinct chars needed
    int formed = 0;               // distinct chars currently satisfied

    int l = 0;
    string output = "";

    for (int r = 0; r < s.size(); r++)
    {
        char c = s[r];
        if (need.count(c))
        {
            windowCount[c]++;
            if (windowCount[c] == need[c]) formed++;
        }

        while (formed == required)
        {
            string temp = s.substr(l, r - l + 1);
            if (output == "" || temp.size() < output.size())
                output = temp;

            char lc = s[l];
            if (need.count(lc))
            {
                windowCount[lc]--;
                if (windowCount[lc] < need[lc]) formed--;   // only NOW is it truly unsatisfied
                
            }
            l++;
        }
    }
    return output;
}
};