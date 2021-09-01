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
    int duration;
    solution_representation(int t0,int i,int td)
    {
        initial_time = t0;
        locate = i;
        duration = td;
    }
};
struct segment_tree
{
    vector<int > arv;
    vector<int> lazy;
    int range;
    segment_tree(int dimension)
    {
        arv = vector<int> (4*dimension,0);
        lazy = vector<int> (arv.size(),0);
        range = dimension-1;
    }
    void update_range(int no,int l,int r,int ll,int rr,int v)
    {
        if(lazy[no])
        {
            arv[no] += lazy[no];
            if(l<r)
            {
                lazy[no*2] += lazy[no];
                lazy[no*2+1] += lazy[no];
            }
            lazy[no] = 0;
        }
        if(l>rr or r<ll)
            return; 
        if(l>=ll and r<=rr)
        {
            arv[no] += v;
            if(l<r)
            {
                lazy[no*2] += v;
                lazy[no*2+1] += v;
            }
            return;
        }
        int m = (l+r)/2;
        update_range(no*2,l,m,ll,rr,v);	
        update_range(no*2+1,m+1,r,ll,rr,v);
        arv[no] = max(arv[no*2],arv[no*2+1]);
    }
    int query(int no,int l,int r,int ll,int rr)
    {
        if(l>rr or r<ll)
            return -10;
        if(lazy[no])
        {
            arv[no] += lazy[no];
            if(l<r)
            {
                lazy[no*2] += lazy[no];
                lazy[no*2+1] += lazy[no];
            }
            lazy[no]=0;
        }
        if(l>=ll and r<=rr)
            return arv[no];
        int m = (l+r)/2;
        long long int v1,v2;
        v1=query(no*2,l,m,ll,rr);
        v2=query(no*2+1,m+1,r,ll,rr);
        return max(v1,v2);
    }
    int greater_of_the_interval(int l,int r)
    {
        return query(1,0,range,l,r);
    }
    void add_one_in_the_interval(int l,int r)
    {
        update_range(1,0,range,l,r,1);
    }
    void subtract_one_in_the_interval(int l,int r)
    {
        update_range(1,0,range,l,r,-1);
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
                representation.pb(solution_representation(t,-1,1));
        }
    }
    
};
int main()
{
   
}
