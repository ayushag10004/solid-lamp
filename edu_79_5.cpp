
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

ll f[100];

vector<ll> get_perm(ll n,ll k)
{	
	vector<ll> uu;

	if(n==0)
		return uu;
 
    vector<ll> vv(n+1);

	ll i,cnt,chance,mid,rem,xx,j;

	for(i=0;i<=n;i++)
		vv[i] = i;

	for(i=n;i>=1;i--)
	{
		cnt = n-i+1;
		chance = f[n-i];

		if(cnt*chance>=k)
		{
			mid = (k-1)/chance;
			vv[i] = i+mid;

			rem = (k-1)%chance;
			uu = get_perm(n-i, rem+1);

			for(j=i+1;j<=n;j++)
			{
				xx = uu[j-i];

				if(xx<=mid)
					vv[j] = xx+i-1;
				else
					vv[j] = xx+i;
			}

			break;
		}
	}

	return vv;
}

vector<ll> decompose(ll n,ll k)
{
	cout<<"decompose "<<n<<" "<<k<<"******\n";

	vector<ll> qq;
	if(n==0)
		return qq;

	cout<<"go--\n";
	ll dp[n+5],ff=0,i,j,jj,chance,perms,in,last,xx,rem;
	memset(dp, 0, sizeof dp);

	vector<ll> vv(n+1);

	for(i=0;i<=n;i++)
		vv[i] = i;

	dp[n+1] = 1;
	ll wq;
	for(i=n;i>=1;i--)
	{
		for(j=i;j<=n;j++)
		{	
			if(i==j)
				perms = 1;
			else
				perms = f[j-i-1];

			chance = dp[j+1];
			wq = dp[i];
			dp[i]+=(perms*chance);
			cout<<i<<" "<<j<<" "<<dp[i]<<"--";
			cout<<perms<<" "<<chance<<"\n";

			if(dp[i]>=k)
			{	k-=wq;
				vv[i] = j;
				in = (k-1)/chance;
				++in;
				rem = ((k-1)%chance) + 1;

				cout<<k<<" "<<in<<" "<<rem<<"+++\n";

				if(i!=j)
				{	last = j;
					vector<ll> mid = get_perm(j-i-1,in);
					for(jj=j-i-1;jj>=1;jj--)
					{
						xx = mid[jj];
						vv[last] = xx+i;
						last = vv[last];
					}
					vv[last] = i;
				}
				
				for(jj=1;jj<=n;jj++)
					cout<<vv[jj]<<" ";
				cout<<"-----------------------------\n";
				vector<ll> mid1 = decompose(n-j,rem);
				for(jj=j+1;jj<=n;jj++)
					vv[jj] = mid1[jj-j] + j;

				ff = 1;
				break;
			}
		}
			if(ff==1)
				break;
	}

	if(ff==0)
		vv.clear();

	return vv;
}

int main()
{	
	ll t,i;
	s(t);

	f[0] = 1;

	for(i=1;i<21;i++)
	{
		f[i] = i*f[i-1];
		
		if(f[i]<=0)
			f[i] = 0;
	}

	while(t--)
	{
		ll n,k;
		s(n); s(k);

		vector<ll> ans = decompose(n,k);

		if(ans.size()==0)
			cout<<"-1\n";
		else
		{
			for(i=1;i<=n;i++)
				cout<<ans[i]<<" ";
			cout<<"\n";
		}
		// vector<ll> aa = get_perm(n,k);

		// for(i=1;i<=n;i++)
		// 	cout<<aa[i]<<" ";

		// cout<<"\n";
	}	

	return 0;
}