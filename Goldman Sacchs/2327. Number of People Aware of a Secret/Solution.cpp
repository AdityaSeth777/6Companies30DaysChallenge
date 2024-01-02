class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long ans = 0;
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        //Aditya Seth.
        for(int i=1; i<=n; i++) {
            if(dp[i])
            {
                for(int j=i+delay; j<=min(i+forget-1,n); j++) {
                    dp[j] += dp[i];
                    dp[j] %= 1000000007;
                }
            }
        }
         for(int i=n-forget+1;i<=n;i++) {
            ans += dp[i];
            ans = ans % 1000000007;
        }
     return ans;
    }
};