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
inline ll uscan()     
{     
    ll n=0,c=gc();    
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9'){
        c=gc();
        if(c=='-')check=1;     
    }     
    while(c<='9'&&c>='0'){     
        n=n*10+c-'0';     
        c=gc();
    }     
    return n+(-2*check*n);
 
}     
int main(){ 
    ll t=uscan(),i,j;     
    while(t--){     
        ll n=uscan(),c=uscan();
        vector <ll> a(n,0);
        bool abcd=1;
        f(i,100000){
            ll cc=c;     
            if(cc%(i+1)==0){            
                
                f(j,n)a[j]=0;
                bool check=true;
                a[n-1]=(n-1)+(i+1);
                cc/=(i+1);
                j=n-2;
                while(j>=0){
                    if(cc==1)break;
                    a[j]=a[j+1];
                    while(cc%(a[j]-j)){
                        a[j]--;
                        if(a[j]<=j+1){
                            check=false;
                            break;
                        }
                    }
                    if(!check)break;
                    cc/=(a[j]-j);
                    j--;
                }
                if(check&&cc==1){
                    abcd=0;
                    break;
                }
            }     
        } 
        if(abcd){
            f(i,n)a[i]=i+1;
            multiset <ll> prime;
            multiset <ll>::iterator it;
            for (i = 2; i <= sqrt(c); i ++){     
                while (c%i == 0){
                    prime.insert(i);
                    c = c/i;               
                }            
            }     
            if (c > 2)     
                prime.insert(c);     
            while(prime.size()>n){     
                it=prime.begin();     
                ll temp=*it;     
                it++;     
                temp*=(*it);     
                prime.insert(temp);     
                prime.erase(prime.begin());     
                prime.erase(prime.begin());     
            }     
            i=n-1;     
            multiset<ll>::reverse_iterator rit;     
            for (rit=prime.rbegin(); rit!=prime.rend(); ++rit){
                a[i--]+=(*rit)-1;
            }
            if(n>2)
                if(a[n-1]-a[n-3]==4){
                    a[n-1]-=2;
                    a[n-2]++;
                    a[n-3]+=2;
                }
            if(a[n-1]-a[n-2]==2){
                a[n-1]--;
                a[n-2]++;
            }     
        }     
        f(i,n){     
            if(!a[i])a[i]=i+1;     
        }     
        f(i,n)     
            printf("%lld ",a[i]);     
            putchar('\n');     
    }
} 