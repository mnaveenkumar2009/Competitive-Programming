#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int count = 0;
    while((1 << count) < n){
        int *p, *q;
        int block_size = (1 << (count+1)), number_of_blocks = ceil(n * 1.0 / block_size);
        int j = 0, b[n];
        for(int i = 0; i < number_of_blocks; i++){
            p = a + i * block_size;
            q = p + block_size/2;
            int *p_end = q,*q_end = min(p + block_size, a + n);
            if(q > q_end)
                break;
            while( p!=p_end && q!=q_end ){
                if(*p > *q)
                    b[j++] = *q++;
                else
                    b[j++] = *p++;
            }
            while(p != p_end)
                b[j++] = *p++;
            while(q != q_end)
                b[j++] = *q++;
        }
        memcpy(a, b, sizeof(b));
        count++;
    }

    for(int i = 0; i<n; i++)
        cout<<a[i]<<' ';
    cout<<'\n';
}