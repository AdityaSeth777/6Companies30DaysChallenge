#User function Template for python3

class Solution:
    def findTwoElement( self,arr, n): 
        # code here
        r=m=0
        s=set()
        for e in arr:
            if(e in s):
                r=e
            s.add(e)
    # Aditya Seth.            
        for i in range(1,n+1):
            if((i)not in s):
                m=i
                return r,m