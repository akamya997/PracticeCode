import os
def rename_func(path):
    for file in os.listdir(path):
        newname=''
        print(file)

if __name__ == '__main__':
    rename_func('./')
