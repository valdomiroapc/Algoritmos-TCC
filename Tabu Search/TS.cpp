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
    vector< vector<double> > distance;
    vector<int>facility_duration;
    vector<vector<int> >clients;
    void read_instance()
    {
        scanf("%d%d%d%d",&V,&T,&L,&K);
        int x;
        for(int i=0;i<V;i++)
        {
            vector<double>line;
            double y;
            for(int j=0;j<V;j++)
            {
                scanf("%lf",&y);
                line.pb(y);
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
                printf("%lf ",distance[i][j]);
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
    vector< segment_tree > facilities_in_time_info;
    segment_tree *time_frame;
    vector< vector<pair<double,int> > > connection_matrix;
    double objective_distance;
    bool is_invalid;
    void fill_connection_matrix()//O(V²logV)
    {
        for(int i=0;i<data.V;i++)
        {
            vector<pair<double,int> > connection_list;
            for(int j=0;j<data.V;j++)
            {
                if(i == j)
                    continue;
                connection_list.pb({data.distance[i][j],j});
            }
            sort(connection_list.begin(),connection_list.end());
            connection_matrix.pb(connection_list);
        }
    }
    solution(dataset &current_data)//O((V*T)+(V²logV))
    {
        data = current_data;
        time_frame = new segment_tree(data.T);
        for(int i=0;i<data.V;i++)
            facilities_in_time_info.pb(segment_tree(data.T));
        is_invalid = false;
        objective_distance = 100000000.0;
        fill_connection_matrix();
    }
    bool is_facility_open_in_interval(int v,int l,int r)//O(logT)
    {
        return facilities_in_time_info[v].greater_of_the_interval(l,r);
    }
    void open_facility_in_interval(int v,int l,int r)//O(logT)
    {
        facilities_in_time_info[v].add_one_in_the_interval(l,r);
    }
    void close_facility_in_interval(int v,int l,int r)//O(logT)
    {
        facilities_in_time_info[v].subtract_one_in_the_interval(l,r);
    }
    bool open_facility(int instant,int facility_idx,int facility_type_idx)//O(logT)
    {
        int duration = data.facility_duration[facility_type_idx];
        int final_instant = min(instant+duration-1,data.T-1);
        if(is_facility_open_in_interval(facility_idx,instant,final_instant))
            return false;
        
        int number_of_open_facilities = time_frame->greater_of_the_interval(instant,final_instant);
        if(number_of_open_facilities > data.K)
            return false;
        time_frame->add_one_in_the_interval(instant,final_instant);
        open_facility_in_interval(facility_idx,instant,final_instant);
        return true;
    }
    bool close_facility(int instant,int facility_idx,int facility_type_idx)//O(logT)
    {
        int duration = data.facility_duration[facility_type_idx];
        int final_instant = min(instant+duration-1,data.T-1);
        if(!is_facility_open_in_interval(facility_idx,instant,final_instant))
            return false;
        int number_of_open_facilities = time_frame->greater_of_the_interval(instant,final_instant);
        if(!number_of_open_facilities)
            return false;
        time_frame->subtract_one_in_the_interval(instant,final_instant);
        close_facility_in_interval(facility_idx,instant,final_instant);
        return true;
    }
    bool is_facility_open_at_instant_t(int v,int t)//O(logT)
    {
        return facilities_in_time_info[v].greater_of_the_interval(t,t);
    }
    double objective_function()//O(T*V²)
    {
        double invalid_value = 1000000000.0;
        int size = connection_matrix[0].size();
        double objective_value = 0.0;
        for(int t=0;t<data.T;t++)
        {
            for(int c:data.clients[t])
            {
                bool has_facility = false;
                for(int v=0;v<size;v++)
                {
                    if(is_facility_open_at_instant_t(connection_matrix[c][v].second,t))
                    {
                        objective_value = max(objective_value,connection_matrix[c][v].first);
                    }
                }
                if(!has_facility)
                {
                    is_invalid = true;
                    return invalid_value;
                }
            }
        }
        is_invalid = false;
        return objective_value;
    }
};
struct Neighborhood
{
    dataset data;
    solution current_solution;
    Neighborhood(dataset &current_data, solution &initial_solution)
    {
        data=current_data;
        current_solution=initial_solution;
    }
    void neighborhood_open_facility()
    {
        vector< pair<double, pair<int,pair<int,int> > > > neighborhood;
        for(int t=0;t<data.T;t++)
        {
            for(int v=0;v<data.V;v++)
            {
                for(int l=0;l<data.L;l++)
                {
                    current_solution.open_facility(t,v,l);
                    double objective_value = current_solution.objective_function();
                    if(current_solution.is_invalid or objective_value<current_solution.objective_distance)
                        neighborhood.pb({objective_value,{t,{v,l}}});
                    current_solution.close_facility(t,v,l);
                }
            }
        }
        for(int i=0;i<)
    }
};

struct VNS
{

};
int main()
{

}
