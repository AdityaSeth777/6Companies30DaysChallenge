class Solution:
    def maxSubsequence(self, arr: List[int], k: int) -> List[int]:
        return [j[1] for j in sorted(sorted(enumerate(arr), reverse=True, key=lambda x: x[1])[:k], key=lambda x: x[0])]
    # Aditya Seth.
