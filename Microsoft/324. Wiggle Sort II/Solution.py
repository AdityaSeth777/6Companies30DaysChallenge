class Solution(object):
    def wiggleSort(self, nums):
        length = len(nums)
        #Aditya Seth.
        nums.sort()
        mid = (length-1)//2
        nums[::2], nums[1::2] = nums[mid::-1], nums[:mid:-1]