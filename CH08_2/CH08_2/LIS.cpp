/* LIS.cpp */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int S[500], cache[501], N;

int findLIS(int start){
    //memoization
    int &ret = cache[start + 1];
    if(ret != -1) return ret;
    
    ret = 1;
    for(int next = start + 1; next <N; ++next){
        if(start == -1 || S[start] < S[next]){
            ret = max(ret, findLIS(next) + 1);
        }
    }
    return ret;
}

int main(void){
    
    int num;
    cin >> num;
    
    for(int a=0; a<num; ++a){
        cin >> N;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<N; ++i){
            cin >> S[i];
        }
        
        //search all indices
        int start = -1;
        cout << findLIS(start) - 1 << endl;
    }
    
    return 0;
}
