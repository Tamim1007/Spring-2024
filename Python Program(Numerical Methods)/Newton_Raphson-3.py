x = 2

for iteration in range (1, 101):
    print(iteration, x)
    xnew = x-(2*x**2-5*x+3)/(4*x-5)
    if x == xnew:
        break
    x = xnew
    
print('The Root: %0.5f' %xnew)
print('Number of iteration: %d' %iteration)


