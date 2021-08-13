#include <experimental/filesystem>
#include <iostream>
#include "instance_data.h"
using namespace std;
namespace fs = std::experimental::filesystem;
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
    fs::path file_path = instance_path;
    cout<<file_path<<endl;
}