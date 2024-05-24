x = [5, 7, 11, 14]
y = [450, 892, 1752, 2266]
m = len(x)
n = m-1
xp = float(input("Enter x: "))
yp = 0

for i in range(n+1):
    L=1
    for j in range(n+1):
        if j != i:
            L *= (xp-x[j])/(x[i]-x[j])
            yp += y[i]*L
            
print("For x = %.1f, y = %.1f" %(xp, yp))