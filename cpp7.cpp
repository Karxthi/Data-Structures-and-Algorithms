#include <iostream>
#include <cmath>
using namespace std;
class point
{
    int x, y;
    friend void distance(point ,point );
    public:
    
    point(int a,int b){
        x=a;
        y=b;
    }
    void display(){
        cout<<"The points are: "<<x<<" and "<<y<<endl;
    }
    
    
};
void distance(point a1,point b1){
        int x1=(b1.x-a1.x);
        cout<<"The points are: "<<x1;
        int y1=(b1.y-a1.y);
        cout<<"The points are: "<<y1;
        int diff = sqrt(pow(x1,2)+pow(y1,2));
        cout<<"The points are: "<<diff;
}
int main()
{
    int d;
    point p1(3,4);
    p1.display();
    point p2(1,2);
    p2.display();
    //point p3;
    distance(p1,p2);
}