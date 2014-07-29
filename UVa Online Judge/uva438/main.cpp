#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct Point {double x, y;} p[3];
struct Line {Point p1, p2;};
typedef Line Segment;
double dist(Point &p1, Point &p2);
int cross(Point& v1, Point& v2);
Point intersection(Point& a1, Point& a2, Point& b1, Point& b2);
Point circle(Point &a, Point &b, Point &c) {
    static Point ab, ac, o;
    static double a1, b1, c1, a2, b2, c2, D, D1, D2;
    ab.x = (a.x+b.x)/2, ab.y = (a.y+b.y)/2;
    ac.x = (a.x+c.x)/2, ac.y = (a.y+c.y)/2;
    a1 = a.x-b.x, b1 = a.y-b.y;
    c1 = a1*ab.x + b1*ab.y;
    a2 = a.x-c.x, b2 = a.y-c.y;
    c2 = a2*ac.x + b2*ac.y;
    D = a1*b2-a2*b1;
    D1 = c1*b2-c2*b1;
    D2 = a1*c2-a2*c1;
    o.x = D1/D;
    o.y = D2/D;
    return o;
}
int main()
{
    while ((cin >> p[0].x)&& (cin >> p[0].y)&& (cin >> p[1].x)&& (cin >> p[1].y)&& (cin >> p[2].x)&& (cin >> p[2].y))
    {
        /*
        Point m1,m2;
        m1.x = (p[0].x + p[1].x)/2;
        m1.y = (p[0].y + p[1].y)/2;
        m2.x = (p[1].x + p[2].x)/2;
        m2.y = (p[1].y + p[2].y)/2;
        //cout << m1.x << endl;
        Point s1,s2 ;
        s1.x = p[1].x - p[0].x;
        s1.y = p[1].y - p[0].y;
        swap(s1.x, s1.y);
        s1.x *= -1;
        cout << s1.x  << endl;
        s2.x = p[2].x - p[1].x;
        s2.y = p[2].y - p[1].y;
        swap(s2.x, s2.y);
        s2.x *= -1;
        Point n1,n2;
        n1.x = s1.x + m1.x;
        n1.y = s1.y + m1.y;
        n2.x = s2.x + m2.x;
        n2.y = s2.y + m2.y;
        Point iter = intersection(n1,m1,n2,m2);
        cout << iter.x << "  "<< iter.y << endl;
        */
        Point o = circle(p[0],p[1],p[2]);
        cout << fixed<<setprecision(2) << (2* 3.141592653589793* dist(o,p[0])) << endl;
    }
    return 0;
}
double dist(Point &p1, Point &p2)
{
    return sqrt((p2.x - p1.x) * (p2.x - p1.x)
                + (p2.y - p1.y) * (p2.y - p1.y));
}
int cross(Point& v1, Point& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}
Point intersection(Point& a1, Point& a2, Point& b1, Point& b2)
{
    Point a ;
    a.x = a2.x - a1.x;
    a.y = a2.y - a1.y;
    Point b ;
    b.x = b2.x - b1.x;
    b.y = b2.y - b1.y;
    Point s;
    s.x = b1.x-a1.x;
    s.y = b1.y-a1.y;


    //if (cross(a, b) == 0) return ;
    Point ans;
    ans.x = a1.x + a.x*cross(s, b) / cross(a, b);
    ans.y = a1.y + a.y*cross(s, b) / cross(a, b);
    return ans;
}
