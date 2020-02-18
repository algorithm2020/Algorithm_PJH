#include <iostream>
#include <algorithm>
#include <vector>

int total;
std::vector<std::pair<int,int> > arr;
std::vector<int> res;
bool visited[201];


void operate(int pre,int cur, std::vector<std::pair<int,int> > arrr){

    if(arrr[0].second == 0){
        res.push_back(arrr[0].second);
    }
    std::vector<std::pair<int,int> > temp = arrr;
    for(int i =0; i< 3; i++){
        if(i == pre) continue;
        else if(i == cur) continue;
        
        int remain = temp[cur].second - (temp[i].first - temp[i].second);
        if(remain > 0){
            temp[i].second = temp[i].first;
            temp[cur].second = remain;
        }
        else{
            temp[i].second += temp[cur].second;
            temp[cur].second = 0;
        }
        operate(cur, i, temp);
    }
    if(arrr[2].second == total){
        return;
    }
}

int main(){

    std::cin >> arr[0].first >> arr[1].first >> arr[2].first;

    arr[0].second = 0;
    arr[1].second = 0;
    arr[2].second = arr[2].first;

    total = arr[2].first;

    operate(1,0, arr);
    operate(0,1, arr);

    for(int i =0; i < res.size(); i++){
        std::cout << res[i]<< ' ' << "res";
    }

    return 0;
}