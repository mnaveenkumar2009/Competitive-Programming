pi=3.1415926535897932384626433832795028841971693993751
step=0.000001
R=5
def fn():
    v=0
    r=0
    while(r<=2):
        a=pi*((R+r)*(R+r)-(R-r)*(R-r))
        v+=(a)*step*pi/2.0
        r+=step
    return 2*v
print(fn())
