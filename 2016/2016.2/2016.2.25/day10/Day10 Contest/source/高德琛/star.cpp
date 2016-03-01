#include	<cstdio>
#include	<cstring>
#include	<iostream>
#include    <algorithm>
#include    <vector>

using namespace std;
const int N = 1e3 + 5;
const double EPS = 1e-10;

int n, Count[N];
vector<pair<double, double> > point;
double A[N], B[N], C[N];

inline double ABS(double x)
{
    return x < 0 ? -x : x;
}

inline bool f(double a, double b)
{
    return ABS(a - b) <= EPS;
}

int main(int argc, char **argv)
{
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        cin >> A[i] >> B[i] >> C[i];
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + 1; j < n; j ++)
        {
            if(A[i] == 0 && A[j] == 0) continue ;
            if(B[i] == 0 && B[j] == 0) continue ;
            double a = C[j] * A[i] - C[i] * A[j];
            double b = B[i] * A[j] - B[j] * A[i];
            if(f(b, 0)) continue ;
            double x, y = a / b;
            if(A[i] == 0) x = (-B[j] * y - C[j]) / A[j];
            else x = (-B[i] * y - C[i]) / A[i];
            point.push_back(make_pair(x , y));
        }
    }
    int size = point.size();
    for(int p = 0; p < size; p ++)
    {
        double x = point[p].first, y = point[p].second;
        for(int i = 0; i < n; i ++)
            if(f(A[i] * x + B[i] * y + C[i], 0))
                Count[p] ++;
    }
    int Max = 0, Num = 0;
    for(int i = 0; i < size; i ++)
        Max = max(Max, Count[i]);
    for(int i = 0; i < size; i ++)
        if(Count[i] == Max)
            Num ++;
    printf("%d %d", Max, Num);
    return 0;
}
