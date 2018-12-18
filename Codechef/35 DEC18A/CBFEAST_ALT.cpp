#include <bits/stdc++.h>
using namespace std;

#define block_size 400
#define number_of_blocks 1000

#define mp make_pair
#define mp5(a,b,c,d,e) mp(a,mp(mp(b,c),mp(d,e)))
#define p5 pair <int,pair <pair <int,int> ,pair <int,int> > >

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    p5 possible_cs[number_of_blocks][(block_size<<1)+3];
    pair <int,int> a[400000];
    int l=200000, r=199999, ans=0;

    int q,k;
    cin>>q>>k;
    
    while(q--){
        int b,C;
        cin>>b>>C;
        int c=C^ans;

        if(b!=3){
            int d;
            cin>>d;
            int block_num=-1;
            if(b==1){
                a[--l]=mp(c,d);
                if((l+1)%block_size==0&&l+1!=200000)
                    block_num=(l+1)/block_size;
            }
            else{
                a[++r]=mp(c,d);
                if(r%block_size==0&&r!=200000)
                    block_num=(r-1)/block_size;
            }
            if(block_num!=-1){
                // executed at most number_of_blocks/2 times
                // O(block_size^2 + block_size*log(block_size))
                int minim=INT_MAX;

                for(int ii=0;ii<(block_size<<1);ii++){

                    int star=block_num*block_size,en=star+block_size-1;
                    minim=min(minim,a[star+(ii>>1)].first);

                    int valid_c=a[star+(ii>>1)].first+k;
                    if(ii&1)
                        valid_c-=((k<<1)+1);

                    int MA=0,ML=0,ml=0,mr=0,bs=0,ma=0;
                    for(int i=star;i<=en;i++){
                        if(a[i].first<=valid_c+k&&a[i].first>=valid_c-k){
                            bs+=a[i].second;
                            MA=a[i].second+max(MA,0);
                            ML+=a[i].second;
                            ma=max(ma,MA);
                            ml=max(ml,ML);
                            mr=min(mr,ML);
                        }
                    }
                    mr=bs-mr;
                    possible_cs[block_num][ii]=(mp5(valid_c,ml,mr,bs,ma));
                }
                possible_cs[block_num][800]=(mp5(minim-1-k,0,0,0,0));
                possible_cs[block_num][801]=(mp5(INT_MAX,0,0,0,0));
                possible_cs[block_num][802]=(mp5(-INT_MAX,0,0,0,0));
                sort(possible_cs[block_num],possible_cs[block_num]+803);
            }
        }
        else{
            ans=0;
            // O( number_of_blocks*log(block_size) + block_size )

            int dp=0;
            int cur_block = l/block_size;
            int last_block = r/block_size;
            
            int MA1=0, ML1=0, mr1=0, bs1=0;
            int en1=block_size*(cur_block+1);
            
            for(int i=l;i<en1;i++){
                if(a[i].first<=c+k&&a[i].first>=c-k){
                    bs1+=a[i].second;
                    MA1=a[i].second+max(MA1,0);
                    ML1+=a[i].second;
                    ans=max(ans,MA1);
                    mr1=min(mr1,ML1);
                }
            }
            dp=mr1=bs1-mr1;
            
            p5 search_dummy=mp5(c,0,0,0,0);
            for(cur_block++;cur_block<last_block;cur_block++){
                // search for anything<=c
                auto tem=lower_bound(possible_cs[cur_block],possible_cs[cur_block]+803,search_dummy);               
                ans=max(tem->second.second.second,ans);
                ans=max(ans,tem->second.first.first+dp);
                //dp = max(blocksum+dp,maxfromright)
                dp=max(tem->second.second.first+dp,tem->second.first.second);
            }
            
            int MA2=0,ML2=0,ml2=0;
            for(int i=last_block*block_size;i<=r;i++){
                if(a[i].first<=c+k&&a[i].first>=c-k){
                    MA2=a[i].second+max(MA2,0);
                    ML2+=a[i].second;
                    ml2=max(ml2,ML2);
                    ans=max(ans,MA2);
                }
            }
            if(last_block>l/block_size)
                ans=max(ans,dp+ml2);
            cout<<ans<<'\n';
        }
    }
	return 0;
}