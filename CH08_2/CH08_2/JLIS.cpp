/* LIS.cpp */

#include <iostream>
#include <cstring>
using namespace std;

int N[100], M[100];
int cache[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int findJLIS(int indexN, int indexM){
    //memoization
    int &ret = cache[indexM + 1][indexN + 1];
    if(ret != -1) return ret;
    
    ret = 2;
    
    
    
    return ret;
}

int main(void){
    int num;
    cin >> num;
    
    for(int a=0; a<num; ++a){
        int n, m;
        cin >> n >> m;
        
        for(int i=0; i<n; ++i){
            cin >> N[i];
        }
        for(int i=0; i<m; ++i){
            cin >> M[i];
        }
        memset(cache, -1, sizeof(cache));
        cout << findJLIS(-1, -1) << endl;
    }
    return 0;
}
