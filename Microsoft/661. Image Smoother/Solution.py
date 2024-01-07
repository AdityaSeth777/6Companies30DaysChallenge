class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        dx = [-1,-1,-1,0,0,0,1,1,1]
        dy = [-1,0,1,-1,0,1,-1,0,1]
        m = int(len(img))
        n = int(len(img[0]))
        # Aditya Seth.
        ans = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                sum = 0
                count = 0
                for a in range(0,9):
                    x = i + dx[a]
                    y = j + dy[a]
                    if x >= 0 and y >= 0 and x < m  and y < n:
                        count += 1
                        sum += img[x][y]
                print(i,j,count,sum,sum//count)
                ans[i][j] = sum//count
        return ans