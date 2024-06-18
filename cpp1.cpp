#include <iostream>
using namespace std;
class emp
{
    static int count;// static so that after each object is deconstrutcted the count remains and also that  each object  can use the count;
    int id;
    public:
        void setdata(){
            cout<<"eneter the id :";
            cin>>id;
            count++;
            
        }
        void showdata(){
            cout<<"id of "<<count<<" is"<<id<<endl;

        }
        static changec()
        {
            //cout<<id<<endl;// error varum
            cout<<"\nenter new count : "<<endl;
            cin>>count;
            cout<<"\n\ncount is "<<count<<endl;
        }
};

//static member
int emp::count;//DEFAULT VALUE IS 0

int main()
{
    emp kar,krish,b;
    kar.setdata();
    kar.showdata();
    emp::changec();

    krish.setdata();
    krish.showdata();
    emp::changec();
    

    b.setdata();
    b.showdata();
    emp::changec();
}