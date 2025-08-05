class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
          int n = fruits.size();
        vector<bool> used(n, false); // Track which baskets are already used
        int unplaced = 0;

        // For each fruit, find the leftmost available basket with enough capacity
        for (int i = 0; i < n; ++i) {
            bool placed = false;

            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break; // Place in the leftmost valid basket
                }
            }

            if (!placed)
                unplaced++;
        }

        return unplaced;
    }
};