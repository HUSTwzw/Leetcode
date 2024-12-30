# 1.将一个给定字符串s根据给定的行数line,以从上往下、从左到右进行Z字形排列
"""
输入:s="PAYPALISHIRING",line=4
输出:"PINALSIGYAHRPI"
输出:
P     I    N
A   L S  I G
Y A   H R
P     I
"""
# 巧设flag解决转向问题


def new_convert(line:int,str_list:list):
    new_str=["" for i in range(line)]
    flag=-1
    i=0
    
    for ch in str_list:
        new_str[i]+=ch
        if i==0 or i==line-1:
            flag*=-1
        i+=flag
    
    new_str="".join(new_str)        #返回拼接字符串(不包含Z型格式)
    return new_str


def output_convert(line:int,str_list:list):
    output_str=["" for i in range(line)]
    new_str=["" for i in range(line)]
    flag=-1
    i=0
    
    for ch in str_list:
        if flag==-1:
            for j in range(line):
                output_str[j]+=" "      #将每一列用空格隔开，实现视觉效果
        
        output_str[i]+=ch
        
        if flag==-1:
            if i!=0:
                for j in range(0,i):
                    output_str[j]+=" "      #将其余行变为" "进行填充 
                for j in range(i+1,line):
                    output_str[j]+=" "
        
        if i==line-1 or i==0:
            flag*=-1
        i+=flag

    return output_str       


str=input("请输入字符串")
line=input("请输入行数")
line=int(line)
new_str=new_convert(line,list(str))
output_str=output_convert(line,list(str))
print(new_str)      #输出拼接字符串(不包含Z型格式)
for i in range(line):
    print(output_str[i])        #按行将Z型结构输出