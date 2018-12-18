#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
#define squar(x) (x*x)
#define dist(x,y,x2,y2) (((x)-(x2))*((x)-(x2))+((y)-(y2))*((y)-(y2)))

int n;
ld X[200],Y[200],Z[200];
ld r[200],R[200];
ld v=0;

bool isThisptintorus(int tor,ld x, ld y, ld z){
    x-=X[tor];
    y-=Y[tor];
    z-=Z[tor];
    ld sec=R[tor]-sqrt(x*x+y*y);
    if((z*z+sec*sec)<=r[tor]*r[tor]){
        return 1;
    }
    return 0;
}
#define threshold 0.02
ll xjc=0,checkpt=0,xxxxs=0;
void f2(ld x, ld y,ld z,ld side){
    xjc++;
    // if(checkpt){
    //     cout<<x<<' '<<y<<' '<<z<<' ' <<side<<'\n';
    // }
    bool isSomethingthere=0;
    bool isEverythingthere,xxx;
    bool nknknkn=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        isEverythingthere=1;
        nknknkn|=isThisptintorus(i,x,y,z);
        ld hsid=side/2.0;
        ld z1=z+hsid,z2=z-hsid,x1=x+hsid,x2=x-hsid,y1=y+hsid,y2=y-hsid;
        
        isEverythingthere&=isThisptintorus(i,x+hsid,y+hsid,z+hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x+hsid,y+hsid,z-hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x+hsid,y-hsid,z+hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x+hsid,y-hsid,z-hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x-hsid,y+hsid,z+hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x-hsid,y+hsid,z-hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x-hsid,y-hsid,z+hsid);
        if(isEverythingthere)
        isEverythingthere&=isThisptintorus(i,x-hsid,y-hsid,z-hsid);
        if(isEverythingthere)
            break;

        if(z1>=Z[i]&&z2<=Z[i]){
            ld aby=abs(y-Y[i]);
            ld summ=R[i]+r[i];
            ld xdash=abs(x-X[i])-hsid;
            
            if(xdash<=0){
                if(aby<summ+hsid){
                    isSomethingthere=1;
                }
            }
            else
                if(xdash<=summ&&aby-hsid<sqrt(summ*summ-(xdash)*(xdash))){
                    isSomethingthere=1;
                }
            ld smallcir=R[i]-r[i];
            smallcir*=smallcir;
            if(dist(x-hsid,y-hsid,X[i],Y[i])<=smallcir){
                if(dist(x+hsid,y-hsid,X[i],Y[i])<=smallcir){
                    if(dist(x-hsid,y+hsid,X[i],Y[i])<=smallcir){
                        if(dist(x+hsid,y+hsid,X[i],Y[i])<=smallcir){
                            isSomethingthere=0;
                        }
                    }
                }
            }
            if(isSomethingthere&&ind==-1){
                ind=i;
            }
            
        }
        else{
            ld xyy=min(abs(z1-Z[i]),abs(z2-Z[i]));
            if(xyy<=r[i]){
                ld rrrr=sqrt(r[i]*r[i]-xyy*xyy);
                ld abx=abs(x-X[i]),aby=abs(y-Y[i]);
                ld summ=rrrr+R[i];
                ld xdash=abx-hsid;
                ld ydash=aby-hsid;
                if(xdash<=0){
                    if(aby<summ+hsid){
                        isSomethingthere=1;
                    }
                }
                else
                    if(xdash<=summ&&aby-hsid<sqrt(summ*summ-(xdash)*(xdash))){
                        isSomethingthere=1;
                        // if(abs(x-50.3906)<0.1 &&abs(y+68.3594)<0.1 &&abs(z-50.3906)<0.1){
                        //     cout<<rrrr<<' '<<xyy<<' '<<abx<<' '<<aby<<'\n';
                        //     cout<<x<<' '<<y<<' '<<z<<' ' <<side<<'\n';
                        //     cout<<z1<<' '<<z2<<' '<<Z[i]<<'\n';
                        //     cout<<summ<<' '<<xdash<<'\n';
                        //     cout<<aby-hsid<<' '<<sqrt(summ*summ-(xdash)*(xdash))<<'\n';
                        // }
                    }
                if(xdash<=0){
                    if(aby<summ+hsid){
                        isSomethingthere=1;
                    }
                }
                else
                    if(xdash<=summ&&aby-hsid<sqrt(summ*summ-(xdash)*(xdash))){
                        isSomethingthere=1;
                        // if(abs(x-50.3906)<0.1 &&abs(y+68.3594)<0.1 &&abs(z-50.3906)<0.1){
                        //     cout<<rrrr<<' '<<xyy<<' '<<abx<<' '<<aby<<'\n';
                        //     cout<<x<<' '<<y<<' '<<z<<' ' <<side<<'\n';
                        //     cout<<z1<<' '<<z2<<' '<<Z[i]<<'\n';
                        //     cout<<summ<<' '<<xdash<<'\n';
                        //     cout<<aby-hsid<<' '<<sqrt(summ*summ-(xdash)*(xdash))<<'\n';
                        // }
                    }
                    
                ld smallcir=R[i]-rrrr;
                smallcir*=smallcir;
                if(dist(x-hsid,y-hsid,X[i],Y[i])<=smallcir){
                    if(dist(x+hsid,y-hsid,X[i],Y[i])<=smallcir){
                        if(dist(x-hsid,y+hsid,X[i],Y[i])<=smallcir){
                            if(dist(x+hsid,y+hsid,X[i],Y[i])<=smallcir){
                                isSomethingthere=0;
                            }
                        }
                    }
                }
                if(isSomethingthere){
                    
                }
                // 1745953
                // 2438554.7617566772
            }
        }
    }
    if(isEverythingthere){
        v+=side*side*side;
    }
    else{
        if(isSomethingthere&&side>=threshold){
            side/=2.0;
            ld hsid=side/2.0;
            ld vvvv=v;
            if(abs(x-50.3906)<0.1 &&abs(y+68.3594)<0.1 &&abs(z-50.3906)<0.1){
                checkpt=1234;
            }
            // if(side>=threshold)
            {
                f2(x+hsid,y+hsid,z+hsid,side);
                f2(x+hsid,y+hsid,z-hsid,side);
                f2(x+hsid,y-hsid,z+hsid,side);
                f2(x+hsid,y-hsid,z-hsid,side);
                f2(x-hsid,y+hsid,z+hsid,side);
                f2(x-hsid,y+hsid,z-hsid,side);
                f2(x-hsid,y-hsid,z+hsid,side);
                f2(x-hsid,y-hsid,z-hsid,side);
            }
            if(v>=vvvv+(side*side*side)){
                xxxxs++;
            }
            if(v==vvvv&&side>0.01){
                // if(abs(x-50.3906)<0.1 &&abs(y+68.3594)<0.1 &&abs(z-50.3906)<0.1){
                        // cout<<rrrr<<' '<<xyy<<' '<<abx<<' '<<aby<<'\n';
                        // cout<<x<<' '<<y<<' '<<z<<' ' <<side<<'\n';
                        // cout<<z1<<' '<<z2<<' '<<Z[i]<<'\n';
                        // cout<<summ<<' '<<xdash<<'\n';
                        // cout<<aby-hsid<<' '<<sqrt(summ*summ-(xdash)*(xdash))<<'\n';
                        // cout<<dist(x+hsid,y+hsid,X[i],Y[i])<<' '<<dist(x-hsid,y-hsid,X[i],Y[i])<<' '<<dist(x-hsid,y+hsid,X[i],Y[i])<<' '<<dist(x+hsid,y-hsid,X[i],Y[i])<<'\n';
                        // cout<<R[i]+rrrr<<'\n';
                        // checkpt=0;
                // }
            }
            if(abs(x-50.3906)<0.1 &&abs(y+68.3594)<0.1 &&abs(z-50.3906)<0.1){
                checkpt=0;
            }
            
        }
        else{
            if(side<threshold&&isSomethingthere){
                // if(nknknkn)
                //     v+=side*side*side/2.0;
                    ;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i]>>Z[i]>>R[i]>>r[i];
    }
    // cout<<isThisptintorus(0,6.70013-0.0579834/2,-0.953674+0.0579834/2,-1.01166+0.0579834/2)<<'\n';
    // cout<<isThisptintorus(0,6.70013+0.0579834/2,-0.953674-0.0579834/2,-1.01166-0.0579834/2)<<'\n';
    f2(-150,-150,-150,1900);
    // f2(0,0,0,20);
    cout<<xjc<<' '<<xxxxs<<'\n';
    cout<<fixed<<setprecision(10)<<v<<'\n';
	return 0;
}
