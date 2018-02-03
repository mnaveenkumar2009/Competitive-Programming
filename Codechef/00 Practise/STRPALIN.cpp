    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    int q,i=0,t;
    long long n,m;
    scanf("%d",&t);
    while(t--)
    {
    string a,b;
    vector <int> count1(26,0),count2(26,0);
    cin>>a>>b;
    f(i,a.length())
    {
        count1[a[i]-'a']++;
    }
    f(i,b.length())
    {
        count2[b[i]-'a']++;
    }
       bool we=0;
       f(i,26)
       {
           if(count1[i]&&count2[i])we=1;
       }
       
       
       if(we)cout<<"Yes\n";
       else cout<< "No\n";
    }
    	return 0;
    }  