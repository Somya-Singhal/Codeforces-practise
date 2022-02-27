#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(): val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right) {}
};

TreeNode* buildTree(int s,int e,vector<int>& permute)
{
    if(s>=e)
    return NULL;
    int t_max=permute[s];
    int idx=s;
     for(int i=s;i<e;i++)
     {
         if(permute[i]>t_max)
         {
             t_max=permute[i];
             idx=i;
         }
     }
     TreeNode* root=new TreeNode(t_max);
     root->left=buildTree(s,idx,permute);
     root->right=buildTree(idx+1,e,permute);
     return root;
}

int main()
{
 int t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     int n;
     cin>>n;
     vector<int>permute(n);
     for(int &i:permute)
     cin>>i;
     vector<int>depth;
     TreeNode* root=buildTree(0,n,permute);
     queue<TreeNode*>q;
     unordered_map<int,int>findDepth;
     q.push(root);
    int level=0;
     while(!q.empty())
     {
         int len=q.size();
         for(int i=0;i<len;i++)
         {
             TreeNode* curr=q.front();
             q.pop();
             findDepth[curr->val]=level;
             if(curr->left)
             q.push(curr->left);
             if(curr->right)
             q.push(curr->right);
         }
         level++;
     }
    for(int i=0;i<n;i++)
    {
        int val=findDepth[permute[i]];
        depth.push_back(val);
    }
    for(int i=0;i<n;i++)
    {
        cout<<depth[i]<<" ";
    }
    cout<<endl;
 }
 return 0;
}
