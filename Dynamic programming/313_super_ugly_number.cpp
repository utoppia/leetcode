class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        int m = primes.size();
        vector<int> point(m);

        for(int i=1; i<n; ++i) {
            dp[i] = dp[point[0]] * primes[0];
            for(int j=1; j<m; ++j) {
                dp[i] = min(dp[i], dp[point[j]] * primes[j]);
            }
            for(int j=0; j<m; ++j) {
                if (dp[i] == dp[point[j]] * primes[j]) point[j] ++;
            }
        }
        return dp[n-1];
    }
};
