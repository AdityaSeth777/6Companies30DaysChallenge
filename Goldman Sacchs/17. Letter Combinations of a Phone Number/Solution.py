class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        digitsToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        res = []
        def backtrack(start, curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return 
            for c in digitsToChar[digits[start]]:
                backtrack(start+1, curStr+c)
        # Aditya Seth.
        backtrack(0, "")
        return res if 0 < len(digits) else []