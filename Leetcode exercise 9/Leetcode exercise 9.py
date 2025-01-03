"""
 1.七个不同的符号代表罗马数字，其值如下：
 I   1
 V	5
 X	10
 L	50
 C	100
 D	500
 M	1000

 罗马数字是通过添加从最高到最低的小数位值的转换而形成的
 将小数位值转换为罗马数字有以下规则:
 如果该值不是以4或9开头,请选择可以从输入中减去的最大值的符号,将该符号附加到结果,减去其值,然后将其余部分转换为罗马数字
 如果该值以4或9开头,使用减法形式,表示从以下符号中减去一个符号,例如4是5(V)减1(I):IV,9 是10(X)减1(I):IX,仅使用以下减法形式:4(IV),9(IX),40(XL),90(XC),400(CD)和900 (CM)
 只有10的次方(I,X,C,M)最多可以连续附加3次以代表10的倍数,不能多次附加5(V),50(L)或500(D),如果需要将符号附加4次,请使用减法形式
 给定一个整数，将其转换为罗马数字(注意:数字范围为1-3999)

 例子：
 输入:num=3749
 输出:"MMMDCCXLIX"
 解释:
 3000=MMM由于1000(M)+1000(M)+1000(M)
 700=DCC由于500(D)+100(C)+100 (C)
 40=XL由于50(L)减10(X)
 9=IX由于10(X)减1(I)
 注意:49不是50(L)减1(I)因为转换是基于小数位
"""


# 方法一：多种条件判断+贪心算法
class Solution:
    def intToRoman(self,num:int):
        roman_dict={"M":1000,"D":500,"C":100,"L":50,"X":10,"V":5,"I":1}     #创建罗马符号字典
        roman_str=""
        key_list=list(roman_dict.keys())
        num_list=[]      
        str_num=str(num)
        
        for i in range(len(str_num)):
            number=int(str_num[i])*10**(len(str_num)-1-i)
            if number!=0:
                num_list.append(number)     #将数字按千、百、十、个位分割
        
        for single_num in num_list:
            for i in range(len(key_list)):
                if single_num>=roman_dict[key_list[i]]:
                    if (str(single_num)[0]=='4'):       #处理4
                        roman_str+=key_list[i]
                        roman_str+=key_list[i-1]
                        single_num-=roman_dict[key_list[i-1]]
                        single_num+=roman_dict[key_list[i]]
                    elif (str(single_num)[0]=='9'):     #处理9
                        roman_str+=key_list[i+1]
                        roman_str+=key_list[i-1]
                        single_num-=roman_dict[key_list[i-1]]
                        single_num+=roman_dict[key_list[i+1]]
                    else:
                        for j in range(single_num//roman_dict[key_list[i]]):
                            roman_str+=key_list[i]
                            single_num-=roman_dict[key_list[i]]
        
        return roman_str
                                                                        
solution=Solution()
num=input("请输入1-3999的数字")
str=solution.intToRoman(int(num))
print(str)


# 方法二：构建新词典+贪心算法(较方法一的速度有明显改进)
class Solution:
    def intToRoman(self,num:int):
        roman_dict={"M":1000,"CM":900,"D":500,"CD":400,"C":100,"XC":90,"L":50,"XL":40,"X":10,"IX":9,"V":5,"IV":4,"I":1}
        key_list=list(roman_dict.keys())
        roman_str=""
        for key in key_list:
            if num>=roman_dict[key]:
                for i in range(num//roman_dict[key]):
                    roman_str+=key
                    num-=roman_dict[key]
        return roman_str
    
    
solution=Solution()
num=input("请输入数字")
roman_str=solution.intToRoman(int(num))
print(roman_str)