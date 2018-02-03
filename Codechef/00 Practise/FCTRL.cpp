    #include <iostream>
    #include <cmath>
    using namespace std;
    int main()
    {
        int t,i,input,zeroes,c;
        cin>>t;
            while(t--)
        {
            zeroes=0;
            cin>>input;
            c=5;
            while((input/c)>0)
            {
                zeroes=zeroes+(input/c);
                c=c*5; 
            }
            cout<<zeroes<<"\n";
        }
     
    } 