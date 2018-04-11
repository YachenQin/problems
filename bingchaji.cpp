//
//  main.cpp
//  codebeauty
//
//  Created by 秦雅琛 on 2018/3/28.
//  Copyright © 2018年 秦雅琛. All rights reserved.
//



#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1100
#define INF 0x3f3f3f3f
using namespace std;
using namespace std;
int par[maxn];
int n,m;
int ran[maxn];

//初始化所有节点，暂时设置每个节点的父节点是自己，也就是说这些节点都不相连
void init(){
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
}

//寻找一个特定数字的根节点。
int find (int x){
    if(x == par[x]){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

void join(int a,int b){
    int roota=find(a);
    int rootb=find(b);
    if(roota!=rootb){
        if(ran[roota]<ran[rootb]){
            par[roota]=rootb;
        }
        else{
            par[rootb]=roota;
            if(ran[roota]==ran[rootb]){
                ran[roota]++;
            }
        }
    }
}



int main(int argc, char *argv[])
{
    int a;
    cin>>a;
    n=a;
    init();
    for(int i=1;i<a;i++){
        int a,b;
        cin>>a>>b;
        join(a,b);
    }
    
    return 0;
}

