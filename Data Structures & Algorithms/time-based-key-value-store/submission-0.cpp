class TimeMap {
public:
unordered_map<string, vector<pair<int,string>>> store;
    TimeMap() 
    {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
    store[key].push_back({timestamp, value});
        }
    
    string get(string key, int timestamp)
{
    if (store.find(key) == store.end())
        return "";

    vector<pair<int,string>>& v = store[key];

    int l = 0;
    int r = v.size() - 1;
    string ans = "";

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (v[m].first <= timestamp)
        {
            ans = v[m].second;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return ans;
}
};
