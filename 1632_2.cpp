//
//  main.cpp
//  test
//
//  5

//

//

//小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

//并且小Q对于能否被3整除这个性质很感兴趣。

//小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。


//输入描述:
//输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。


//输出描述:
//输出一个整数, 表示区间内能被3整除的数字个数。

#include <iostream>


using namespace std;

bool can_be_divide(int a){
    
    if(a%3==0 || (a+1)%3==0){
        return true;
    }
    else{
        return false;
    }
}


int result(int l, int r){
    
    int res=0;
    for(int i=l;i<=r;i++){
        if(can_be_divide(i)){
            res++;
        }
    }
    return res;
    
}




int main(int argc, const char * argv[]) {
    int l,r;
    cin>>l>>r;
    int res=result(l,r);
    cout<<res;
    return 0;
}




