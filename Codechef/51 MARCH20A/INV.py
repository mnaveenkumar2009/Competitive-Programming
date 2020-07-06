from math import sqrt, gcd

def ExtendedGCD(a, b):
    a2, a1 = 1, 0
    b2, b1 = 0, 1
    while b:
        q, r = divmod(a, b)
        a1, a2 = a2 - q * a1, a1
        b1, b2 = b2 - q * b1, b1
        a, b = b, r
    return a, a2, b2

def ModularInverse(b, n):
    b = int(b)
    n = int(n)
    g, x, _ = ExtendedGCD(b, n)
    if g == 1:
        return x % n
def phi(n):
    result = n
    i = 2;
    while(i * i <= n):
        if(n % i == 0):
            while(n % i == 0):
                n /= i
            result -= result / i
        i += 1
    if n > 1:
        result -= result / n
    return result

def solve(a, b, m):
    phim = phi(m)
    ret = 1e9
    a %= m
    if b == 1:
        return 0
    if a == 0:
        if b == 0:
            return 1
        else:
            return -1
    if gcd(a, m) != 1:
        return -1
    n = int(sqrt(m) + 1)
    an = 1
    for i in range(n):
        an = (an * a) % m
        if an == b:
            return i + 1
    vals = {}
    p = 1
    cur = an
    while(p <= n):
        if not (cur in vals):
            vals[cur] = p;
        cur = (cur * an) % m;
        p += 1
    q = 0
    cur = b
    while(q <= n):
        if (cur in vals):
            ans = vals[cur] * n - q
            ret = int(min(ret, ans % phim))
        cur = (cur * a) % m;
        q += 1
    if ret == 1e9:
        ret = -1
    else:
        for i in range(2, n):
            if m % i == 0:
                t1 = int(ret % i);
                if pow(a, t1, m) == b:
                    ret = t1
                t2 = int(ret % (m/i))
                if pow(a, t2, m) == b:
                    ret = t2
    return ret;

modu = 998244353

t = int(input())
while t > 0:
    n, x, m = map(int, input().split())
    if x == 1 or m == 1:
        print(0)
        t -= 1
        continue
    if x == 0:
        if n != 1:
            print(1)
        else:
            print(-1)
        t -= 1
        continue
    p2min1 = (n - 1) % (modu - 1)
    p2min1 = pow(2, p2min1, modu)
    plusone = 0
    z = (pow(2, n, m) - 1 + m) % m
    ZZ = z
    MM = m
    XX = x
    if z == 0:
        print(-1)
        t -= 1
        continue
    we = False
    # print(z, x, m)
    gc = gcd(z, m)
    while gc != 1:
        if x % gc != 0:
            we = True
            break
        else:
            x /= gc
            m /= gc
            x *= ModularInverse(z/gc, m);
            x %= m
            z %= m
            m = int(m)
            x = int(x)
            z = int(z)
            plusone += 1
            # print(z, x, m)
        gc = gcd(z, m)
        if z == 0 or x == 1:
            break
    if we:
        print(-1)
        t -= 1
        continue
    # z >= 1, z < m, x >= 1
    # print(z, x, m)
    y = solve(z, x, m)
    # print(z, x, m)
    # print(plusone)
    # print(y)
    if y == -1:
        print(-1)
    else:
        y += plusone
        if plusone > 0:
            assert(pow(ZZ, y, MM) == XX)
        y = (p2min1 * (pow(2, y, modu) - 1 + modu)) % modu
        print(y)
    t -= 1