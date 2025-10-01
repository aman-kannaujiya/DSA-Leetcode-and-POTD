class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int , int> mp;
        // for(int num : nums){
        //     mp[num]++;
        // }
        // for(auto pair: mp){
        //     if(pair.second ==1){
        //         return pair.first;
        //     }
        // }
        // return -1;
        

        // USING THE CONCEPT OF XOR 

        int ans = 0;
        for(int val : nums){
            ans = ans^val;
        }
        return ans;
    }
};