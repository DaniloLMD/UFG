def empadas(n):
    if n == 1:
        return 1
    elif n%2 == 0 :
        return 2 * empadas(n-1)
    return 2 * empadas(n-1) + 1

a = int(input())

print(empadas(a))