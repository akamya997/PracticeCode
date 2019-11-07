m, n = input(), input()
l, r = 0, 1
while r ** m < n:
    r *= 2
 
while(l + 1 < r):
    md = (l + r) >> 1
    if(md ** m <= n):
        l = md
    else:
        r = md
 
if(r **m <= n):
    l = r
 
print(l)
