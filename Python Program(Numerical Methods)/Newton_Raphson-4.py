import math
x =2
for iteration in range(1, 201):
    a = (5*x-3)/2
    xnew = math.sqrt(a)
    if(xnew == x):
        break
    x = xnew
    print(iteration, x)

print('Root: %0.5f' %xnew)
print('The number of iteration: %d' %iteration)