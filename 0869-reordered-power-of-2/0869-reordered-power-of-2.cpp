class Solution {
    string signature(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        static unordered_set<string> powerSignatures;
        if (powerSignatures.empty()) {
            for (int i = 0; i < 31; ++i) {
                powerSignatures.insert(signature(1 << i));
            }
        }
        return powerSignatures.count(signature(n));
    }
};