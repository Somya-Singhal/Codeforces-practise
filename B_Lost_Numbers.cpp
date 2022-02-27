#include<bits/stdc++.h>
using namespace std;

vector<int>p={4,8,15,16,23,42};
int main()
{
  vector<int>ans(4);
  for(int i=0;i<4;i++)
  {
      cout<<"?"<<" "<<i+1<<" "<<i+2<<endl;
      fflush(stdout);
      cin>>ans[i];
  }
  do{
      bool flag=true;
      for(int i=0;i<4;i++)
      flag &= (p[i]*p[i+1]==ans[i]);
      if(flag)
      break;
  }
  while(next_permutation(p.begin(),p.end()));
  cout<<"!";
  for(int i=0;i<6;i++)
  cout<<" "<<p[i];
  cout<<endl;
  fflush(stdout);
  return 0;
}