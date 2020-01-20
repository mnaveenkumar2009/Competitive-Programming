#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
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

ll por[100007];
ll N, ssiz;
string s;
int dp[1005][1005];

bool f2(ll pos, ll rem){
    int ans = 0;
    if(dp[pos][rem] != -1)
        return dp[pos][rem];
    if(s[pos] != '?'){
        if(pos == ssiz - 1){
            return dp[pos][rem] = (rem==0);
        }
        return dp[pos][rem] = f2(pos + 1, rem);
    }
    if(pos == ssiz-1){
        for(ll i = 0; i < 10; i++){
            ans = max( (int)((rem +  i)%N==0), ans);
        }
        return dp[pos][rem] = ans;
    }
    for(ll i = 0; i < 10; i++){
        ans = max((int)f2(pos+1, (rem + (i * por[ssiz-1-pos]))%N), ans);
    }
    return dp[pos][rem] = ans;
}
int main()
{
    ll i,j, cur_mod = 0;
    f(i,1005)f(j,1005)dp[i][j] =-1;
    cin>>s;
    ssiz = s.length();
    cin>>N;
    por[0] = 1;
    f(i,10000){
        por[i+1] = (por[i]*10)%N;
    }
    f(i, ssiz){
        if(s[i] != '?'){
            s[i] -= '0';
            cur_mod = ( cur_mod + (s[i] * por[ssiz-1-i] ))%N;
        }
    }
    
    bool we=1;
    f(i, ssiz){
        if(s[i] != '?')continue;
        f(j, 10){
            if(i == 0 && j==0)continue;
            ll new_mod = (cur_mod + (j*por[ssiz-i-1])%N)%N;
            if(i==ssiz -1){
                if((cur_mod + j) % N == 0){
                    s[i] = j;
                    break;
                }
                continue;
            }
            if(f2(i + 1, new_mod)){
                s[i] = j;
                cur_mod = new_mod;
                break;
            }
            
        }
        if(j==10){
            we =0;break;
        }
    }
    
    f(i,ssiz){
        s[i] += '0';
    }
    if(we)
        cout<<s<<'\n';
    else{
        cout<<"*\n";
    }
	return 0;
}