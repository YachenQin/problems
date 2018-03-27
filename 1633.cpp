//
//  main.cpp
//  test
//
//  5

//如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
//小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。
//
#include <iostream>
#include <string>

using namespace std;

int transfer(string s){
    int length=(int)s.size();
    if(length==1){
        return 1;
    }
    else{
        int result=0;
        int trans=1;
        for(int i=1;i<length;i++){
            if(s[i]==s[i-1]){
                result=std::max(result,trans);
                trans=1;
            }
            else{
                trans++;
            }
        }
        result=std::max(result,trans);
        return result;
    }
}



int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int a=transfer(s);
    cout<<a;
    return 0;
}
