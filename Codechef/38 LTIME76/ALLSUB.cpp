#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
int main()
{
    ll t=sc;
    while(t--){
        bool we=1;
        string s, r;
        cin >> s >> r;
        vl C(26, 0);
        for(auto it:r){
            C[it - 'a']++;
        }
        string ans;
        for(auto it:s){
            if(C[it - 'a']){
                C[it - 'a']--;
                ans.pb(it);
            }
            else{
                we =0;
                break;
            }
        }
        bool dec = 0;
        for(auto it: ans){
            if(it!=ans[0]){
                if(it < ans[0]){
                    dec = 1;
                }
                break;
            }
        }
        // ca cd ccd ccccc
        // cout<<ans << dec <<'\n';
        string fans;
        f(i, 26){
            // cout << i << ' '<< fans <<'\n';
            if(i < ans[0] - 'a'){
                f(j,C[i])
                    fans.pb(i + 'a');
            }
            if( i == ans[0] - 'a'){
                if(dec){
                    fans += ans;
                    f(j,C[i])
                        fans.pb(i+'a');
                }
                else{
                    f(j,C[i])
                        fans.pb(i+'a');
                    fans += ans;
                }
            }
            if(i > ans[0] - 'a'){
                f(j,C[i])
                    fans.pb(i+'a');
            }
        }
        if(we)
            cout << fans <<'\n';
        else{
            cout<<"Impossible\n";
        }
    }
	return 0;
}