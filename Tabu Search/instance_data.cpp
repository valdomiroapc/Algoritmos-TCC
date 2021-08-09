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
void instance_data::read_instance(string name)
{
    instance_name = name;
    instance_data::_read_instance();
}
void instance_data::_read_instance()
{
    string path = instance_path + instance_name +".txt";
    FILE *instance_file;
    instance_file = fopen(path.c_str(),"r");
    char buffer[100];
    string file_text;
    if(instance_file == NULL)
        puts("Error opening file");
    else
    {
        while(feof(instance_file))
        {
            if(fgets(buffer, 100,instance_file) == NULL)
                break;
            file_text+=buffer;
        }
    }
    cout<<file_text<<endl;
}