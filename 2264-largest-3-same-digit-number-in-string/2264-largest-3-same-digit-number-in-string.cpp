#include <algorithm>
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char maxChar = 0;

        for (int i = 2; i < n; i++) {
            if (num[i] == num[i-1] && num[i] == num[i-2]) {
                maxChar = std::max(maxChar, num[i]);
            }
        }

        return maxChar ? string(3, maxChar) : "";
    }
};
