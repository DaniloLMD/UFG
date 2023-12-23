import math

h, c, l = [float(a) for a in input().split()]

d1 = math.sqrt(((l+2*h)*(l+2*h) + c * c))
d2 = math.sqrt(l*l + (c+2*h)*(c+2*h))
d3 = math.sqrt((c+h) * (c+h) + (l+h)*(l+h))


d = min(d1, d2, d3)
print(f"{d:.{4}f}")