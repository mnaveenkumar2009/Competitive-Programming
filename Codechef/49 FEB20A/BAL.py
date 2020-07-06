n = 0
m = 0
N = 0

g = [[]]
gt = [[]]


used = []
order = []
comp = []
assignment = []

def dfs1(v):
    global order
    global used
    global g
    used[v] = True;
    for u in g[v]:
        if not used[u]:
            dfs1(u) 
    order.append(v);

def dfs2(v, cl):
    global comp
    global gt
    comp[v] = 1*cl
    for u in gt[v]:
        if (comp[u] == -1):
            dfs2(u, cl)

def solve_2SAT():
    global n
    global m
    global comp
    global order
    global used
    global assignment
    # print(g)
    n = m * 2;
    comp = [-1] * n
    order = []
    used = [False] * n
    assignment = [False] * int(n)

    for i in range(n):
        if not used[i]:
            dfs1(i)
    # print(order)
    j = 0
    for i in range(n):
        v = 1*order[n - i - 1]
        if (comp[v] == -1):
            dfs2(v, j);
            j += 1
    # print(comp)
    for i in range(0, n, 2):
        if (comp[i] == comp[i + 1]):
            return False
        assignment[i >>1] = False
        if comp[i] > comp[i + 1]:
            assignment[i>>1] = True
    # print(assignment)
    return True

def Add(u, v):
    # print(u, v)
    global g
    global gt
    if(N > 100):
        if (u^1) in g[v]:
            return
        if v in g[u^1]:
            return
    g[u].append(v);
    gt[v].append(u);
    g[v^1].append(u^1);
    gt[u^1].append(v^1);

def Rem(u, v):
    global g
    global gt
    # print(u, v)
    g[u].pop();
    gt[v].pop();
    g[v^1].pop();
    gt[u^1].pop();

t = int(input())
while(t > 0):
    t -= 1
    n, m = map(int, input().split())
    N = int(n)
    g = [[] for i in range(2*m)]
    gt = [[] for i in range(2*m)]
    A = [-1] * n
    P = [0] * m
    Q = [0] * m
    Add(0, 2 * m - 2);
    Add(1, 2 * m - 2);

    for i in range(m):
        u = -1
        v = -1
        X, Y = map(int, input().split())
        B = 1*A[X-1]
        C = 1*A[Y-1]
        if(B != -1 and C != -1):
            if(P[C] == Y):
                v = 2*C + 1
            else:
                v = 2*C
            if(P[B] == X):
                u = 2*B
            else:
                u = 2*B + 1
            Add(u, v)
            if(N <= 100):
                if(not solve_2SAT()):
                    Rem(u, v)
        else:
            u = 2*m - 2
            if(C != -1):
                if(P[C] == Y):
                    v = 2*C + 1
                else:
                    v = 2*C
            if(B != -1):
                if(P[B] == X):
                    v = 2*B + 1
                else:
                    v = 2*B;
            if(v != -1):
                Add(u, v)
                if(N <= 100):
                    if(not solve_2SAT()):
                        Rem(u, v)
        P[i] = 1*X;
        Q[i] = 1*Y;
        A[X - 1] = 1*i;
        A[Y - 1] = 1*i;
    solve_2SAT()
    for i in range(m):
        if(assignment[i]):
            print('^', end = '');
        else:
            print('v', end = '');

    print('')