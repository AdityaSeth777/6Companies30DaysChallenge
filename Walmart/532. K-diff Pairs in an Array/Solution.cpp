class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 1;
        int diff;
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        // Aditya Seth.
        while (j <= nums.size() - 1)
        {
            diff = abs(nums[i] - nums[j]);
            if (i == j)
                j++;
            else if (diff == k)
            {
                ans.insert({nums[i], nums[j]});
                ++i, ++j;
            }
            else if (diff > k)
                i++;
            else
                j++;
        }
        return ans.size();
    }
};