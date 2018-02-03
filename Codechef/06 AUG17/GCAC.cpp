    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    using namespace std;
     
    int main()
    {
        int t;
        sd(t);
        while(t--)
        {
           long long i,j,n,m,count=0,sum=0;
           
           slld(n);slld(m);
           
           vector <long long> a(n),os(m),vs(m),vs2(m);
           f(i,n)
           {
               slld(a[i]);
           }
           f(i,m)
           {
               slld(os[i]);
               slld(vs[i]);
               vs2[i]=vs[i];
           }
           char qul[n][m];
           bool qual[n][m];
           f(i,n)
           {
               string ss;
               cin>>ss;
               f(j,m)
               {
                   qual[i][j]=ss[j]-'0';
                  // cout<<qual[i][j];
               }
           }
           f(i,n)
           {int k=-1;
           bool hhh=0;
               f(j,m)
               {
                   if(qual[i][j])
                   {   
                       
                       if(vs[j]&&os[j]>=a[i])
                       {hhh=1;
                           if(k==-1)
                       {
                           k=j;
                       }
                       if(os[j]>os[k])k=j;
                           
                       }
                   }
               }        
                        if(hhh){
                        vs[k]--;
                        count++;
                        sum+=os[k];
                        }
           }
           long long count2=0;
           f(i,m)
           {
               if(vs[i]==vs2[i])count2++;
           }
           printf("%lld %lld %lld\n",count,sum,count2);
        }
     
        return 0;
    }