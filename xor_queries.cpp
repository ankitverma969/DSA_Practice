class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        vector<long long> mul(n, 1);

        // ✅ Large k
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    mul[i] = mul[i] * v % MOD;
                }
            }
        }

        // ✅ Small k
        for (int k = 1; k < B; k++) {

            // rem → (index → events)
            vector<unordered_map<int, vector<pair<int,int>>>> events(k);

            for (auto &q : queries) {
                if (q[2] == k) {
                    int l = q[0], r = q[1], v = q[3];
                    int rem = l % k;

                    events[rem][l].push_back({v, 1});

                    int last = l + ((r - l) / k) * k;
                    if (last + k < n) {
                        events[rem][last + k].push_back({v, -1});
                    }
                }
            }

            for (int rem = 0; rem < k; rem++) {
                long long curr = 1;

                for (int i = rem; i < n; i += k) {
                    if (events[rem].count(i)) {
                        for (auto &[v, type] : events[rem][i]) {
                            if (type == 1)
                                curr = curr * v % MOD;
                            else
                                curr = curr * modPow(v, MOD - 2) % MOD;
                        }
                    }
                    mul[i] = mul[i] * curr % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= (nums[i] * mul[i]) % MOD;
        }

        return ans;
    }
};
