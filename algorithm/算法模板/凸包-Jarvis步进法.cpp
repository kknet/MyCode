#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//精度判断
const double eps = 1e-10;
double dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {}
};
Point operator - (const Point& A, const Point& B) {
    return Point(A.x-B.x, A.y-B.y);
}
double Cross(const Point& A, const Point& B) {
    return A.x*B.y - A.y*B.x;
}
double Dot(const Point& A, const Point& B) {
    return A.x*B.x + A.y*B.y;
}
bool operator < (const Point& p1, const Point& p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}
bool operator == (const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

//点集凸包，Jarvis步进法,注意，是逆时针方向，并且首尾不相连
vector<Point> ConvexHull(vector<Point> p) {
    //预处理，删除重复点
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; i++) {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}