import concurrent.futures as cf
def calc(a):
    return a**2

if __name__ == '__main__':
    a = range(10000000)
    
    with cf.ProcessPoolExecutor() as e:
        future = e.map(calc, a)
        #for f in future:
         #   print(f)
    
    #for i in a:
    #    calc(i)
