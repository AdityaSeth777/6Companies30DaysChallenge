class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, prev;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += i * nums[i];
            sum += nums[i];
        }
        prev = ans;
        // Aditya Seth.
        for (int i = 1; i < n; i++)
        {
            int curr = prev + sum - n * (nums[n - i]);
            ans = max(curr, ans);
            prev = curr;
        }
        return ans;
    }
};