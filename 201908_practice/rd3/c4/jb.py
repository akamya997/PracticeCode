import os
import re
path='/home/compute/acm//201908_practice/rd3/c4/04-5$linux/tests/'

#获取该目录下所有文件，存入列表中
fileList=os.listdir(path)

print(fileList)
n=0
for i in fileList:
    oldname=path+ os.sep + fileList[n]   # os.sep添加系统分隔符
    newname=''
    if i.find(".a")!=-1:
        tmp=i
        tmp=tmp.replace('.a','');
        newname=path +os.sep+'p4.t'+tmp+'.out'
    #设置旧文件名（就是路径+文件名）
    #设置新文件名
    else:
        newname=path+ os.sep +'p4.t'+i+'.in'
    
    os.rename(oldname,newname)   #用os模块中的rename方法对文件改名
    print(oldname,'======>',newname)
    n+=1
