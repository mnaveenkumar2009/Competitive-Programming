#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 1;
    vector <long long> sizes(1, 1);
    char s[500006];
    sprintf(s + strlen(s),"1");
    while(n++!=25000){
        sizes.push_back(sizes[sizes.size()-1] + log10(n) + 1);
        sprintf(s + strlen(s), "%d",n);
    }
    n--;
    for(int i = 0; i < n - 1; i++)
        sizes[i + 1] += sizes[i];
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        k--;
        int pos = lower_bound(sizes.begin(), sizes.end(), k) - sizes.begin();
        if(sizes[pos] > k)
            pos--;
        if(pos >= 0)
            k -= sizes[pos];
        cout<<s[k]<<'\n';
    }
}