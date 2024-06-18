#include <iostream>
#include <cmath>
using namespace std;
//int distance(int , int );
class point
{
    int x, y;
    public:
        void getpoint(int a,int b)
        {
            x=a; 
            y=b;
        }
        void showpoint()
        {
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }
        friend int distance(point a1,point a2);
};
int distance(point a1,point a2)
{
    int xdiff = a1.x-a2.x;
    int ydiff = a1.y-a2.y;
    int distanc=sqrt(pow(xdiff,2)+pow(ydiff,2));
    return distanc;
};
int main()
{
    point p1,p2;
    int x,y,dist;
    cin>>x>>y;
    p1.getpoint(x,y);
    p1.showpoint();
    cin>>x>>y;
    p2.getpoint(x,y);
    p2.showpoint();
    dist=distance(p1,p2);
    cout<<"distance "<<dist<<endl;
    
}