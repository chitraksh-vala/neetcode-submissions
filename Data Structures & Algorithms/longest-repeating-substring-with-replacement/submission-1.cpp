class Solution {
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freq;

        int l = 0;
        int output = 0;
        char main = s[0];

        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;

            if (freq[s[r]] > freq[main])
                main = s[r];

            while ((r - l + 1) - freq[main] > k)
            {
                freq[s[l]]--;
                l++;

                // Recompute the most frequent character
                main = s[l];
                for (char c = 'A'; c <= 'Z'; c++)
                {
                    if (freq[c] > freq[main])
                        main = c;
                }
            }

            output = max(output, r - l + 1);
        }

        return output;
    }
};