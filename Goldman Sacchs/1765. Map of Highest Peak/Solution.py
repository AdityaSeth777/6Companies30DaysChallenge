class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        arr = [[-1 for _ in range(len(isWater[0]))] for _ in range(len(isWater))]
        coords = []
        for i in range(len(isWater)):
            for j in range(len(isWater[i])):
                if isWater[i][j] == 1:
                    arr[i][j] = 0
                    coords.append((i, j))
        directions = ((-1, 0), (0, -1), (1, 0), (0, 1))
        #Aditya Seth.
        while coords:
            x, y = coords.pop(0)
            for dx, dy in directions:
                fx, fy = x + dx, y + dy
                if (0 <= fx < len(arr) and 0 <= fy < len(arr[0]) and arr[fx][fy] == -1):
                    arr[fx][fy] = arr[x][y] + 1
                    coords.append((fx, fy))
        return arr