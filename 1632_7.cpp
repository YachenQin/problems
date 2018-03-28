//
//  main.cpp
//  test
//
//  5

//

//

//

//每个输入包含一个测试用例。
//每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
//接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
//接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
//接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
//数据保证至少有一个闹钟可以让牛牛及时到达教室。



#include <iostream>
#include <vector>


using namespace std;


int time_minus(vector<int> classtime,vector<int> weaktime){
    vector<int> result;
    int classhour=classtime[0];
    int weakhour=weaktime[0];
    int classmin=classtime[1];
    int weakmin=weaktime[1];
    if(classmin<weakmin){
        result.push_back(classhour-weakhour-1);
        result.push_back(60-(weakmin-classmin));
    }
    else{
        result.push_back(classhour-weakhour);
        result.push_back(classmin-weakmin);
        
    }
    
    int res=result[0]*60+result[1];
    return res;
    
}

void compare(vector<vector<int>> out,int n,int x,vector<int> classtime){
    int min=100;
    int minus=0;
    int tick=0;
    for(int i=0;i<n;i++){
        minus=time_minus(classtime,out[i])-x;
        if(minus>=0) {
            if(minus<min){
                min=minus;
                tick=i;
            }
        }
    }
    
    vector<int> res=out[tick];
    
    for(int i=0;i<2;i++){
        cout<<res[i]<<" ";
    }
    
}




int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<vector<int>> out;
    for(int i=0;i<n;i++){
        vector<int> clock;
        int a,b;
        cin>>a>>b;
        clock.push_back(a);
        clock.push_back(b);
        out.push_back(clock);
    }
    int x;
    cin>>x;
    vector<int> classtime;
    int a,b;
    cin>>a>>b;
    classtime.push_back(a);
    classtime.push_back(b);
    compare(out, n, x, classtime);
    
    
}




