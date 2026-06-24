class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;

        for (int x : nums)
            s.insert(x);

        int longest = 0;

        for (int x : nums)
        {
            if (!s.count(x - 1))
            {
                int current = x;
                int length = 1;

                while (s.count(current + 1))
                {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};