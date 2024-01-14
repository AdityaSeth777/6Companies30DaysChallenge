class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        count = 0
#Aditya Seth.
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X':
                    if (i > 0 and board[i-1][j] == 'X') or (j > 0 and board[i][j-1]== 'X'):
                        pass
                    else:
                        count += 1
        return count