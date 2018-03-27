//
//  main.cpp
//  alibaba
//
//
//阿里巴巴在线编程题；
//小允因为自己要去做VR创业,但创业资金还缺6万元启动资金,于是某日小允分别向他的同学小波,小钱两位同学共借了6万元(每人3万元),并且答应各位同学从还款日起,每天还10000元给各位,3天还完,因为大家都是同学,为了支持小允的创业,就都免去小允的利息,同时还向三位同学提到后续可能还会向大家借钱,但后续都会给利息。小钱是一个工程师,希望通过这次小允借钱的过程来给小允记录一个失信分,而这个分值用来作为他们后续是否借钱给小允的一个评判依据,如果失信分>3则认为风险较高,不宜借钱,否则下次仍可继续借钱。
//失信分的计算规则如下：(从还款日起,如果有一天没有按时还款给相应借款人,则记为逾期)
//(1)如果逾期则记失信分+1,每个借款人单独算,以次类推
//(2)如果小允同时在一天内对两个借款人都逾期,则失信分+1
//(3)如果小允连续3天都逾期,则失信分+1
//三种规则可累加计算
//小允得知该规则后,他希望你能帮助他输入对应失信分(<=3)即可列出对应的逾期情况.


//输入:
//第一行： repay_start_day(还款起始日,格式yyyymmdd) break_faith_score(失信分，取值范围0-5)
//输出:
//失信分对应的输出每种逾期分布

//20170730
//0
//输出范例:
//失信分:0
//情况1:20170730-小波(正常),20170730-小钱(正常),20170731-小波(正常),20170731-小钱(正常),20170801-小波(正常),20170801-小钱(正常)





#include <iostream>
using namespace std;


void transfromdate(int yymmdd, int *date){
    date[0]=yymmdd/10000;
    date[1]=(yymmdd/100)%100;
    date[2]=(yymmdd/100);
}

bool is_leap_year(int y){
    if((y%4 ==0 && y%100 !=0)|| y%400 ==0){
        return true;
    }
    else{
        return false;
    }
}

void date_add_one(int *date){
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap_year(date[0])){
        month[1]=29;
    }
    
    date[2]+=1;
    if(date[2]>month[date[1]]){
        date[1]+=1;
        date[2]=1;
        if(date[1]>12){
            date[0]+=1;
            date[1]=1;
            date[2]=1;
        }
    }
}

int state_transfer(int state){
    int score=0;
    //每个人逾期都会加一分
    for(int i=0; i<6;i++){
        if(((state>>i) & 1) == 1){
            score++;
        }
    }
    
    //每天同时欠两个人的钱的情况
    for(int i=0;i<6;i+=2){
        if(((state>>i)&3)==3){
            score++;
        }
    }
    
    //连续三天都逾期
    if((state & 3)!=0 && (state & 12)!=0 &&  (state & 48)!=0){
        score++;
    }
    
    return score;
}

void output(int state, int yymmdd){
    int *date=new int[3];
    transfromdate(yymmdd,date);
    
    for(int i=0;i<6;i+=2){
        if(((state >> i)&1)!=0){
            cout<<date[0]<<date[1]<<date[2]<<"-小波(逾期)"<<",";
        }
        else{
             cout<<date[0]<<date[1]<<date[2]<<"-小波(正常)"<<",";
        }
        if(((state >> i) & 2)!=0){
            cout<<date[0]<<date[1]<<date[2]<<"-小钱(逾期)"<<",";
        }
        else{
            cout<<date[0]<<date[1]<<date[2]<<"-小钱(正常)"<<",";
        }
        date_add_one(date);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int yymmdd;
    cin>>yymmdd;
    int state=64,k=0;
    int score;
    cin>>score;
    {
        for(int i=1; i<=state;i++){
            if(state_transfer(i)==score){
                cout<<"情况"<<k<<endl;
                output(i,yymmdd);
                k++;
            }
        }
    }
    return 0;
}
