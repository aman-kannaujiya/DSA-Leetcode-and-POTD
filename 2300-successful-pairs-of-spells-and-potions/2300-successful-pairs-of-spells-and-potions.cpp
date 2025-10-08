#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort the potions
        sort(potions.begin(), potions.end());
        vector<int> ans;

        // Step 2: For each spell
        for (int spell : spells) {
            // We want spell * potion >= success
            // So potion must be at least success / spell
            long long need = (success + spell - 1) / spell; // same as ceil(success / spell)

            // Step 3: Find the first potion >= need
            int index = lower_bound(potions.begin(), potions.end(), need) - potions.begin();

            // Step 4: Count how many potions work
            int count = potions.size() - index;
            ans.push_back(count);
        }

        // Step 5: Return the final answer
        return ans;
    }
};
