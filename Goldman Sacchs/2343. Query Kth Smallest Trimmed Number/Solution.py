class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:   
        num_value_dict = defaultdict(list)
        MAX_TRIM_VAL = len(nums[0])
        for i in range(1,MAX_TRIM_VAL+1):
            for j,n in enumerate(nums):
                num_value_dict[i].append((int(n[MAX_TRIM_VAL-i:]),j))
        for n in num_value_dict:
            num_value_dict[n].sort(key = lambda x: (x[0],x[1]))
        answer = []
        for k,key in queries:
            answer.append(num_value_dict[key][k-1][1])
        #Aditya Seth.
        return answer