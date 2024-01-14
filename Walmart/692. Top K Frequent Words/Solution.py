class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        maxi = 0
        d = defaultdict(int)
        count = defaultdict(list)
        for i in words:
            d[i] += 1
            count[d[i]].append(i)
            maxi = max(maxi, d[i])
        ans = []
        visited = set()
# Aditya Seth.
        while k:
            count[maxi].sort()
            for i in count[maxi]:
                if i not in visited:
                    ans.append(i)
                    visited.add(i)
                    k -= 1
                    if not k:
                        return ans
            maxi -= 1
        return ans
