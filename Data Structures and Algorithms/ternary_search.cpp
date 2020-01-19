#include <bits/stdc++.h>
using namespace std;
#define ld long double
ld epsilon = 0.000001;

ld P(ld p){
    return 55 * log(p) + 45 * log(1 - p); // function with maxima
}

int main(){
    ld low = epsilon, high = 1 - epsilon;
    while(high - low > epsilon){
        ld diff = high - low;
        ld mid1 = low + 0.33 * diff;
        ld mid2 = low + 0.66 * diff;
        if(P(mid1) > P(mid2))
            high = mid2;
        else
            low = mid1;
    }
    printf("%Lf\n",low);
}