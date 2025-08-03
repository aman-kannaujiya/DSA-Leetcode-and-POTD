class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> positions, prefix(n, 0);

        // Step 1: Build positions and prefix sum array
        for (int i = 0; i < n; i++) {
            positions.push_back(fruits[i][0]);
            prefix[i] = fruits[i][1] + (i > 0 ? prefix[i - 1] : 0);
        }

        int result = 0;

        // Step 2: Try every possible turning point d from 0 to k/2
        for (int d = 0; d <= k / 2; d++) {
            // Case 1: Move d to the left, then right (total steps ≤ k)
            int i = startPos - d;
            int j = startPos + (k - 2 * d);
            auto left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            auto right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (left <= right && right < n) {
                result= max(result, prefix[right] - (left > 0 ? prefix[left - 1] : 0));
            }

            // Case 2: Move d to the right, then left (total steps ≤ k)
            i = startPos - (k - 2 * d);
            j = startPos + d;
            left = lower_bound(positions.begin(), positions.end(), i) - positions.begin();
            right = upper_bound(positions.begin(), positions.end(), j) - positions.begin() - 1;

            if (left <= right && right < n) {
                result = max(result, prefix[right] - (left > 0 ? prefix[left - 1] : 0));
            }
        }

        return result;
    }
};