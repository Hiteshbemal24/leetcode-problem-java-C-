#define f first
#define s second

class Solution {
public:
    map<int, int> m;
    vector<int> all;
    int minGroupsForValidAssignment(vector<int>& nums) {
        for(auto it : nums)
            m[it] ++;  

        for(auto it : m)
        {
            all.push_back(it.s); 
        }

        sort(all.begin(), all.end());  

        int ans = 2e9;
        for(int gr = 1; gr <= all[0]; gr++)
        {
            int a = gr, b = gr + 1;
            int num = 0;
            bool bad = false;

            for(int i = 0; i < all.size(); i ++)
            {
                int cur = all[i];
                int mn = 2e9, cnt = 0;

                while(cur >= 0)
                {
                    if(cur % a == 0) mn = cnt + cur / a;
                    cur -= b;
                    cnt ++;
                }

                if(mn == 2e9)
                {
                    bad = true;
                    break;
                }

                num += mn; 

            }

            if(!bad)
                ans = min(ans, num); 
        }

        return ans; 
    }
};
