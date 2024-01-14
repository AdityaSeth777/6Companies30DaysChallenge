class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            int maxi = 0;
            for (int j = 0; j < i; j++)
            {
                if (dp[j] > maxi and nums[i] % nums[j] == 0)
                {
                    maxi = dp[j];
                }
            }
            dp[i] = 1 + maxi;
        }
        int maxi = -1;
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
            if (dp[i] > maxi)
            {
                ind = i;
                maxi = dp[i];
            }
        }
        // cout <<"\n" << maxi <<"";
        vector<int> ans;
        ans.push_back(nums[ind]);
        maxi--;
        int pre_ind = ind;
        // cout <<"\n" << pre_ind << endl;
        ind--;
        while (ind >= 0)
        {
            if (dp[ind] == maxi and nums[pre_ind] % nums[ind] == 0)
            {
                ans.push_back(nums[ind]);
                pre_ind = ind;
                ind--;
                maxi--;
            }
            else
            {
                ind--;
            }
        }

        return ans;
    }
};