class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [True] + [False] * len(s)
        # Aditya Seth.
        for i in range(1, len(s) + 1):
            for w in wordDict:
                if s[i - len(w): i] == w and dp[i - len(w)]:
                    dp[i] = True
                    break
        return dp[-1]
