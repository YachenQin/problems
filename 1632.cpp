//
//  main.cpp
//  test
//
//  5

//如果一个数列S满足对于所有的合法的i,都有S[i + 1] = S[i] + d, 这里的d也可以是负数和零,我们就称数列S为等差数列。
//小易现在有一个长度为n的数列x,小易想把x变为一个等差数列。小易允许在数列上做交换任意两个位置的数值的操作,并且交换操作允许交换多次。但是有些数列通过交换还是不能变成等差数列,小易需要判别一个数列是否能通过交换操作变成等差数列。
//
#include <iostream>
#include <string>
#include <set>

using namespace std;

void transfer(int a,int *b){
    set<int> myset;
    set<int>::iterator it;
    for(int i=0;i<a;i++){
        myset.insert(b[i]);
    }
    if(myset.size()==1){
        cout<<"Possible";
    }
    else if(myset.size()<a){
        cout<<"Impossible";
    }
    else{
        int new_b[a];
        int i=0;
        for(it=myset.begin();it!=myset.end();it++){
            new_b[i]=*it;
            i++;
        }
        
        int trans=new_b[1]-new_b[0];
        for(int j=0;j<a-1;j++){
            int minus=new_b[j+1]-new_b[j];
            if(minus!=trans){
                cout<<"Impossible";
                return;
            }
        }
        cout<<"Possible";
        
    }
}



int main(int argc, const char * argv[]) {
    int a;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++ ){
        cin>>b[i];
    }
    transfer(a,b);
    return 0;
}
