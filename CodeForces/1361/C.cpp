#include <bits/stdc++.h>
using namespace std;

#define MMM 10
set <int> A[1 << MMM];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    if(n == 1){
        cout << "20\n2 1\n";
        return 0;
    }
    for(int k = MMM; k >= 0; k--){
        int MASK = (1 << k) - 1;
        for(int i = 0; i < MASK; i++)
            A[i].clear();
        int val[2*n];
        for(int i = 0; i < n; i++){
            a[i] = a[i] & MASK;
            b[i] = b[i] & MASK;
            A[a[i]].insert(2*i);
            A[b[i]].insert(2*i + 1);
            val[2*i] = a[i];
            val[2*i + 1] = b[i];
        }
        vector <int> nex(2 * n, -1);
        vector <bool> vis(2 * n, 0);
        bool we = 1;
        nex[0] = 1;
        int cur = 1;
        A[b[0]].erase(1);
        bool xxx = 1;
        while(xxx){
            xxx = 0;
            // cout << xxx << '\n';
            while(nex[cur] == -1){
                if(A[val[cur]].size() == 0){
                    we = 0;
                    break;
                }
                else{
                    int j = *(A[val[cur]].begin());
                    A[val[cur]].erase(A[val[cur]].begin());
                    nex[cur] = j;
                    nex[j] = j^1;
                    cur = j^1;
                    A[val[cur]].erase(j^1);
                }
            }
            if(!we)break;
            int i = 1;
            while(nex[i] != 1){
                if(nex[i] == (i ^ 1)){
                i = nex[i];continue;}
                if(A[val[i]].size() >= 1){
                    // cout << i << ' ' << *(A[val[i]].begin()) << ' ' << nex[i] << '\n';
                    int j = *(A[val[i]].begin());
                    A[val[i]].erase(A[val[i]].begin());
                    A[val[nex[i]]].insert(nex[i]);

                    nex[i] = j;
                    nex[j] = j^1;
                    cur = j^1;
                    A[val[cur]].erase(j^1);
                    xxx = 1;
                    break;
                }

                i = nex[i];
            }
        }
        if(we){
            cout << k << '\n' << "1 ";
            int i = 0;
            for(int i = 0; i < n; i++){

            }
            while(nex[i] != 0){
                cout << nex[i] + 1 << ' ';
                i = nex[i];
            }
            cout << '\n';
            break;
        }
    }

}