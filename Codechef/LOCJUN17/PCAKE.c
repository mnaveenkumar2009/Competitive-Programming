    #include <stdio.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define N 1001
    int isuniq ( int i, int r,int sum[][168])
    {      int j;
           
           if(i!=0)
           {
               f(j,168)
                {
                    if(sum[r][j]-sum[i-1][j]>=2)return 0;
                    
                }
           }
           else
           {
               f(j,168)
           {
           if(sum[r][j]>=2)return 0;
           } 
           }
           
           return (1);
    }
    int main(void) {
        int p[168];
    p[0]=2;
    p[1]=3;
    p[2]=5;
    p[3]=7;
    p[4]=11;
    p[5]=13;
    p[6]=17;
    p[7]=19;
    p[8]=23;
    p[9]=29;
    p[10]=31;
    p[11]=37;
    p[12]=41;
    p[13]=43;
    p[14]=47;
    p[15]=53;
    p[16]=59;
    p[17]=61;
    p[18]=67;
    p[19]=71;
    p[20]=73;
    p[21]=79;
    p[22]=83;
    p[23]=89;
    p[24]=97;
    p[25]=101;
    p[26]=103;
    p[27]=107;
    p[28]=109;
    p[29]=113;
    p[30]=127;
    p[31]=131;
    p[32]=137;
    p[33]=139;
    p[34]=149;
    p[35]=151;
    p[36]=157;
    p[37]=163;
    p[38]=167;
    p[39]=173;
    p[40]=179;
    p[41]=181;
    p[42]=191;
    p[43]=193;
    p[44]=197;
    p[45]=199;
    p[46]=211;
    p[47]=223;
    p[48]=227;
    p[49]=229;
    p[50]=233;
    p[51]=239;
    p[52]=241;
    p[53]=251;
    p[54]=257;
    p[55]=263;
    p[56]=269;
    p[57]=271;
    p[58]=277;
    p[59]=281;
    p[60]=283;
    p[61]=293;
    p[62]=307;
    p[63]=311;
    p[64]=313;
    p[65]=317;
    p[66]=331;
    p[67]=337;
    p[68]=347;
    p[69]=349;
    p[70]=353;
    p[71]=359;
    p[72]=367;
    p[73]=373;
    p[74]=379;
    p[75]=383;
    p[76]=389;
    p[77]=397;
    p[78]=401;
    p[79]=409;
    p[80]=419;
    p[81]=421;
    p[82]=431;
    p[83]=433;
    p[84]=439;
    p[85]=443;
    p[86]=449;
    p[87]=457;
    p[88]=461;
    p[89]=463;
    p[90]=467;
    p[91]=479;
    p[92]=487;
    p[93]=491;
    p[94]=499;
    p[95]=503;
    p[96]=509;
    p[97]=521;
    p[98]=523;
    p[99]=541;
    p[100]=547;
    p[101]=557;
    p[102]=563;
    p[103]=569;
    p[104]=571;
    p[105]=577;
    p[106]=587;
    p[107]=593;
    p[108]=599;
    p[109]=601;
    p[110]=607;
    p[111]=613;
    p[112]=617;
    p[113]=619;
    p[114]=631;
    p[115]=641;
    p[116]=643;
    p[117]=647;
    p[118]=653;
    p[119]=659;
    p[120]=661;
    p[121]=673;
    p[122]=677;
    p[123]=683;
    p[124]=691;
    p[125]=701;
    p[126]=709;
    p[127]=719;
    p[128]=727;
    p[129]=733;
    p[130]=739;
    p[131]=743;
    p[132]=751;
    p[133]=757;
    p[134]=761;
    p[135]=769;
    p[136]=773;
    p[137]=787;
    p[138]=797;
    p[139]=809;
    p[140]=811;
    p[141]=821;
    p[142]=823;
    p[143]=827;
    p[144]=829;
    p[145]=839;
    p[146]=853;
    p[147]=857;
    p[148]=859;
    p[149]=863;
    p[150]=877;
    p[151]=881;
    p[152]=883;
    p[153]=887;
    p[154]=907;
    p[155]=911;
    p[156]=919;
    p[157]=929;
    p[158]=937;
    p[159]=941;
    p[160]=947;
    p[161]=953;
    p[162]=967;
    p[163]=971;
    p[164]=977;
    p[165]=983;
    p[166]=991;
    p[167]=997;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,j,i;
        scanf("%d",&n);
        int sum[n][168];
        memset(sum,0,168*n*sizeof(int));
        int aa[n];
        f(i,n)
        {
            j=0;
                scanf("%d",&aa[i]);
                while(aa[i]!=1)
                {
                    if(aa[i]%p[j]==0)
                    {
                    aa[i]/=p[j];
                    sum[i][j]++;
                    }
                    else
                    j++;
                }
        }
        f(i,n-1)
            {   
                f(j,168)
                sum[i+1][j]+=sum[i][j];
            }
           
            long long ans=0; 
           int left,right=-1,flag=-1;
            
            
            f(i,n)
            {  
            if(i>right)
            left=i;
            else
            left=right;
            
            int mid;
            right=-1;
            int l=left,r=n-1;
            if(flag<i)
            {
                if(isuniq(i,l,sum)==0)continue;
            }
            ///////////////////
            while(1){
                
        int mid=(r+l)/2;
        if(l>r)break;
        if(l==r){
            if(isuniq(i,l,sum))
            {right=l;break;
        }
            
        }
        if(isuniq(i,mid,sum)&&!isuniq(i,mid+1,sum))
        {
            right= (mid);break;
        }
        if(l==r-1)
        {
            right= (r);break;
        }
        if(isuniq(i,mid,sum))
        {
        l=mid;    
        }
        else
        {
        r=mid-1;    
        }
            }
            ///////////////////////
            if(right==-1)continue;
           // printf("%d %d %d %d %lld\n",i,left,right,flag,ans);
           // cout<<i<<" "<<left<<" "<<right<<" "<<flag<<" "<<ans<<endl;
            long long k=0;
            if(flag<i&&right!=-1)
            {
                k=(right-i)+1;
                k*=k+1;
                k/=2;
            }
            if(flag>=i&&flag<right)
            {
                k=right-flag;
                long long k2=(flag-i)+1;
                k2*=k;
                k*=k+1;
                k/=2;
                ans+=k2;
            }
            if(k>=0){
            ans+=k;
            }
            if(flag<right)
            flag=right;
            
            }
            printf("%lld\n",ans);
    }
     
    	return 0;
    } 