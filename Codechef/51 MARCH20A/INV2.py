import math
modu = 998244353

t = int(input())
while t > 0:
    n, x, m = map(int, input().split())
    p2min1 = pow(2, n - 1, modu)
    z = (pow(2, n, m) - 1 + m) % m
    if m == 1:
        print(0)
        t -= 1
        continue
    if x == 1:
        print(0)
        t -= 1
        continue
    if x == 0 and n != 1:
        print(1)
        t -= 1
        continue
    we = False
    for y in range(1, m):
        if pow(z, y, m) == x:
            y = (p2min1 * (pow(2, y, modu) - 1 + modu)) % modu
            we = True
            assert(y >= 0)
            print(y)
            break;
    if not we:
        print(-1)
    t -= 1