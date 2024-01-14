#define ll long long
#define pi pair<int, int>
#define mod 1000000007
class Solution
{
public:
    int n;
    ll f(vector<int> &nums, vector<int> &count, int i, vector<unordered_map<int, ll>> &dp, int mask)
    {
        if (i == n)
            return 1;
        // Aditya Seth.
        if (dp[i].count(mask))
            return dp[i][mask];
        ll x = f(nums, count, i + 1, dp, mask);
        ll y = 0;
        bool check = true;
        ll temp = nums[i];
        int idx = 2;
        int mask1 = mask;
        while (temp && temp >= idx)
        {
            if (temp % idx == 0)
            {
                if (mask & (1 << idx))
                {
                    check = false;
                    break;
                }
                mask |= (1 << idx);
                temp /= idx;
            }
            else
                idx++;
        }
        if (check)
            y = f(nums, count, i + 1, dp, mask);
        ll cnt = count[i];
        if (!i && x + y * cnt == mod)
        {
            return mod;
        }
        dp[i][mask1] = (x + y * cnt) % mod;
        return dp[i][mask1];
    }

    int squareFreeSubsets(vector<int> &nums)
    {
        n = size(nums);
        sort(nums.begin(), nums.end());
        vector<int> arr, count;
        int cnt = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                cnt1++;
                continue;
            }
            int j = i;
            while (j < n and nums[j] == nums[i])
            {
                cnt++;
                j++;
            }
            arr.push_back(nums[i]);
            count.push_back(cnt);
            i = j - 1;
            cnt = 0;
        }
        n = arr.size();
        vector<unordered_map<int, ll>> dp(n + 1);
        ll ans = f(arr, count, 0, dp, 0);
        ll exp = 1, base = 2;
        if (cnt1 == 0)
        {
            if (ans == 0)
                return 1000000006;
            return (ans - 1) % mod;
        }
        while (cnt1 > 0)
        {
            if (cnt1 & 1)
            {
                exp = (exp * base) % mod;
            }
            base = (base * base) % mod;
            cnt1 /= 2;
        }
        return (ans * exp + mod) % mod - 1;
    }
};