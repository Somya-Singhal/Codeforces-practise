#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    vector<int>smaller(n+4),bigger(n+4);
    for(int i=1;i<=n;i++)
    {
         smaller[i]=smaller[i-1]+freq[i-1];
    }
    for(int i=n;i>=0;i--)
    {
         bigger[i]=bigger[i+1]+freq[i+1];
    }
    int low=0,hi=n-1;
    int X,Y;
    while(low<=hi)
    {
        bool curr=false;
        int mid=(low+hi)/2;
        for(int x=1;x<=n;x++)
        {
            int y=x+mid;
            if(y>n)
            {
                   break;
            }
            int extra=smaller[x]+bigger[y];
            int inrange=n-extra;
            if(inrange-extra>=k)
            {
               X=x,Y=y;
               curr=true;
               break;
            }
        }
        if(curr)
            {
                hi=mid-1;
            }
            else
            {
                 low=mid+1;
            }
    }
    vector<int>idx;
    idx.push_back(-1);
    int presum=0,target=1;
    for(int i=0;i<n && target<k;i++)
    {
        if(arr[i]>=X && arr[i]<=Y)
        presum++;
        else
        presum--;
        if(presum==target)
        {
            idx.push_back(i);
            target++;
        }
    }
    idx.push_back(n-1);
    cout<<X<<" "<<Y<<endl;
    for(int i=1;i<(int)idx.size();i++)
    {
        cout<<idx[i-1]+2<<" "<<idx[i]+1<<endl;
    }
 }
 return 0;
}