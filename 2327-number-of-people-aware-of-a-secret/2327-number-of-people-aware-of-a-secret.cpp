class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);

        dp[1] = 1;              // Day 1: one person knows the secret
        pref[1] = 1;

        for (int day = 2; day <= n; day++) {
            int left = max(1, day - forget + 1);
            int right = day - delay;

            if (right >= left) {
                dp[day] = (pref[right] - pref[left - 1] + MOD) % MOD;
            }
            pref[day] = (pref[day - 1] + dp[day]) % MOD;
        }

        int start = max(1, n - forget + 1);
        long long ans = 0;
        for (int i = start; i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return (int)ans;
    }
};
