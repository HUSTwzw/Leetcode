# 1.给定一个mxn的整数数组grid,一个机器人初始位于左上角(即grid[0][0]),机器人尝试移动到右下角(即grid[m-1][n-1]
# 机器人每次只能向下或者向右移动一步,网格中的障碍物和空位置分别用1和0来表示,机器人的移动路径中不能包含任何有障碍物的方格
# 返回机器人能够到达右下角的不同路径数量。


"""
算法：参用动态规划，由于路线只有向下或向左，因此只需分析每一个格子是否可以通过左方或上方格子到达
以下为五种情况：
1.在第一行或者第一列：只有向左或向下，一旦中途有障碍物就无法继续前进，具有特殊性
2.本身就是障碍物的位置：无法到达
3.左方和上方均无法到达，意味着此地也不可能通过左方或上方到达
4.上方可以到达，左方不行/左方可以到达，上方不行
5.上方和左方都可以到达
特殊情况：在起点有障碍物或终点无法到达
"""
class Solution: 
    def PathsWithObstacles(self, obstacleGrid:list) :
        row=len(obstacleGrid)
        column=len(obstacleGrid[0])
        
        Grid=[[0]*column for _ in range(row)]
        
        for i in range(row):
            for j in range(column):
                if obstacleGrid[i][j]==1:
                    Grid[i][j]=-1       #创建新的格子图，-1表示机器人不能到达，因此障碍物所在位置均赋值为-1
        
        for j in range(column):
            if Grid[0][j]==0:
                Grid[0][j]=1
            if Grid[0][j]==-1:
                for k in range(j,column):
                    Grid[0][k]=-1       #若第一行存在障碍物，则第一行障碍物所在列以及之后的列均不可能到达，因此赋值为-1
        
        for i in range(row):
            if Grid[i][0]==0:
                Grid[i][0]=1
            if Grid[i][0]==-1:
                for k in range(i,row):
                    Grid[k][0]=-1       #若第一列存在障碍物，则第一列障碍物所在行以及之后的行均不可能到达，因此赋值为-1
        
        for i in range(1,row):
            for j in range(1,column):
                if Grid[i][j]==-1:      #不可能到达的位置直接略过
                    pass
                else:
                    if Grid[i][j-1]==-1 and Grid[i-1][j]==-1:       #当左方和上方均为-1,则不可能到达此处，因此赋值为-1
                        Grid[i][j]=-1
                    elif Grid[i][j-1]==-1:
                        Grid[i][j]=Grid[i-1][j]     #当左方为-1,而上方不为-1,则可以从上方向下到达此处，且路径数量即上方数量
                    elif Grid[i-1][j]==-1:
                        Grid[i][j]=Grid[i][j-1]     #当上方为-1,而左方不为-1,则可以从左方向右到达此处，且路径数量即左方数量
                    else:
                        Grid[i][j]=Grid[i-1][j]+Grid[i][j-1]        #当左方和上方均不为-1时，路径数量为左方与上方之和                        
        if Grid[0][0]==-1 or Grid[row-1][column-1]==-1:     #若起点或终点为-1,则不可能到达，路径数量为0
            return 0
        else:
            return Grid[row-1][column-1]        #否则路径数量为右下角
    
solution=Solution()
amount=solution.PathsWithObstacles([[0,1]])
print(amount)
amount=solution.PathsWithObstacles([[0,1],[0,0]])
print(amount)
amount=solution.PathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]])
print(amount)