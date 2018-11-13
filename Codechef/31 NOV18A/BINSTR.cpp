#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)

inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
#define sc uscan()

#define vl vector <ll> 
#define vvl vector <vector <ll> >

ll xxx[50][100005];
bool stringcheck(pair <string,ll> a ,pair <string,ll> b){
    if(a.ff.length()==b.ff.length()){
        return a<b;
    }
    return a.ff.length()<b.ff.length();
}

bool ispo2min1(ll n){
    n++;
    return ((1LL<<(ll)log2(n))==n);
}
string s[100005],str[100005];
vector <pair <string,ll> > tree[200005];
ll n,q;
ll query(vector <pair <string,ll> > &elements,string s){
    ll siz=elements.size(),fir=log2(s.length()),rank=xxx[fir][elements[siz-1].ss], low =0,high=siz-1, slen =s.length();
    
    while(low!=high){
        ll mid=(low+high)/2;
        if(xxx[fir][elements[mid].ss]!=rank){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    high=siz-1;
    
    ll curpos=0;
    while(low!=high){
        ll low2=low,high2=high+1;
        bool we1=0,we2=0;
        if(elements[low2].ff.length()>=slen-curpos){
            if(elements[low2].ff[curpos-(slen-elements[low2].ff.length())]=='1'){
                we1=1;
            }
        }
        if(elements[high].ff.length()>=slen-curpos){
            if(elements[high].ff[curpos-(slen-elements[high].ff.length())]=='1'){
                we2=1;
            }
        }
        if(we1!=we2){
            while(low2!=high2){
                ll mid=(low2+high2)/2;
                if(elements[mid].ff.length()>=slen-curpos){
                    if(elements[mid].ff[curpos-(slen-elements[mid].ff.length())]=='1'){
                        high2=mid;
                    }
                    else{
                        low2=mid+1;
                    }
                }
                else{
                    low2=mid+1;                
                }
            }
            if(s[curpos]=='0'){
                low=low2;
            }
            else{
                high=low2-1;
            }
            
        }
        curpos++;
    }
    return elements[low].ss;
}

ll query(ll l,ll r,string s){
    ll ans;
    vector < ll > possible_indices;    
    l+=n;
    r+=n;
    while(l<r){
        // cout<<l<<' '<<r<<'\n';
        if(l&1){
            possible_indices.pb(query(tree[l],s));
            l++;
        }
        if(r&1){
            possible_indices.pb(query(tree[r-1],s));
            r--;
        }
        l/=2;
        r/=2;
    }
    
    ll newlength=s.length();
    ll sizofpossible=possible_indices.size();
    ll fir=log2(newlength);
    ll maxr=0,i,j;
    f(j,sizofpossible){
        maxr=max(maxr,xxx[fir][possible_indices[j]]);
    }
    vector <ll> newposs;
    f(i,sizofpossible){
        if(maxr==xxx[fir][possible_indices[i]]){
            newposs.pb(possible_indices[i]);
        }
    }
    sizofpossible=newposs.size();
    possible_indices=newposs;
    
    ll slen=s.length();
    string maxi;
    ans=1e8;
    for(auto it:possible_indices){
        ll strl=str[it].length();
        ll noi=min(slen,strl);
        string news=s;
        // cout<<str[it]<<'\n';
        for(ll i=0;i<noi;i++){
            if(str[it][strl-i-1]=='1'){
                if(news[slen-i-1]=='0'){
                    news[slen-i-1]='1';
                }
                else
                    news[slen-i-1]='0';
            }
        }
        // maxi=max(maxi,news);
        if(news>maxi){
            maxi=news;
            ans=it;
        }
        if(news==maxi)ans=min(ans,it);
    }
    
    return ans;
}
int main(){
    n=sc,q=sc;
    ll i,j,k;
    
    f(i,n){
        cin>>s[i];
        str[i]=s[i];
        ll nn=s[i].length(),curpos,n0s=0;

        f(curpos,nn){
            if(s[i][curpos]=='1')
                break;
            n0s++;
        }
        string news;
        for(ll ii=curpos;ii<nn;ii++){
            news.pb(s[i][ii]);
        }
        s[i]=news;
    }
    
    f(i,n){
        tree[n+i].pb(mp(s[i],i));
    }
    // return 0;
    ll posi;
    for(posi=n-1;posi>0;posi--){
        i=j=k=0;
        ll t1=posi<<1,t2=(posi<<1)|1;

        ll n1=tree[t1].size(),n2=tree[t2].size();
        // if(posi==3){
        //     cout<<tree[t1][0].ss<<' '<<tree[t2][0].ss<<'\n';
        // }
        while (i<n1 && j <n2)
        {
            // cout<<posi<<i<<j<<'\n';
            if (stringcheck(tree[t1][i],tree[t2][j]))
            {
                if(k)
                {   
                    if(tree[t1][i].ff!=tree[posi][k-1].ff){
                        tree[posi].pb(tree[t1][i]);
                        k++;
                    }
                    else{
                        tree[posi][k-1].ss=min(tree[posi][k-1].ss,tree[t1][i].ss);
                    }
                }
                else{
                        tree[posi].pb(tree[t1][i]);
                        k++;

                }
                i++;
            }
            else{
                if(k)
                {   
                    if(tree[t2][j].ff!=tree[posi][k-1].ff){
                        tree[posi].pb(tree[t2][j]);
                        k++;
                    }
                    else{
                        tree[posi][k-1].ss=min(tree[posi][k-1].ss,tree[t2][j].ss);
                    }
                }
                else{
                        tree[posi].pb(tree[t2][j]);
                        k++;

                }
                j++;
            }
        } 
        // cout<<i<<' '<<j<<k<<'\n';
        // Store remaining elements of first array 
        while (i < n1){
                if(k)
                {   
                    if(tree[t1][i].ff!=tree[posi][k-1].ff){
                        tree[posi].pb(tree[t1][i]);
                        k++;
                    }
                    else{
                        // cout<<'v';
                        tree[posi][k-1].ss=min(tree[posi][k-1].ss,tree[t1][i].ss);
                    }
                }
                else{
                        tree[posi].pb(tree[t1][i]);
                        k++;

                }
                i++;}
    
        // Store remaining elements of second array 
        while (j < n2) 
                {if(k)
                {   
                    if(tree[t2][j].ff!=tree[posi][k-1].ff){
                        tree[posi].pb(tree[t2][j]);
                        k++;
                    }
                    else{
                        tree[posi][k-1].ss=min(tree[posi][k-1].ss,tree[t2][j].ss);
                    }
                }
                else{
                        tree[posi].pb(tree[t2][j]);
                        k++;

                }
                j++;}
        //         cout<<posi<<'\n';
        // for(auto it:tree[posi]){
        //     cout<<it.ff<<' '<<it.ss<<' ';
        // }
        // cout<<'\n';
    }
    // return 0;
    ll bitt;
    f(bitt,50){
        // remove (1<<i) from back
        f(i,n){
            if(s[i].length())break;
        }
        if(i==n)break;
        f(i,n){
            ll cou=(1LL<<bitt);
            if(cou>=s[i].length()){
                s[i]="";
            }
            else{
                while(cou--){
                    s[i].pop_back();
                }
            }
        }
        vector <pair <string,ll> > a(n);
        f(i,n){
            a[i].ff=s[i];
            a[i].ss=i;
        }
        sort(a.begin(),a.end(),stringcheck);
        ll rank=0;
        xxx[bitt][a[0].ss]=++rank;
        for(i=1;i<n;i++){
            if(a[i].ff!=a[i-1].ff)
                xxx[bitt][a[i].ss]=++rank;
            else
                xxx[bitt][a[i].ss]=rank;            
        }
    }
    
    while(q--){
        
        ll l=sc-1,r=sc;
        string squery;
        cin>>squery;
        string initial0;
        while(!ispo2min1(initial0.length()+squery.length())){
            initial0.pb('0');
        }
        squery=initial0+squery;
        cout<<query(l,r,squery)+1<<'\n'; // [l,r)
    }

}