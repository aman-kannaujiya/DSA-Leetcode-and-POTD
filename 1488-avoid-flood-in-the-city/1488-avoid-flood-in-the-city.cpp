class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int , int> mp;
        set<int> st; // zeros days in a sorted fashion

        vector<int> ans(n , 1);
        for(int i = 0; i <n; i++){
            int lake = rains[i];
            if(lake == 0){
                st.insert(i); // ith day
            }else{
                ans[i] = -1;
                // also check if this lake already contains water , iff yes will check if we can dry it  up
                if(mp.count(lake)){ // already it has water 
                auto it = st.lower_bound(mp[lake]);
                   if(it == st.end()){ // you won't be ablel to dry this lake
                   return {};

                   }
                   // day on which no rain happened
                   int day = *it;
                   ans[day] = lake;
                   st.erase(it);
                }
                mp[lake] = i; // ith day  it rains on lake
            }
        }
        return ans;
    }
};