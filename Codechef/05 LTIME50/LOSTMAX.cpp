    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    int q,i=0,t;
    long long n,m;
    scanf("%d",&t);
    string a;
        getline(cin,a);
    while(t--)
    {
        int temp ;char ch;
        n=0;
        int max1=0,max2=0;
         while(2 == scanf("%d%c", &temp, &ch)){
             int x=temp;n++;
             if(x>max1)
            {
                max2=max1;
                max1=x;
            }
            else
            {
                if(x>max2)
                {
                    max2=x;
                }
            }
            
            if(ch == '\n')
                break;
            else if(ch != ' '){
                fprintf(stderr, "Invalid input.\n");
                return -1;
            }
        }
        
      
        if(max1==n-1)printf("%d\n",max2);
        else
        printf("%d\n",max1);
        
        
    }
    	return 0;
    }  