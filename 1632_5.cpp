//
//  main.cpp
//  test
//
//  5

//

//

//牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。

//但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
//牛牛希望你能帮他计算一共有多少个可能的数对。
//注意到当除数是y时，当x=1~n时，余数是1,2,3,...,y-1,0循环出现，循环节长度显然是y
//那么我们可以枚举y=k~n(当y<k时所有余数均小于k，因此不需要考虑)
//然后对于x=1~n，总共出现了[n/y]个循环节，然后数出每个循环节里面不小于k的余数。最后再数出不满一个循环节的不小于k的余数，就是答案了。注意当k=0的时候由于余数0出现在循环的末尾，因此要特别判断。



#include <iostream>


using namespace std;




int main(int argc, const char * argv[]) {
    long long n,k;
    cin>>n>>k;
    long long ans=0;
    for(int y=k;y<=n;++y)
    {
        int res=0;
        res=n/y*(y-k);
        if(n%y>=k)
            if(k)
                res+=n%y-k+1;
            else res+=n%y;
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}




