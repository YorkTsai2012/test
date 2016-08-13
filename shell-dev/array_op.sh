#!/bin/bash


#数组赋值：

#(1) array=(var1 var2 var3 ... varN)

#(2) array=([0]=var1 [1]=var2 [2]=var3 ... [n]=varN)

#(3) array[0]=var1

#    arrya[1]=var2

#    array[n]=varN


#计算数组元素个数：

#${#array[@]}  或者  ${#array[*]}

  
#关联数组 
#declare -A phone 
#phone=([jim]=135 [tom]=136 [lucy]=158) 

phone=("123" "456" "789")

# 打印所有下标
echo ${!phone[@]}

# 打印所有元素
echo ${phone[@]}

#追加数据
phone+=("15618897435")
phone+=("15996310080")

# 按照下标遍历数组
for key in ${!phone[*]} 
do 
    echo "$key -> ${phone[$key]}" 
done

# 只遍历数据元素
for key in ${phone[@]}
do
	echo $key
done
