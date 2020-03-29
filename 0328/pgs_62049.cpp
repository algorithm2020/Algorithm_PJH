#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> cp;
    answer.push_back(0);
    for(int i =1 ; i<n; i++){
        cp.assign(answer.begin(), answer.end());
        answer.push_back(0);
        
        while(!cp.empty()){
            int val = cp.back();
            cp.pop_back();
            
            if(val == 1){
                answer.push_back(0);
            }
            else{
                answer.push_back(1);
            }
        }
    }
    
    return answer;
}