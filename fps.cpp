//
//  main.cpp
//  test
//
//  5

//

//

//

//输入包括三行。
//第一行中有一个正整数n(1 ≤ n ≤ 50),表示平面内的怪物数量。
//第二行包括n个整数x[i](-1,000,000 ≤ x[i] ≤ 1,000,000),表示每只怪物所在坐标的横坐标,以空格分割。
//第二行包括n个整数y[i](-1,000,000 ≤ y[i] ≤ 1,000,000),表示每只怪物所在坐标的纵坐标,以空格分割。

//输出描述:
//输出一个整数表示小易最多能消灭多少只怪物。





#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct point{
    int x = 0;
    int y = 0;
};

bool is_sameline(point p1, point p2, point p3){
    return ((p1.x - p2.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p2.y)) == 0;
}

bool is_vertical(point p1, point p2){
    return (p1.x * p2.x + p1.y * p2.y) == 0;
}

bool is_vertical(point p1, point p2, point p3, point p4){
    point v1, v2;
    v1.x = p1.x - p2.x;
    v1.y = p1.y - p2.y;
    v2.x = p3.x - p4.x;
    v2.y = p3.y - p4.y;
    return is_vertical(v1, v2);
}

int main()
{
    int n, ret = 0;
    cin >> n;
    point inputs[n];
    for (int i = 0; i < n; i++)
        cin >> inputs[i].x;
    for (int i = 0; i < n; i++)
        cin >> inputs[i].y;
    if (n < 4)
    {
        cout << n << endl;
        return 0;
    };
    vector<int> select = {1, 1, 1};
    for (int i = 0; i < n - 3; i++)
        select.push_back(0);
    do
    {
        vector<point> shizi;
        for (int i = 0; i < n; i++)
        {
            if (select[i])
            {
                shizi.push_back(inputs[i]);
            }
        }
        vector<vector<point>> status;
        status.push_back({shizi[0], shizi[1], shizi[2]});
        status.push_back({shizi[0], shizi[2], shizi[1]});
        status.push_back({shizi[1], shizi[2], shizi[0]});
        for (auto points : status)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (!select[i])
                {
                    if (is_sameline(points[0], points[1], inputs[i]))
                        count++;
                    if (is_vertical(points[0], points[1], points[2], inputs[i]))
                        count++;
                }
            }
            ret = max(ret, count);
            
        }
    } while (prev_permutation(select.begin(), select.end()));
    cout << ret + 3 << endl;
    return 0;
}






