//
//  main.cpp
//  test
//
//  5

//

//

//平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i], y2[i])。

//如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。

//请你计算出平面内重叠矩形数量最多的地方,有多少个矩形相互重叠。

//输入包括五行。
//第一行包括一个整数n(2 <= n <= 50), 表示矩形的个数。
//第二行包括n个整数x1[i](-10^9 <= x1[i] <= 10^9),表示左下角的横坐标。
//第三行包括n个整数y1[i](-10^9 <= y1[i] <= 10^9),表示左下角的纵坐标。
//第四行包括n个整数x2[i](-10^9 <= x2[i] <= 10^9),表示右上角的横坐标。
//第五行包括n个整数y2[i](-10^9 <= y2[i] <= 10^9),表示右上角的纵坐标。



#include <iostream>


using namespace std;

int over(int n,int *x_1,int *y_1,int *x_2,int *y_2){
    
    int x[2*n];
    int j=0;
    for(int i=0;i<n;i++){
        x[j]=x_1[i];
        x[j+1]=x_2[i];
        j+=2;
    }
    
    int y[2*n];
    int k=0;
    for(int i=0;i<n;i++){
        x[k]=y_1[i];
        x[k+1]=y_2[i];
        k+=2;
    }
    
    
    
    
    return 1;
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int *x_1;
    int *y_1;
    int *x_2;
    int *y_2;
    for(int i=0;i<n;i++){
        cin>>x_1[i];
    }
    for(int i=0;i<n;i++){
        cin>>y_1[i];
    }
    for(int i=0;i<n;i++){
        cin>>x_2[i];
    }
    for(int i=0;i<n;i++){
        cin>>y_2[i];
    }
    
    
}




