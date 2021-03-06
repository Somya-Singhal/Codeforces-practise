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
 int C;
 cin>>C;
 cout<<C;
 vector<string>like,dislike;
 for(int i=0;i<C;i++)
 {
     cin>>like[i];
     cin>>dislike[i];
     cout<<like[i];
     cout<<dislike[i];
 }
 unordered_map<string,int>m;
 for(int i=0;i<C;i++)
 {
     string s1=like[i];
     int num1=s1.find(" ");
     string first1=s1.substr(0,num1);
     int no1=atoi(first1.c_str());
     cout<<no1<<" ";
     while(no1>0){
         string item=s1.substr(0,s1.find(" "));
         m[item]++;
         no1--;
     }
     string s2=dislike[i];
     int num2=s2.find(" ");
     string first2=s2.substr(0,num2);
     int no2=atoi(first2.c_str());
     cout<<no2<<" ";
     while(no2>0){
         string item=s2.substr(0,s2.find(" "));
         m[item]--;
         no2--;
     }
 }
 vector<string>itemsList;
 for(auto &x: m)
 {
     if(x.second>0){
        itemsList.push_back(x.first);
     }
 }
 cout<<itemsList.size()<<" ";
 for(int i=0;i<itemsList.size();i++)
 cout<<itemsList[i]<<" ";
 cout<<"\n";
 return 0;
}