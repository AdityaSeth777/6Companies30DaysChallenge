class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        #Aditya Seth.
        return sum(all(a < b for a, b in pairwise(nums[:i] + nums[j:])) for i, j in combinations(range(len(nums)+1), 2))