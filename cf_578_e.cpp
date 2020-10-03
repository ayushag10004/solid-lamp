

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

ll p[2000005],va[2000005];
int main()
{
	ll n,i;
	cin>>n;

	string mid,str;
	for(i=1;i<=n;i++)
	{
		cin>>mid;
		str+='#';
		str+=mid;
	}

	ll last=-1,in,j,qq,size,fin;
	n = str.size();
	string aa,bb;

	for(i=0;i<n;i++)
	if(str[i]=='#')
	{	
		in = i+1;

		if(last!=-1)
		{	
			qq = last;
			size = 0;

			for(j=in;j<n;j++)
			if(j+1==n || str[j+1]=='#')
			{
				size = j-i;
				break;
			}

			aa.clear();
			bb.clear();

			for(j=i+size;j>i;j--)
				bb+=str[j];

			for(j=0;j<size+1;j++)
			if(last!=-1)
			{
				aa+=str[last];
				last = p[last];
			}
			else
				break;

			// cout<<aa<<" "<<bb<<"\n";

			aa+='#';
			aa+=bb;
			va[0] = 0;
			size = aa.size();

			for(j=1;j<size;j++)
			{
				in = va[j-1];

				while(in!=0 && aa[in]!=aa[j])
					in = va[in-1];

				if(aa[in]==aa[j])
					va[j] = in+1;
				else
					va[j] = 0;
			}

			fin = va[size-1];

			// cout<<aa<<"\n"<<size-1<<"\n";

			// for(j=0;j<size;j++)
			// 	cout<<va[i]<<" ";
			// cout<<"\n";
			// fin = va[size-1];
			// cout<<fin<<"\n";

			last = qq;
			while(fin>0)
				last = p[last],--fin;

		}

		// cout<<last<<"\n";
		in = i+1;
		for(j=in;j<n;j++)
		if(str[j]!='#')
		{
			p[j] = last;
			last = j;
		}
		else
			break;


		// cout<<last<<"\n";
	}

	// for(i=0;i<n;i++)
	// 	cout<<i<<" "<<str[i]<<" "<<p[i]<<"\n";

	string ans;
	in = n-1;

	while(in!=-1)
	{
		ans+=str[in];
		in = p[in];
	}

	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	
	return 0;
}