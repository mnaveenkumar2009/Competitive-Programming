    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int main() {
        int t,i;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            long long maxi=0;
            vector <long long> c(n),w(n),sum(n);
            vector <int> p,q;
            vector <vector <long long> > pos(n+1,vector <long long> (0,0));
            f(i,n)
            {
                cin>>c[i];
                pos[c[i]].pb(i);
                if(pos[c[i]].size()>=2)
                {p.pb(i);
                q.pb(pos[c[i]][pos[c[i]].size()-2]);
                    
                }
            }
             f(i,n)
            {
                cin>>w[i];
            }
            sum[0]=w[0];
             f(i,n-1)
            {
                sum[i+1]=sum[i]+w[i+1];
            }int j;
          //  f(i,n+1)        {            f(j,pos[i].size())            cout<<pos[i][j]<<" ";cout<<endl;        }
            //f(i,p.size())cout<<q[i]<<" ";cout<<endl;
            i=0;
            int l=0,r=0;
        
         while(r!=n-1){   
            while(i!=p.size()){
            if(q[i]>=l)
           { 
               break;}
            else
            {
               i++; 
            }
                
            }
            if(i!=p.size())
            r=p[i]-1;
            else
            r=n-1;
           // cout<<l<<" "<<r<<endl;
            if(l>0)
            maxi=max(maxi,sum[r]-sum[l-1]);
            else
            maxi=sum[r];
            if(!(l==0&&r==n-1))
            l=q[i]+1;
         }
         cout<<maxi<<endl;
        }
    	return 0;
    } 