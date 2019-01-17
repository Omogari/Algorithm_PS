/* PI.cpp */

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string N;
int cache[10000];
const int INF = 987654321;

int checkDifficulty(string N){
    if(N.length() <= 2) return INF;
    
    //dificulty 1
    bool check = true;
    for(int i=0; i<N.length(); ++i){
        if(N[i] != N[0]){
            check = false;
            break;
        }
    }
    if(check) return 1;
    
    //difficulty 2, 5
    check = true;
    for(int i=0; i<N.length() - 2; ++i){
        if(N[i+2] - N[i+1] != N[i+1] - N[i]){
            check = false;
            break;
        }
    }
    if(check){
        if(N[1] - N[0] == 1 || N[1] - N[0] == -1) return 2;
        else return 5;
    }
    
    //difficulty 4
    check = true;
    for(int i=0; i<N.length()-2; i += 2){
        if(N[i+2] != N[i]){
            check = false;
            break;
        }
    }
    for(int i=1; i<N.length()-2; i += 2){
        if(N[i+2] != N[i]){
            check = false;
            break;
        }
    }
    if(check) return 4;

    return 10;
}

int sumOfDifficulty(int idx){
    //memoization
    int &ret = cache[idx];
    if(ret != -1) return ret;
    
    //base case
    if(N.substr(idx).length() <= 5)
        return ret = checkDifficulty(N.substr(idx));
    
    ret = INF;
    for(int i=3; i<=5; ++i){
        ret = min(ret, checkDifficulty(N.substr(idx, i)) + sumOfDifficulty(idx + i));
    }
    return ret;
}

int main(void){
    
    int num;
    cin >> num;
    for(int a=0; a<num; ++a){
        cin >> N;
        memset(cache, -1, sizeof(cache));
        cout << sumOfDifficulty(0) << endl;
    }
    
    return 0;
}
