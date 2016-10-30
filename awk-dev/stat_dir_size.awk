#!/usr/bin/awk -f  
#命名:      file_tot.awk  
#功能：     计算当前文件夹中文件大小和  
#使用方法:  ls -l | ./file_tot.awk  
  
#print a header first  
BEGIN{  
    print"this is the size of all files"  
    print"fileName\t\tfilesize"  
    print"----------------------------------"  
}  
  
#let's add the size of file  
(tot+=$5) {printf "%-24s%d\n",$9,tot}   #根据打印的头长度来判断左对齐空格长度  
  
#finished print an end  
END{  
    printf "\n"  
    print "the total is : " tot  
    print"------------the end!------------"  
}  
