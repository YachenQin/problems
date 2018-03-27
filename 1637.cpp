//
//  main.cpp
//  test
//
//  5

//

//小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死。

//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int calculate(int a,int *student){
    int result = 0;
    if(a==1){
        return student[0];
    }
    else if(a==2){
        return student[1]-student[0];
    }
    else{
        int left=a-2,right=a-1;
        int m=0,count=0;
        sort(student,student+a);
        while(m<=left){
            if(count%2==0){
                result=result+student[left]-student[m]+student[right]-student[m];
                m++;
                left--;
                count++;
            }
            else{
                result=result+student[left]-student[m]+student[right]-student[m];
                m++;
                right--;
                left--;
                count++;
            }
        }
        
        return result;
    }
}

int main(int argc, const char * argv[]) {
    int a;
    cin>>a;
    int student[a];
    for(int i=0;i<a;i++){
        cin>>student[i];
    }
    cout<<calculate(a, student);
    return 0;
}
