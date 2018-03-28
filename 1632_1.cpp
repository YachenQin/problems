//
//  main.cpp
//  test
//
//  5

//

//

//为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。

//通过率不完全

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void do_my_job (vector<vector<int>> salary,int *ability,int n, int m){
    map<int,int> job;
    map<int,int>::iterator it;
    
    map<int,int> job_1;
    map<int,int>::iterator it_1;
    
    
    for(int i=0;i<n;i++){
        int a=salary[i][0];//工作量
        int b=salary[i][1];//报酬
        
        if(job.begin()==job.end()){
            job[b]=a;
        }
        else{
            it=job.end();
            it--;
            if(b>(it->first)){
                job[b]=a;
                if(a<=it->second){
                    job.erase(it);
                }
            }
            else{
                if(a<it->second){
                    job[b]=a;
                }
            }
        }
    }
    
    for(it=job.begin();it!=job.end();it++){
        if(job_1.begin()==job_1.end()){
            job_1[it->second]=it->first;
        }
        else{
            it_1=job_1.end();
            it_1--;
            if(it->second>it_1->first && it->first<it_1->second){
                job_1.erase(it_1);
            }
            job_1[it->second]=it->first;
        }
        
        
    }
    
    for(int i=0;i<m;i++){
        int power=ability[i];
        if(job_1.find(power)!=job_1.end()){
            int res=job_1[power];
            cout<<res;
        }
        else{
            it=job_1.upper_bound(power);
            it--;
            int res=it->second;
            cout<<res;
        }
    }
}


int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> salary;
    for(int i=0;i<n;i++){
        int a,b;
        vector<int> each;
        cin>>a>>b;
        each.push_back(a);
        each.push_back(b);
        salary.push_back(each);
    }
    
    int *ability=new int[m];
    for(int i=0;i<m;i++){
        cin>>ability[i];
    }
    
    do_my_job(salary,ability,n,m);
    return 0;
}




