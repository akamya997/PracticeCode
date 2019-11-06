import concurrent.futures as cf
def calc(a):
    for i in range(10000000):
        a += 1
    return a
a = range(4)
#with cf.ProcessPoolExecutor() as executor:
#    ret = executor.map(calc,a)
for i in a:
    calc(i)
