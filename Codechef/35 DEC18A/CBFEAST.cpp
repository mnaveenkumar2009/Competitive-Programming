#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
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
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}

#define MAXNUM 200000

// #define block_size 1

#ifndef block_size
    #define block_size 400
#endif

const ll number_of_blocks_half=ceil((ld)MAXNUM/(ld)block_size);
const ll number_of_blocks=number_of_blocks_half<<1;

#define thisproblemisapain(a,b,c,d,e) mp(a,mp(mp(b,c),mp(d,e)))
#define pllllll pair <ll,pair <pair <ll,ll> ,pair <ll,ll> > >


int main()
{
    ll q=sc,k=sc;

    ll ans=0;
    vector <pllllll > maxans[number_of_blocks];
    pair <ll,ll> a[number_of_blocks*block_size]={mp(-1,0)};
    ll l=number_of_blocks_half*block_size;
    ll r=l-1;

    while(q--){
        ll b=sc,C=sc;
        ll c=C^ans;
        if(b!=3){
            ll d=sc;
            ll block_num=-1;
            if(b==1){
                l--;
                a[l].ss=d;
                a[l].ff=c;                
                if(((l+1)%block_size)==0&&l+1!=number_of_blocks_half*block_size){
                    block_num=(l+1)/block_size;
                }
            }
            else{
                r++;
                a[r].ss=d;
                a[r].ff=c;
                if(r%block_size==0&&r!=number_of_blocks_half*block_size){
                    block_num=(r-1)/block_size;
                }
            }
            if(block_num!=-1){
                // O(block_size^2 + block_size*log(block_size))
                ll star=block_num*block_size;
                ll en=star+block_size-1;
                ll maxim=0,minim=INT_MAX;
                for(ll ii=0;ii<(block_size*2);ii++){
                    
                    maxim=max(maxim,a[star+(ii/2)].ff);
                    minim=min(minim,a[star+(ii/2)].ff);
                    
                    ll valid_c=a[star+ii/2].ff-k;
                    if(ii%2)
                        valid_c+=(k<<1)+1;
                    // if(ii%3==2){
                    //     valid_c++;
                    // }
                    ll MA=0,ML=0,MR=0;
                    ll ml=0,mr=0,bs=0,ma=0;
                    for(ll i=star;i<=en;i++){
                        if(a[i].ff<=valid_c+k&&a[i].ff>=valid_c-k){
                            bs+=a[i].ss;
                            if(i-star){
                                MA=a[i].ss+max(MA,0);
                                ML=ML+a[i].ss;
                            }
                            else{
                                MA=max(0,a[i].ss);
                                ML=a[i].ss;
                            }
                        }
                        ma=max(ma,MA);
                        ml=max(ml,ML);
                        mr=min(mr,ML);
                    }
                    mr=bs-mr;
                    mr=max(mr,bs);
                    maxans[block_num].pb(thisproblemisapain(valid_c,ml,mr,bs,ma));
                }
                maxans[block_num].pb(thisproblemisapain(maxim+1+k,0,0,0,0));
                maxans[block_num].pb(thisproblemisapain(minim-1-k,0,0,0,0));
                maxans[block_num].pb(thisproblemisapain(INT_MAX,0,0,0,0));
                maxans[block_num].pb(thisproblemisapain(-INT_MAX,0,0,0,0));
                sort1(maxans[block_num]);
            }
        }
        else{
            // query
            ans=0;
            ll dp=0;
            ll cur_block=l/block_size;
            ll start_block=cur_block;
            ll last_block=r/block_size;

            // fill dp[curblock]
            ll MA1=0,ML1=0;
            ll mr1=0,bs1=0;
            ll star1=l,en1=block_size*(cur_block+1)-1;
            // cout<<star1<<' '<<en1<<'\n';
            for(ll i=star1;i<=en1;i++){
                if(a[i].ff<=c+k&&a[i].ff>=c-k){
                    bs1+=a[i].ss;
                    if(i-star1){
                        MA1=a[i].ss+max(MA1,0);
                        ML1=ML1+a[i].ss;
                    }
                    else{
                        MA1=max(0,a[i].ss);
                        ML1=a[i].ss;
                    }
                    ans=max(ans,MA1);
                    mr1=min(mr1,ML1);
                }
            }
            mr1=bs1-mr1;
            mr1=max(mr1,bs1);
            dp=mr1;
            pllllll search_dummy=thisproblemisapain(c,-1,-1,-1,-1);
            for(cur_block++;cur_block<last_block;cur_block++){
                ll bs=-INT_MAX,mr=0,ml=0;
                // search <=c

                ll tem=lower_bound(maxans[cur_block].begin(),maxans[cur_block].end(),search_dummy)-maxans[cur_block].begin();
                if(tem==(ll)maxans[cur_block].size()){
                    tem--;
                }                
                if(maxans[cur_block][tem].ff>c&&tem){
                    tem--;
                }
                ans=max(maxans[cur_block][tem].ss.ss.ss,ans);
                bs=maxans[cur_block][tem].ss.ss.ff;
                mr=max(mr,maxans[cur_block][tem].ss.ff.ss);
                ml=max(ml,maxans[cur_block][tem].ss.ff.ff);
                
                ans=max(ans,ml+dp);
                dp=max(bs+dp,mr);
            }
            
            ll MA2=0,ML2=0;
            ll ml2=0;
            ll star2=last_block*block_size,en2=r;
            for(ll i=star2;i<=en2;i++){
                if(a[i].ff<=c+k&&a[i].ff>=c-k){
                    if(i-star2){
                        MA2=a[i].ss+max(MA2,0);
                        ML2=ML2+a[i].ss;
                    }
                    else{
                        MA2=max(0,a[i].ss);
                        ML2=a[i].ss;
                    }
                    ml2=max(ml2,ML2);
                    ans=max(ans,MA2);
                }
            }
            if(last_block-1>=start_block)
                ans=max(ans,dp+ml2);
            cout<<ans<<'\n';
        }
    }
    

	return 0;
}