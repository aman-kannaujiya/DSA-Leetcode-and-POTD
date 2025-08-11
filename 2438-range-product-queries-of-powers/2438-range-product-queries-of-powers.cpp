class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int bit = 0;
        
        // Extract powers of two
        while (n > 0) {
            if (n & 1) {
                powers.push_back(1LL << bit);
            }
            bit++;
            n >>= 1;
        }
        
        // prefix product
        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i-1] * powers[i]) % MOD;
        }
        
        // answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = prefix[r];
            if (l > 0) {
                prod = (prod * modPow(prefix[l-1], MOD-2)) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
