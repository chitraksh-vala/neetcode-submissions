class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int size=position.size();

        vector<pair<int,int>> vp;
        for(int i=0;i<size;i++)
        {
            vp.push_back({position[i], speed[i]});
        }
        sort(vp.begin(), vp.end());

        stack<pair<int,int>> cars;
        for(int i=0;i<size;i++)
        {
            cars.push({vp[i].first, vp[i].second});
        }

        int i=0;
        int res=0;
        double time = -1;
        while(i<size)
        {
            if(time>=(double)(target - cars.top().first) / cars.top().second)
            {
                cars.pop();
                i++;
            }
            else
            {
                res++;
                time=(double)(target - cars.top().first) / cars.top().second;
                cars.pop();
                i++;
            }
        }
        return res;
    }
};