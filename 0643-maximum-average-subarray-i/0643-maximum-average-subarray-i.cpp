class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int n = nums.size();
        double curr = 0;
        
        // Sum of first window
        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }
        
        double maxAvg = curr / k;  // start with first window's average
        
        // Slide the window
        for (int i = k; i < n; i++) {
            curr += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, curr / k);
        }
        
        return maxAvg;
    }
};