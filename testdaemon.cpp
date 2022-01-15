#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'winOverDemon' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cards
 *  2. INTEGER_ARRAY queries
 */

vector<int> winOverDemon(vector<int> cards, vector<int> queries) {
    int n=cards.size();
int maxsum=INT_MIN,neg=0,pos=0;
    for(int i=0;i<n;i++)
    {
    if(cards[i]<0)
    neg+=cards[i];
    else if(cards[i]>0)
    pos+=cards[i];
    }
    maxsum=max(neg,pos);
    int dp[n+1][maxsum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<maxsum+1;j++)
        {
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxsum;j++)
        {
            if(cards[i-1]<=j)
            dp[i][j]=dp[i-1][j-cards[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    int m=queries.size();
    vector<int>res;
    for(int i=0;i<m;i++)
    {
        int currsum=dp[n][0];
        for(int j=1;j<=maxsum;j++)
        {
            if(maxsum%queries[i]==0)
            currsum+=dp[n][maxsum];
        }
        res.push_back(currsum);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cards_count_temp;
    getline(cin, cards_count_temp);

    int cards_count = stoi(ltrim(rtrim(cards_count_temp)));

    vector<int> cards(cards_count);

    for (int i = 0; i < cards_count; i++) {
        string cards_item_temp;
        getline(cin, cards_item_temp);

        int cards_item = stoi(ltrim(rtrim(cards_item_temp)));

        cards[i] = cards_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = winOverDemon(cards, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
