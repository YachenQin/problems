//
//  main.cpp
//  test
//
//  5

//

//

//

//牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
//牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
//牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int how_much(vector<int> v, int n, int w){
    int package=0;
    int count=0;
    for(int i=0;i<n;i++){
        package=package+v[i];
        if(package>w){
            count=i;
            break;
            
        }
    }
    if(count==0){
        return pow(2,n);
    }
    else{
        int invalid=n-count;
        int minus=pow(2,invalid)-1;
        return pow(2,n)-minus;
        
    }

}





int main(int argc, const char * argv[]) {
    int n,w;
    cin>>n>>w;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    std::sort(v.begin(),v.end());
    
    cout<<how_much(v,n,w);
    
    
}




