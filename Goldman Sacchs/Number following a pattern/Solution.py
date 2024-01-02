class Solution:
    def printMinNumberForPattern(ob,s):
        result=[]
        stack=[]
        num=1
        for i in s:
            if i=='D':
                stack.append(num)
                num+=1
                #Aditya Seth.
            else:
                stack.append(num)
                num+=1
                while stack:
                    result.append(stack.pop())
        stack.append(num)
        while stack:
            result.append(stack.pop())
        return ''.join(map(str,result))