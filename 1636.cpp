//
//  main.cpp
//  test
//
//  5

//

//小易将n个棋子摆放在一张无限大的棋盘上。第i个棋子放在第x[i]行y[i]列。同一个格子允许放置多个棋子。每一次操作小易可以把一个棋子拿起并将其移动到原格子的上、下、左、右的任意一个格子中。小易想知道要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数.

//
#include <iostream>
#include <string>
#include <set>

using namespace std;


int helper(int a,int *b_x,int *b_y){
    set<int> x;
    set<int> y;
    set<int>::iterator it_x;
    set<int>::iterator it_y;
    if(a==1){
        return 0;
    }
    else if(a==2){
        return abs(b_x[1]-b_x[0])+abs(b_y[1]-b_y[0]);
    }
    
    
    else{
        for(int i=1;i<a-1;i++){
            int result_x=0;
            int result_y=0;
            for(int j=0;j<a;j++){
                result_x+=abs(b_x[j]-b_x[i]);
                result_y+=abs(b_y[j]-b_y[i]);
            }
            x.insert(result_x);
            y.insert(result_y);
        }
        it_x=x.begin();
        it_y=y.begin();
        int res_x=*it_x;
        int res_y=*it_y;
        return res_x+res_y;
    }
}

int main(int argc, const char * argv[]) {
    int a;
    cin>>a;
    int b_x[a];
    int b_y[a];
    for(int i=0;i<a;i++){
        cin>>b_x[i];
    }
    for(int i=0;i<a;i++){
        cin>>b_y[i];
    }
    for(int i=1;i<a+1;i++){
        int result;
        result=helper(i,b_x,b_y);
        cout<<result;
    }
    return 0;
}
