    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    int n,q,i=0;
    scanf("%d%d",&n,&q);
    int j;
    bool pos[31][n];
    int mini[31];
    f(i,31)mini[i]=n;
    f(i,31)
    {
        f(j,n)
        {pos[i][j]=0;
        }
    }
    //pos[0][i] last digit in binary
     
    while(q--)
    {   int yy;
        scanf("%d",&yy);
        if(yy==2)
        {   bool we=1,lll=0;
            
            
            long long k;
            scanf("%lld",&k);
            int count=0;
            bool posi[31];
            f(i,31)posi[i]=0;
            while(k!=0)
            {
                posi[count]=k%2;
                lll=lll|(k%2);
                k/=2;
                count++;
            }
            
          //f(i,30)    cout<<mini[i]<<" ";cout<<endl;
           //f(i,30)        cout<<posi[i]<<" ";cout<<endl;
            
            int flag=-1,minflag=n;
            f(i,31)
            {
                if(posi[i])
                {   
                    flag=max(flag,mini[i]);
                    minflag=min(minflag,mini[i]);
                }
            }
            vector <int> a1;
                    f(i,31){
                        if(posi[i]){
                    if(mini[i]==n)
                    {
                        we=0;
                    }
                    a1.pb(mini[i]);        
                    }
                    }
                    sort(a1.begin(),a1.end());
            
            if(we)
            {
              
            f(i,31)
            {
                if(posi[i]==0&&mini[i]<=flag&&mini[i]>=minflag)
                {   
                    if(binary_search (a1.begin(), a1.end(), mini[i]))
                    we=0;
                }
            }
            
            }
            
            if(we||!lll)
            {  
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            
        }
        else
        {   long long b;
            int kk,count=0;
            scanf("%d%lld",&kk,&b);
            kk--;
            f(i,31)
            {
                if(mini[i]==kk)
                {
                mini[i]=n;
                for(int r=kk+1;r<n;r++)
                {
                    if(pos[i][r]==1)
                    {mini[i]=r;break;}
                }
                }
                pos[i][kk]=0;
            }
            while(b!=0)
            {
                pos[count][kk]=b%2;
                if(b%2)
                mini[count]=min(mini[count],kk);
                b/=2;
                count++;
            }
            
            
        }
    }
    	return 0;
    }
     