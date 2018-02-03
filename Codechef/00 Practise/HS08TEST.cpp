    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    int x;
    float y;
    cin>>x>>y;
    float z=x;
    float p;
    p=y-z-0.5;
    if(x%5==0)
    {
        if(z+0.5<=y)
        {
            printf("%0.2f",p);
      
        }
        else
        {
           
            
           cout<<y;
        }
    }
    else
    {
        cout<<y;
    }
    return 0;
    }
     