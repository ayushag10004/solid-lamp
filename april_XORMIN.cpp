

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%d",&x)

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

ll a[200005];
vector < vector < ll > > v;
ll st[200005],en[200005],mp[200005],root[200005];
ll cnt,lft[5000005],rgt[5000005],val[5000005];

void dfs1(ll x,ll y,ll in)
{
	ll size = v[x].size(),i;

	st[x] = in;
	mp[in] = x;

	for(i=0;i<size;i++)
	if(v[x][i]!=y)
	{
		dfs1(v[x][i],x,in+1);
		in = en[v[x][i]];
	}

	en[x] = in;
	
	return;	
}

ll seg[3000005],cnt1,lft1[3000005],rgt1[3000005];
map<ll,ll> mmp;

ll check(ll in,ll lo,ll hi,ll lt,ll rt)
{
	if(hi<lt || rt<lo)
		return MOD;

	if(lt<=lo && hi<=rt)
		return seg[in];

	ll mid = (lo+hi)/2;

	return min(check(lft1[in],lo,mid,lt,rt),check(rgt1[in],mid+1,hi,lt,rt));
}

void update(ll cur,ll last,ll lo,ll hi,ll pos,ll val)
{	
	// cout<<cur<<" "<<last<<" "<<lo<<" "<<hi<<" "<<pos<<" "<<val<<"\n";
	
	if (hi<pos || pos<lo)
		return;

	if (lo==hi)
		{
			seg[cur] = val;
			return;
		}

	++cnt1;
	lft1[cnt1] = rgt1[cnt1] = 0;

	ll mid = (lo+hi)/2;

	if(pos<=mid)
	{
		lft1[cur] = cnt1;
		rgt1[cur] = rgt1[last];

		update(cnt1,lft1[last],lo,mid,pos,val);
	}
	else
	{
		rgt1[cur] = cnt1;
		lft1[cur] = lft1[last];

		update(cnt1,rgt1[last],mid+1,hi,pos,val);
	}

	seg[cur] = min(seg[lft1[cur]],seg[rgt1[cur]]);

	return;
}

int main()
{
	ll t;
	s(t);
	seg[0] = MOD;

	while(t--)
	{
		ll n,q,i,x,y;
		s(n); s(q);
		cnt = 0;
		cnt1 = 0;
		mmp.clear();

		for(i=1;i<=n;i++)
			s(a[i]);

		v.clear();
		v.resize(n+1);

		for(i=1;i<n;i++)
		{
			s(x); s(y);
			v[x]._pb(y);
			v[y]._pb(x);
		}

		dfs1(1,0,1);

		ll last1,cur1;
		
		for(i=1;i<=n;i++)
		{	
			last1 = 0;

			if(mmp.find(a[i])!=mmp.end())
				last1 = mmp[a[i]];

			++cnt1;
			lft1[cnt1] = rgt1[cnt1] = 0;

			mmp[a[i]] = cnt1;
			cur1 = cnt1;

			update(cur1,last1,1,n,st[i],i);
		}

		// for(i=1;i<=n;i++)
		// 	cout<<i<<"--"<<st[i]<<" "<<mmp[a[i]]<<"\n";

		// for(i=0;i<=150;i++)
		// 	cout<<i<<" "<<seg[i]<<" "<<lft1[i]<<" "<<rgt1[i]<<"\n";
		// for(i=1;i<=n;i++)
		// 	cout<<i<<" "<<st[i]<<" "<<en[i]<<"\n";

		ll mid,last,cur,par,j;

		for(i=1;i<=n;i++)
		{
			x = mp[i];
			mid = a[x];
			++cnt;
			lft[cnt] = rgt[cnt] = 0;
			root[i] = cnt;
			val[cnt] = i;
			
			last = root[i-1];
			cur = root[i];

			for(j=0;j<21;j++)
			{
				par = (mid>>(20-j))%2;

				++cnt;
				lft[cnt] = rgt[cnt] = 0;
				val[cnt] = i;

				if(par==0)
				{
					lft[cur] = cnt;
					rgt[cur] = rgt[last];

					cur = cnt;
					last = lft[last];
				}
				else
				{
					lft[cur] = lft[last];
					rgt[cur] = cnt;

					cur = cnt;
					last = rgt[last];
				}
			}
		}

		ll vv=0,xx=0,pos;

		// for(i=1;i<=n;i++)
		// 	cout<<root[i]<<"--\n";

		// for(i=0;i<=120;i++)
		// 	cout<<i<<" "<<val[i]<<" "<<lft[i]<<" "<<rgt[i]<<"\n";

		while(q--)
		{
			ll aa,bb,ans=0;
			s(aa); s(bb);
			aa^=vv;
			bb^=xx;

			pos = root[en[aa]];

			for(j=0;j<21;j++)
			{
				par = (bb>>(20-j))%2;
				// cout<<j<<" "<<pos<<" "<<par<<" "<<lft[pos]<<" "<<rgt[pos]<<" "<<val[pos]<<" "<<ans<<"\n";

				if(par==0)
				{
					if(rgt[pos]==0 || val[rgt[pos]]<st[aa])
					{	
						ans = ans*2;
						pos = lft[pos];
					}
					else
					{
						ans = ans*2 + 1;
						pos = rgt[pos];
					}
				}
				else
				{
					if(lft[pos]==0 || val[lft[pos]]<st[aa])
					{	
						ans = ans*2;
						pos = rgt[pos];
					}
					else
					{
						ans = ans*2 + 1;
						pos = lft[pos];
					}
				}
			}

			vv = check(mmp[ans^bb],1,n,st[aa],en[aa]);
			
			if(vv==MOD)
				vv = 0;

			// cout<<vv<<" "<<ans<<"\n";
			printf("%d %d\n",vv,ans);
			xx = ans;
		}
	}

	return 0;
}