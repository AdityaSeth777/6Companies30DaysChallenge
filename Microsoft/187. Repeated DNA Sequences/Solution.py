class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen, res = set(), set()
        for i in range(len(s) - 10 + 1):
            substring = s[i:i + 10]
            if substring in seen:
                res.add(substring)
                #Aditya Seth.
            seen.add(substring)
        return res