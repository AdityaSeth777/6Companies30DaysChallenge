class Solution {
public:
    int len=1;
    int dp[13][13];
    int find(string& s, int l, int h){
        if(l>h)return 0;
        if(dp[l][h]!=-1)return dp[l][h];
        //Aditya Seth.
        if(l==h)return 1;
        if(s[l]==s[h])
            return dp[l][h]=2+find(s,l+1,h-1);
        return dp[l][h]=max(find(s,l+1,h),find(s,l,h-1));
    }
    void dfs(string &s, int ind, int bit){
        int n = s.length();
        if(ind==n){
            string s1,s2;
            int x=0;
            for(int j=0; j<n; j++){
                if(bit>>j&1)s1.push_back(s[j]);
                else s2.push_back(s[j]);
            }
            memset(dp,-1,sizeof(dp));
            int l1 = find(s1,0,s1.length()-1);
            memset(dp,-1,sizeof(dp));
            int l2 = find(s2,0,s2.length()-1);
            len = max(len,l1*l2);
            return;
        }
        for(int i=ind; i<n; i++)
            dfs(s,i+1, bit | 1<<i);
    }
    int maxProduct(string s) {
        dfs(s,0,0);
        return len;
    }
};