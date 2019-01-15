/* LIS.cpp */

#include <iostream>
#include <vector>
using namespace std;

int currentLISSize;

int findLIS(vector<int> seq){
    
    //cause we find max size of LIS
    if(seq.size() == currentLISSize) return currentLISSize;
    
    //check seq vector is LIS
    bool checkLIS = true;
    for(int i=0; i<seq.size() - 1; ++i){
        if(seq[i] >= seq[i+1]){
            checkLIS = false;
            break;
        }
    }
    
    //base case
    //if(checkLIS) return seq.size();
    
    for(vector<int>::iterator it=seq.begin(); it != seq.end(); ++it){
        int temp = seq.back();
        seq.pop_back();
        //recursive findLIS
        seq.push_back(temp);
    }
    return currentLISSize;
}

int main(void){
    
    int num, N;
    cin >> num;
    
    for(int a=0; a<num; ++a){
        cin >> N;
        vector<int> seq(N);
        for(int i=0; i<N; ++i){
            cin >> seq[i];
        }
        
        currentLISSize = 1;
        cout << findLIS(seq) << endl;
    }
    
    return 0;
}
