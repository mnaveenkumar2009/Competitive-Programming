    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
    #define gc getchar
    #define pc putchar
    inline unsigned long long uscan()
    {
        unsigned long long n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
    inline long int lscan()                 
    {
        long int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
     
    inline  int sscan()                     
    {register  int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0')
        {
    n=n*10+c-'0';
    c=gc();
        }
    return n;
    }
     
    int main()
    {
        int t=1;
       // t=sscan();
        while(t--){
            ll n=sscan();
            ll nextp=ceil(log2(n));
            ll nob=nextp;
            nextp=1LL<<nextp;
            if((1LL<<nob)==n)
            {
                nob++;
                nextp=nextp<<1;
            }
            //cout<<nob<<endl;
            //cout<<nextp<<endl;
            vector <ll> a(n),death(n,-1);
            ll i,j,k;
            f(i,n)
            a[i]=uscan();
            /*
            vector <vector <ll> > aa(nob+1, vector <ll> (0,0));
            f(i,nextp){
                int count=0;
                f(j,nob){
                    if( ((1<<j)&i)>0 ){
                        count++;
                    }
                }
                aa[count].pb(i);
            }
            f(i,aa.size()){            f(j,aa[i].size())cout<<aa[i][j]<<" ";cout<<endl;        }*/
            ll q=uscan();
            ll rq=sqrt(q);
            if(rq*rq<q)
            rq++;
            vector < vector <pair <ll,ll> > > que(rq,vector <pair <ll,ll> > (rq,mp(0,0)));
            f(i,q){
                que[i/rq][i%rq].ff=uscan()%nextp;
                que[i/rq][i%rq].ss=uscan();
            }
            //f(i,rq){            f(j,rq)cout<<que[i][j].ff<<" "<<que[i][j].ss<<" ";        }cout<<endl;
            ll count=q;
            f(i,rq){
                vector <ll> b=a;
                //decrease a for root q queries
                /*vector <vector <ll> > qq(nextp,vector <ll> (nob,0));
                f(j,rq){
                    qq[que[i][j].ff][0]=que[i][j].ss;
                }
                
                f(j,nextp){
                    f(k,nob){
                        
                    }
                }*/
                
                vector <ll> qq(nextp,0);
                f(j,rq){
                    qq[que[i][j].ff]+=que[i][j].ss;
                }
                
                //f(j,nextp)cout<<qq[j]<<" ";cout<<endl;
                f(j,nob)
                    for(ll mask = 0; mask < nextp; ++mask){
    	                if(mask & (1LL<<j))
    		             qq[mask^(1<<j)]+=qq[mask];
                    }
                //f(j,nextp)cout<<qq[j]<<" ";cout<<endl;
             //   f(j,n)cout<<a[j]<<" ";cout<<endl;
                f(j,n){a[j]-=qq[j];}
               // f(j,n)cout<<a[j]<<" ";cout<<endl;
                //check
                f(j,n){
                    if(death[j]==-1&&a[j]<=0){
                        //check when they died
                        f(k,rq){
                            if((que[i][k].ff&j)==j){
                                b[j]-=que[i][k].ss;
                            }
                            if(b[j]<=0){
                            death[j]=i*rq;
                            death[j]+=k;
                            break;
                            }
                        }
                    }
                }
              //  f(j,n)cout<<b[j]<<" ";cout<<endl;
            }
            
            vector <ll> ans(q,0);
            //f(i,n)cout<<death[i]<<" ";cout<<endl;
            f(i,n){
                if(death[i]!=-1)
                ans[death[i]]--;
            }
            f(i,q-1){
                ans[i+1]+=ans[i];
            }
            f(i,q)ans[i]+=n;
            f(i,q){
                printf("%lld\n",ans[i]);
            }
        }
    	return 0;
    } 