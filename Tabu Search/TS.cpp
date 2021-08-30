#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
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
struct dataset
{
    int V,T,L,K;
    vector< vector<int> > distance;
    vector<int>facility_duration;
    vector<vector<int> >clients;
    void read_instance()
    {
        scanf("%d%d%d%d",&V,&T,&L,&K);
        int x;
        for(int i=0;i<V;i++)
        {
            vector<int>line;
            for(int j=0;j<V;j++)
            {
                scanf("%d",&x);
                line.pb(x);
            }
            distance.pb(line);
        }
        for(int i=0;i<L;i++)
        {
            scanf("%d",&x);
            facility_duration.pb(x);
        }
        for(int i=0;i<T;i++)
        {
            int number_clients;
            scanf("%d",&number_clients);
            vector<int> line;
            for(int j=0;j<number_clients;j++)
            {
                scanf("%d",&x);
                line.pb(x);
            }
            clients.pb(line);
        }
    }
    void print_instance()
    {
        printf("%d %d %d %d\n\n",V,T,L,K);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                printf("%d ",distance[i][j]);
            puts("");
        }
        puts("");
        for(int i=0;i<L;i++)
            printf("%d ",facility_duration[i]);
        puts("\n");
        for(int i=0;i<T;i++)
        {
            for(int j=0;j<clients[i].size();j++)
                printf("%d ", clients[i][j]);
            puts("");
        }
    }
};
struct solution_representation
{
    int initial_time;
    int locate;
    int facility_type;
    solution_representation(int t0,int i,int l)
    {
        initial_time = t0;
        locate = i;
        facility_type = l;
    }
};
struct solution
{
    dataset data;
    vector <solution_representation> representation;
    solution(dataset current_data)
    {
        data = current_data;
        for(int t=0;t<data.T;t++)
        {
            for(int k=0;k<data.K;k++)
                representation.pb(solution_representation(t,-1,-1));
        }
    }
};
int main()
{
    dataset data;
    data.read_instance();

}
