# time: O(mn)
# space: O(1)

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        #0 0
        #1 1
        #1 -1
        #0 2

        for i in range(len(board)):
            for j in range(len(board[0])):
                live_nei_cnt = 0
                for x in [-1, 0, 1]:
                    for y in [-1, 0, 1]:
                        if x == y == 0:
                            continue
                        if 0 <= i+x < len(board) and 0 <= j+y < len(board[0]) and abs(board[i+x][j+y]) == 1:
                            live_nei_cnt += 1
                
                if board[i][j] == 1 and (live_nei_cnt < 2 or live_nei_cnt > 3):
                    board[i][j] = -1
                elif board[i][j] == 0 and live_nei_cnt == 3:
                    board[i][j] = 2
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = 1 if board[i][j] > 0 else 0
        return board

