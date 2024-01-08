class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int res=0;
        vector<int> temp(n);
        unordered_map<int,int> mp;
        mp[0] = 1;
        //Aditya Seth.
        for(int i=0;i<n;i++)
        {
            temp[i] = a[i]%2;
        }
        long long  sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=temp[i];
            int t = sum-k;
            if(mp.count(t))
            {
                res+=mp[t];  
            }
            mp[sum]++;
        }
        return res;
    }
};