class Solution:
   def equalSubstring(self, s, t, maxCost):
    max_len, left, running_sum = 0, 0, 0
    for right in range(len(s)):
        running_sum += abs(ord(s[right]) - ord(t[right]))
        while running_sum > maxCost:
            running_sum -= abs(ord(s[left]) - ord(t[left]))
            left += 1
#Aditya Seth.
        max_len = max(max_len, right - left + 1)
    return max_len