class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;

        // find the freq of all number
        for(int &num: nums){
            freq[num]++;

        }
        // find the max freq by iterating in map
        int maxFreq =0;
        for(auto &p : freq){
            maxFreq = max(maxFreq, p.second);
        }
          //find the sum of max freq
        int total =0;
        for(auto &p : freq){
            if(p.second == maxFreq){
                total = total + p.second;
            }
        }

        return total;
    }
};