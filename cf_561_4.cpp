

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)

ll mul(ll x,ll y)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }

  return ans;
};

/******************************************************************************************************/

int main()
{
	ll q;
	cin>>q;

	while(q--)
	{

		ll a,b,m,i,in=1,in1,aa,bb,mid,cnt,j,rem,last,xx;
		cin>>a>>b>>m;

		if(a==b)
			cout<<1<<" "<<a<<"\n";
		else
		{
			for(i=2;i<=53;i++)
			{
				aa = in*a + in;
				bb = in*a + in*m;

				if(aa<=b && b<=bb)
				{
					cout<<i<<" "<<a<<" ";
					in1 = 1;
					rem = b - aa;
					in/=2;
					last = 0;

					for(j=2;j<=i;j++)
					{	
						mid = in1*a + in1;
						
						if(in==0)
							in = 1;

							xx = rem/in;

						cnt = min(xx,m-1);
						rem-=cnt*in;
						mid+=(last+cnt);
						last = last*2 + cnt;
						cout<<mid<<" ";
						in1*=2;
						in/=2;
					}

					cout<<"\n";
					break;
				}
				else if(b<aa)
				{
					cout<<-1<<"\n";
					break;
				}

				in*=2;
			}
		}

	}

	return 0;
}