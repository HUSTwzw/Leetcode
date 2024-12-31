# 1.一个机器人位于一个mxn网格的左上角(起始点在下图中标记为“Start”)
# 机器人每次只能向下或者向右移动一步,机器人试图达到网格的右下角(在下图中标记为“Finish”),问总共有多少条不同的路径？


# 方法一：递归法
"""
算法:在没有到达行边界或列边界时，下一步有两个选择(向下或向左),直到到达终点为止
因此可以使用递归法
"""
def find_path(row_site:int,column_site:int,row:int,column:int):
    global method1
    if row_site==row and column_site==column:
        method1+=1
        return 
    else:
        if row_site==row:
            find_path(row_site,column_site+1,row,column)
        elif column_site==column:
            find_path(row_site+1,column_site,row,column)
        else:
            find_path(row_site+1,column_site,row,column)
            find_path(row_site,column_site+1,row,column)
      
row=int(input("请输入行数"))
column=int(input("请输入列数"))
method1=0            
find_path(1,1,row,column)
print(method1)


# 方法二：动态规划法
"""
算法：
用f(i,j)表示从左上角走到(i,j)的路径数量,其中i和j的范围分别是[0,m)和[0,n)
由于每一步只能从向下或者向右移动一步,因此要想走到(i,j),如果向下走一步,那么会从(i-1,j)走过来;如果向右走一步,那么会从(i,j-1)走过来
因此可以写出动态规划转移方程:f(i,j)=f(i-1,j)+f(i,j-1)
从(0,0)到达第一行任何位置只需要向右移动,因此只有一种方法,同理,从(0,0)到达第一列任何位置只需要向下移动,因此只有一种方法
则初始化时f(0,i)=1 (i=0,1,……column-1),f(i,0)=1 (i=0,1……row-1)
方法总数为f(row-1,column-1)
"""
row=int(input("请输入行数"))
column=int(input("请输入列数"))
def find_path(row:int,column:int):
    grid=[[1]*column]+[[1]+[0]*(column-1)]*(row-1)
    for i in range(1,row):
        for j in range(1,column):
            grid[i][j]=grid[i-1][j]+grid[i][j-1]
    return grid[row-1][column-1]

method2=find_path(row,column)
print(method2)