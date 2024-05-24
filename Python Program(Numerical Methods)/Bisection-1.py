a = 0
b = 1.2
f_a = 2*a**2*a-6
f_b = 2*b**2*b-6

if f_a*f_b > a:
    print('No roots exist within the given interval')
    exit
for i in range(1,101):
    c = (a+b)/2
    f_c = 2*c**2-5*c+3
    f_a = 2*a**2-5*a+3
    if abs(f_a) < 1.0e-6:
        break
    elif f_a*f_c < 0:
        b = c
    else:
        a = c
    print(i,c)
     
print('The root: %.5f' %c)
print('Number of iteration; %d' % i)
