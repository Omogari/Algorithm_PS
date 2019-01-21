/* LIS.cpp */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, M[100], N[100];
int cache[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int findJLIS(int indexM, int indexN){
    //memoization
    int &ret = cache[indexM + 1][indexN + 1];
    if(ret != -1) return ret;
    
    ret = 0;
    long long a = (indexM == -1 ? NEGINF : M[indexM]);
    long long b = (indexN == -1 ? NEGINF : N[indexN]);
    long long maxElement = max(a, b);
    
    for(int nextM = indexM + 1; nextM < m; ++nextM){
        if(maxElement < M[nextM])
            ret = max(ret, findJLIS(nextM, indexN) + 1);
    }
    for(int nextN = indexN + 1; nextN < n; ++nextN){
        if(maxElement < N[nextN])
            ret = max(ret, findJLIS(indexM, nextN) + 1);
    }
    
    return ret;
}

int main(void){
    int num;
    cin >> num;
    
    for(int a=0; a<num; ++a){
        cin >> m >> n;
        
        for(int i=0; i<m; ++i){
            cin >> M[i];
        }
        for(int i=0; i<n; ++i){
            cin >> N[i];
        }
        memset(cache, -1, sizeof(cache));
        cout << findJLIS(-1, -1) << endl;
    }
    return 0;
}
