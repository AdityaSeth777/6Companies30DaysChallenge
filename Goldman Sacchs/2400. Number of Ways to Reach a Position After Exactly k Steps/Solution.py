class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:
        mod = 10**9 + 7
        @lru_cache(2000)
        #Aditya Seth.
        def pos(s,e,k):
            if k==0:
                if s==e: return 1
                else: return 0
            return sum([pos(s-1,e,k-1), pos(s+1,e,k-1)])
        return pos(startPos, endPos, k) % mod