#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, c, q;
    cin >> n >> c >> q;
    ll blockSize = min((ll)sqrt(n) + 1LL, n);
    ll nob = n / blockSize;
    if(n % blockSize)
        nob++;
    ll col[n] = {0};
    ll Fc[c][nob], Qc[c][nob];
    ll Q[nob], C[nob] = {0}, Qp[n];
    for(ll i = 0; i < n; i++)
        Qp[i] = -1;
    for(ll i = 0; i < c; i++){
        for(ll j = 0; j < nob; j++){
            Q[j] = -1;
            Qc[i][j] = -1;
            Fc[i][j] = 0;
            if(!i){
                Fc[i][j] = blockSize;
                if(j == nob-1 && n % blockSize)
                    Fc[i][j] = n % blockSize;
            }
        }
    }
    // cout<<blockSize<<'\n';
    for(int query_no = 0; query_no < q; query_no++){
        ll P, X, A, B, S = 0;
        cin >> P >> X >> A >> B;
        P--;X--;
        for(int blok = 0; blok < nob; blok++){
            if(Qc[P][blok] < Q[blok]){
                Fc[P][blok] = 0;
                Qc[P][blok] = query_no;
            }
            S += Fc[P][blok];
        }
        // cout << "S: " << S << '\n';
        ll M1 = (A + S * S) % n;
        ll M2 = (A + (S + B) * (S + B)) % n;
        if(M1 > M2)
            swap(M1, M2);
        // cout<<"Ranges: "<< M1<<' '<<M2<<'\n';
        for(int blok = (M1 / blockSize) + ((M1 % blockSize) != 0); blok < (M2 / blockSize) + (((M2 + 1) % blockSize) == 0); blok++){
            // blok becomes X
            Fc[C[blok]][blok] = 0;
            Qc[C[blok]][blok] = query_no;
            Fc[X][blok] = ((blok == nob - 1) && (n % blockSize)) ? n % blockSize : blockSize;
            Qc[X][blok] = query_no;
            Q[blok] = query_no;
            C[blok] = X;
        }
        int lBlock = M1 / blockSize, rBlock = M2 / blockSize;
        while((M1 % blockSize) && M1 != n){
            if(Qc[X][lBlock] < Q[lBlock])
                Fc[X][lBlock] = 0;
            Qc[X][lBlock] = query_no;
            int prevCol = col[M1];
            if(Qp[M1] < Q[lBlock]){
                if(Qc[prevCol][lBlock] < Q[lBlock])
                    Fc[prevCol][lBlock] = 0;
                Qc[prevCol][lBlock] = query_no;
                prevCol = C[lBlock];
            }
            Fc[prevCol][lBlock]--;
            Qc[prevCol][lBlock] = query_no;
            Qp[M1] = query_no;
            col[M1] = X;
            Fc[X][lBlock]++;
            M1++;
        }
        while((M2+1) % blockSize){
            if(Qc[X][rBlock] < Q[rBlock]){
                Fc[X][rBlock] = 0;
            }
            Qc[X][rBlock] = query_no;
            int prevCol = col[M2];
            if(Qp[M2] < Q[rBlock]){
                if(Qc[prevCol][rBlock] < Q[rBlock])
                    Fc[prevCol][rBlock] = 0;
                Qc[prevCol][rBlock] = query_no;
                prevCol = C[rBlock];
            }
            Fc[prevCol][rBlock]--;
            Qc[prevCol][lBlock] = query_no;
            Qp[M2] = query_no;
            col[M2] = X;
            Fc[X][rBlock]++;
            M2--;
        }
    }
    // for(int i = 0; i < nob; i++){
    //     cout<<Q[i]<<' ';
    // }cout<<'\n';
    // cout<<"Ans\n";
    int fans = 0;
    for(int P = 0; P < c; P++){
        int S = 0;
        for(int blok = 0; blok < nob; blok++){
            if(Qc[P][blok] < Q[blok])
                Fc[P][blok] = 0;
            S += Fc[P][blok];
        }
        // cout<<S<<'\n';
        fans = max(fans, S);
    }
    cout << fans << '\n';
}