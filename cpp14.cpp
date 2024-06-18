#include <iostream>
using namespace std;
class Shape
{
    public:
        int length;
        shape(){}
        Shape(int x)
        {
            length = x;

        }
        void display()
        {
            cout<<"Length is "<<length<<endl;
        }
};
class Rectangle
{
    public:
        int width;
        Rectangle(int a)
        {
            width = a;
        }
        void display()
        {
            cout<<"Width is "<<width<<endl;
        }
};
class Volume:public Shape,public Rectangle
{
    public:
        int height;
        Volume(int b,int x,int a):Shape(x),Rectangle(a)
        {
            height = b;
        }
        void display()
        {
            cout<<"All Details are"<<endl;
            Shape::display();
            Rectangle::display();
            cout<<"Height is "<<height<<endl;
            cout<<"Volume is "<<length*width*height<<endl;
        }

};
int main()
{
    int l,b,h;
    
    cin>>l>>b>>h;
    Volume v=Volume(h,l,b);
    v.display();
    return 0;
}
//nthaa bro moda aano
