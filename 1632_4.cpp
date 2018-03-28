//
//  main.cpp
//  test
//
//  5

//

//

//输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。

//输入例子1:
//3
//LRR

//输出例子1:
//E

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char change_direction(char a, char b){
    if(a=='N'){
        if(b=='R'){
            return 'E';
        }
        else{
            return 'W';
        }
    }
    else if(a=='S'){
        if(b=='R'){
            return 'W';
        }
        else{
            return 'E';
        }
    }
    else if(a=='W'){
        if(b=='R'){
            return 'N';
        }
        else{
            return 'S';
        }
    }
    else{
        if(b=='R'){
            return 'S';
        }
        else{
            return 'N';
        }
    }
}

char direction(int n,string s){
    char result='N';
    for(int i=0;i<n;i++){
        result=change_direction(result,s[i]);
    }
    
    return result;
}




int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>s[i];
    }
    cout<<direction(N,s)<<endl;
    return 0;
}




