class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
       int avg= nums[n/2];
       int ans=0;
       //Aditya Seth.
       for(auto i: nums){
           ans+= abs(avg-i);
       }
       return ans;
    }
};