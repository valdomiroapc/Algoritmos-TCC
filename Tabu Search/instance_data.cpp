#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "instance_data.h"
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mp make_pair
#define fast_io cin.tie(0), cin.sync_with_stdio(false);
#define PI 3.14159265359
#define eps 1e-9
#define unvisited -1
typedef vector<int>vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef pair<int, string> istr;
typedef vector<istr> vistr;
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
void instance_data::read_instance()
{
    cin>>V>>T>>L>>k;
    for(int i=0;i<V;i++)
    {
        vector<int>linha;int x;
        for(int j=0;j<V;j++)
        {
            cin>>x;
            linha.pb(x);
        }
        d.pb(linha);
    }
    int x;
    for(int i=0;i<L;i++)
    {
        cin>>x;
        delta.pb(x);
    }
    for(int i=0;i<T;i++)
    {
        int dt;
        cin>>dt;
        vector<int> client;
        for(int j=0;j<dt;j++)
        {
            cin>>x;
            client.pb(x);
        }
        clients_at_time_t.pb(client);
    }
}
void instance_data::print_instance()
{
    printf("%d %d %d %d\n\n",V,T,L,k);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            printf("%d ",d[i][j]);
        puts("");
    }
    puts("");
    for(int i=0;i<L;i++)
        printf("%d ",delta[i]);
    puts("\n");
    for(int i=0;i<T;i++)
    {
        printf("%d",(int)clients_at_time_t.size());
        for(int j=0;j<(int)clients_at_time_t.size();j++)
            printf(" %d",clients_at_time_t[i][j]);
        puts("");
    }
}