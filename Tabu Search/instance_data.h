#include <experimental/filesystem>
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
struct instance_data
{
    int T,V,L,k;
    vector< vector<int> >d;
    vector< int > delta;
    vector< int > Dt;
    string instance_name;
    fs::path instance_path = U"C:\\Users\\valdo\\OneDrive\\Área de Trabalho\\TCC\\Algoritmos TCC\\Instâncias LKC\\inst0.txt";
    void read_instance(string name);
    void _read_instance();
};