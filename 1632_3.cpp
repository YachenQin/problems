//
//  main.cpp
//  test
//
//  5

//

//

//小Q正在给一条长度为n的道路设计路灯安置方案。

//为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。

//小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。

//小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。


//输入描述:
//输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
//接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
//第二行一个字符串s表示道路的构造,只包含'.'和'X'。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void light_number(int a,string s){
    
    int res=0;
    int count=0;
    for(int i=0;i<a;i++){
        if(s[i]!='X'){
            count++;
        }
        else{
            if(count%3>0){
                count++;
            }
        }
    }
    if(count%3==0){
        res=count/3;
    }
    else{
        res=count/3+1;
    }

    cout<<res<<endl;
}





int main(int argc, const char * argv[]) {
    //int t;
    //cin>>t;
    
    //int a[t];
    //vector<string> s;
    
    //for(int i=0;i<t;i++){
      //  cin>>a[i];
        //string str;
        //cin>>str;
        //s.push_back(str);
        
   // }
 //   for(int i=0;i<t;i++){
   //   light_number(a[i],s[i]);
    //}
    string s=".X...X.....XX...X...XX.X....X..X.X.X..XX....X.X........X.....XX..XX.X.X.X..X.X.XX...X...";
    light_number(88,s);
    return 0;
}




