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
            ll f2(ll t,string s){
                int i;
                ll ret=0;
                for(i=15;i>=0;i--){
                    if((1LL<<i)&t){
                        ret+=s[15-i]-'0';
                    }
                    else
                    {
                        ret+='1'-s[15-i];
                    }
                }
                return 16-ret;
            }
            bool f3(string s,ll l,ll r){
                int i;
                int fl=-1,fr=-1,fs=-1,fss;
                
                f(i,32){
                    if(s[i]=='1'){
                        fs=i;
                        break;
                    }
                }
                for(i=15;i>=0;i--){
                    if((1<<i)&l){
                        fl=15-i;
                        break;
                    }
                }
                for(i=15;i>=0;i--){
                    if((1<<i)&r){
                        fr=15-i;
                        break;
                    }
                }
                if(fl==-1){
                    fss=fr+16;
                }
                else
                {
                    fss=fl;
                }
                if(fss!=fs)return 0;
                return 1;
            }
            int main()
            {
                int t=1;
                ll tot=1<<16;
                //cout<<tot<<endl;
                int i,j;
                //vector < pair< pair<ll,ll>,ll > > a(tot,mp(mp(0,0),0));
                map < pair<int,int> ,int > a;
                f(i,tot){
                    
                    pair<int,int> temp[16];
                    f(j,16)temp[j]=mp(0,0);
                    for(j=15;j>=0;j--){
                        if((1<<j)&i){
                            if(j==15){
                                temp[0].ss=1;
                            }
                            else
                            {
                                temp[15-j].ss=temp[14-j].ss+temp[14-j].ff+1;
                                temp[15-j].ff=temp[14-j].ff;
                            }
                        }
                        else
                        {
                            if(j!=15)
                            {
                                temp[15-j].ff=temp[14-j].ss+temp[14-j].ff;
                                temp[15-j].ss=temp[14-j].ss;
                            }
                        }
                    }
                    a[mp(temp[15].ff,temp[15].ss)]=i;
                }
                
                /*
                f(i,20)
                {//i=43690;
                    cout<<a[i].ss<<" "<<a[i].ff.ff<<" "<<a[i].ff.ss<<endl;
                }
                f(i,tot-1){
                    if(a[i].ff==a[i+1].ff){
                        cout<<a[i].ss<<" "<<a[i].ff.ff<<" "<<a[i].ff.ss<<endl;
                        cout<<a[i+1].ss<<" "<<a[i+1].ff.ff<<" "<<a[i+1].ff.ss<<endl;
                    }
                }*/
                //no 2 pairs equal
                
                  //  cout<<f3("00000000000000000000000000001010",0,10)<<endl;
                t=sscan();
                while(t--){
                    string s,s1,s2,tt;
                    ll X;
                    cin>>s>>X;
                    tt=s;
                    s="";
                    f(i,32-tt.length())
                    {
                        s+="0";
                    }
                    s+=tt;
                    f(i,16){
                        s1.pb(s[i]);
                        s2.pb(s[i+16]);
                    }
                    //cout<<s<<endl<<s1<<endl<<s2<<endl;
                    ll ans=33;
                    f(i,tot){
                        if(i&1)continue;
                        //mx+ny=
                        //x
                        //y
                        int m1=1,n1=0,m2=0,n2=1,k1=0,k2=0;
                        for(j=15;j>=0;j--){
                            if((1<<j)&i){
                                m2+=m1;
                                n2+=n1;
                                k2=1+k1+k2;
                            }
                            else
                            {
                                m1+=m2;
                                n1+=n2;
                                k1=k1+k2;
                            }
                        }
                        j=(X-k1-1600*m1);
                        j=ceil(double(j)/double(n1));
                        if(j<0)j=0;
                        for(;j<1300;j++){
                            //m1x+n1j+k1=X      
                            //search for (x,j)
                            if((X-k1-n1*j)%m1)continue;
                            ll x=(X-k1-n1*j)/m1;
                            if(x<0)break;
                            
                            map<pair<int,int> ,int>::iterator it=a.find(mp(x,j));
                            if(it==a.end())continue;
                            ll tem=it->ss;
                            if(f3(s,tem,i))
                            {
                                ans=min(ans,f2(tem,s1)+f2(i,s2));
                            }
                        }
                    } 
                    if(ans==33){
                        printf("NO\n");
                    }
                    else
                    {
                        printf("YES\n%lld\n",ans);
                    }
                }
            	return 0;
            }   