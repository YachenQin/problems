//
//  main.cpp
//  test
//
//  5
//小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
//1、将a_i放入b序列的末尾
//2、逆置b序列
//小易需要你计算输出操作n次之后的b序列。
//
#include <iostream>
#include<vector>

using namespace std;

vector<int> transfer(vector<int> s){
    
    vector<int> result;
    int length=(int)s.size();
    
    for(int i=length-1;i>=0;i--){
        result.push_back(s[i]);
    }
    
    return result;
}

vector<int> move(int a,vector<int> s){
    
    vector<int> result;
    int i=0;
    while(i<s.size()){
        if(i==a){
            i++;
        }
        else{
            result.push_back(s[i]);
            i++;
        }
    }
    result.push_back(s[a]);
    return result;
}

vector<int> final(int a,vector<int> s){
    
    for(int i=0;i<a;i++){
        s=move(i,s);
        s=transfer(s);
    }
    
    return s;
}




int main(int argc, const char * argv[]) {
    int count;
    cin>>count;
    vector<int> s;
    for(int i=0;i<count;i++){
        int number;
        cin>>number;
        s.push_back(number);
    }
    vector<int> result;
    result=final(count,s);
    for(int i=0;i<count;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
