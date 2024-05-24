x=0

for iteration in range (1, 201):
    xnew = (2*x**2+3)/5
    if(xnew == x):
        break
    x = xnew
    print(iteration, x)
    
print('Root: %0.5f' %xnew)
print('The number of iteration: %d' %iteration)