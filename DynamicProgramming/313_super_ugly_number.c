#define nMax 1000001
int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int dp[nMax];
    int point[101];
    for (int j=0; j<primesSize; ++j) point[j] = 0;
    dp[0] = 1;
    for (int i=1; i<n; ++i) {
        dp[i] = dp[point[0]] * primes[0];
        for (int j=1; j<primesSize; ++j) {
            int nxt = dp[point[j]] * primes[j];
            if (dp[i] > nxt) dp[i] = nxt;
        }
        for (int j=0; j<primesSize; ++j) {
            if (dp[i] == dp[point[j]] * primes[j]) point[j] ++;
        }
    }
    return dp[n-1];
}
