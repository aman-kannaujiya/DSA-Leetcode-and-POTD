class Solution {
public:
    string largestGoodInteger(string num) {
    int n = num.size();
    int best = -1;

    for (int i = 0; i + 2 < n; ++i) {
        if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
            best = max(best, num[i] - '0');
        }
    }

    if (best == -1) return "";
    return string(3, '0' + best);
}

};