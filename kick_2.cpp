

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

ll a[100005],tgt[100005],mid[100005],b[100005],nxt[100005],seg[10000000];

void build(ll in,ll lt,ll rt)
{
	if(lt==rt)
		{	
			// cout<<in<<" "<<lt<<" "<<rt<<"\n";
			seg[in] = b[lt];
			// cout<<seg[in]<<"^^\n";
			return;
		}

	ll mid = (lt+rt)/2;
	build(in*2,lt,mid);
	build(in*2+1,mid+1,rt);

	seg[in] = max(seg[in*2],seg[in*2+1]);
	return;
}

void update(ll in,ll lt,ll rt,ll ql,ll qr,ll val)
{	
	if(rt<ql || qr<lt)
		{ 
			// cout<<in<<" "<<lt<<" "<<rt<<" "<<ql<<" "<<qr<<" "<<val<<"##\n";
		return;
		}

	if(ql<=lt && rt<=qr && lt==rt)
		{	
						// cout<<in<<" "<<lt<<" "<<rt<<" "<<ql<<" "<<qr<<" "<<val<<"\n";
			seg[in]+=val;
			// cout<<seg[in]<<"&&\n";
			return;
		}

	// cout<<lt<<" "<<rt<<"%%\n";	
	ll mid = (lt+rt)/2;
	// cout<<mid<<"()\n";
	update(in*2,lt,mid,ql,qr,val);
	update(in*2+1,mid+1,rt,ql,qr,val);

	seg[in] = max(seg[in*2],seg[in*2+1]);
	// cout<<in<<" "<<lt<<" "<<rt<<" "<<ql<<" "<<qr<<" "<<val<<"\n";
	// cout<<seg[in]<<"---\n";
	return;
}

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{	
		ll n,i,ss,ans=0,j,size;
		s(n); s(ss);

		vector < vector < ll > > v(100005);

		for(i=1;i<=n;i++)
		{
			s(a[i]);
			tgt[i] = n+1;
			nxt[i] = n+1;
			v[a[i]]._pb(i);

			mid[i] = mid[i-1];

			if(v[a[i]].size()<=ss)
				++mid[i];
			else if(v[a[i]].size()==ss+1)
				mid[i]-=ss;

			// cout<<i<<"**"<<mid[i]<<"\n";
		}

		for(i=1;i<=100002;i++)
			if(v[i].size()>ss)
			{
				size = v[i].size();
				
				for(j=0;j+ss<size;j++)
				{
					tgt[v[i][j]] = v[i][j+ss];	
					nxt[v[i][j]] = v[i][j+1];
				}
			}	

		// for(i=1;i<=n;i++)
		// 	cout<<tgt[i]<<" ";
		// cout<<"\n";

		size = 0;	
		vector<ll> vv;
		vv._pb(0);

		for(i=1;i<=n;i++)
		if(tgt[i]!=n+1)	
			{
				vv._pb(tgt[i]);
				++size;
			}

		vv._pb(n+1);
		++size;

		sort(vv.begin(),vv.end());

		map<ll,ll> mp;
		// cout<<size<<"===\n";
		for(i=1;i<=size;i++)
		{
			b[i] = mid[vv[i]-1];
			mp[vv[i]] = i;
			// cout<<vv[i]<<" -> "<<b[i]<<"\n";
		}	

		build(1,1,size);
		ans = seg[1];
		// cout<<"go\n";
		ll in1,in2;

		for(i=1;i<=n;i++)
		{
			if(tgt[i]==n+1)
				update(1,1,size,1,size,-1);
			else
			{
				in1 = mp[tgt[i]];
				update(1,1,size,1,in1,-1);

				in2 = mp[nxt[tgt[i]]];

				// cout<<in1<<"//"<<in2<<"\n";
				update(1,1,size,in1+1,in2,ss);
			}

			ans = max(ans,seg[1]);
		}

		cout<<"Case #"<<g<<": "<<ans<<"\n";
		++g;
	}
	return 0;
}