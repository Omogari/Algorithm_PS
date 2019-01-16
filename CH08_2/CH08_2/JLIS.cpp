/* LIS.cpp */

#include <iostream>
using namespace std;

int N[100], M[100];

int findJLIS(int start){
    
    
    return 0;
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
        
        int start = 0;
        cout << findJLIS(start) << endl;
    }
    return 0;
}
