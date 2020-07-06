
import math
def solve(g, h, p):
    N = int(math.ceil(math.sqrt(p - 1)))
    t = {}
    # Baby step.
    for i in range(N):
        t[pow(g, i, p)]=i

    # Fermat’s Little Theorem
    c = pow(g, N * (p - 2), p)
     
    for j in range(N):
        y = (h * pow(c, j, p)) % p
        if y in t: 
            return j * N + t[y]
    return -2