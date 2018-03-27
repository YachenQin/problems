//
//  main.cpp
//  test
//
//  5

//

//

//小易非常喜欢拥有以下性质的数列:
//1、数列的长度为n
//2、数列中的每个数都在1到k之间(包括1和k)
//3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
//例如,当n = 4, k = 7
//那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
//但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。

//使用动态规划。状态dp[i][j]i代表了输出数列的长度（1<=i<=n)，j代表了该数列的最后一个一个数的值（1<=j<=k).
//状态方程：dp[i][j]=dp[i][j]+dp[i-1][m](1<=m<=k)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int const mod=1000000007;

int calculate(int n,int k){
    int dp[n+1][k+1];
    if(n==1){
        return k;
    }
    else{
        for(int i=1;i<k+1;i++){
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;i++){
            int sum=0;
            //计算上一行一共有多少个，因为下一行就等于上一行的总数再进行一些操作
            for(int j=1;j<=k;j++){
               sum=(sum+dp[i-1][j])%mod;
            }
            
            
            //
            for(int j=1;j<=k;j++){
                //先假设上一行每个结果都可以加到现在这个数字的前面
                dp[i][j]=sum;
                
                for(int q=1;q<=k;q++){
                    //如果上一行的结尾比这一行结尾的数字大，或是上一行结尾除这一行结尾余数是零，则减去上一行的数据
                    if(q>j && q%j==0){
                        dp[i][j]=(dp[i][j]-dp[i-1][q]+mod)%mod;
                    }
                }
            }
        }
        
        int res=0;
        for(int i=1;i<=k;i++) {
           res=(res+dp[n][i])%mod;
        }
        return res;
    }
}



int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    cout<<calculate(n,k);
    return 0;
}
