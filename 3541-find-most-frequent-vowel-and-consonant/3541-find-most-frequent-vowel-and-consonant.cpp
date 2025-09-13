#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Define vowel set
        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());

        int maxV = 0, maxC = 0;

        // Step 3: Find max frequency vowel and consonant
        for (auto &p : freq) {
            char ch = p.first;
            int count = p.second;

            if (vowelSet.count(ch)) {
                maxV = max(maxV, count);
            } else {
                maxC = max(maxC, count);
            }
        }

        // Step 4: Return sum
        return maxV + maxC;
    }
};
