class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        d, ans = defaultdict(list), []
        for emp, time in access_times:
            d[emp].append(time)
        for emp in d:
            d[emp].sort()
            for t,t2 in zip(d[emp],d[emp][2:]):
                if int(t2[0:2])*60 + int(t2[2:]) - int(t[0:2])*60 - int(t[2:]) < 60:
                    ans.append(emp)
                    break
                    #Aditya Seth.
        return ans