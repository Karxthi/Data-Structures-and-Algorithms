#include <iostream>
using namespace std;
class Add
{
    int a,b;
    static int count;
    public:
        void setdata()
        {
            cout<<"enter data"<<endl;
            cin>>a;
            cin>>b;
        }
        void showdata()
        {
            cout<<"a"<<a<<"and b"<<b<<endl;
        }
        static change()
        {
            cout<<"enter data for count"<<endl;
            cin>>count;
            cout<<count<<endl;
        }
        void add(Add a1,Add a2)
        {
           
            a=a1.a+a2.a;
            b=a1.b+a2.b;
            
        }
};
int Add::count=0;
int main()
{
    int i,j;
    int p,q;
    scanf("%d",&i);
    Add k[i],k2,k3,k4;
    for(int j=0;j<i;j++)
    {
        k[j].setdata();// dont forget brackers of function
        k[j].showdata();
    }
    cout<<"vannuum"<<endl;
    k2.setdata();
    k2.showdata();
    k4.setdata();
    k4.showdata();
    
    cin>>p>>q;
    k3.add(k2,k4);
    cout<<"added k"<<endl;
    k3.showdata();
    Add::change();
}
