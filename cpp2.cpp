#include <iostream>
using namespace std;
class emp{
    int id;
    static int count;
    int salary;
    public:
    void set_id(){
        cout<<"\n\nEnter id: "<<endl;
        cin>>id;
        count++;

        
    }
    void get_id(){
        cout<<"\nthe id of employee "<<count<<" is "<<id<<endl;
    }
    
};
int emp::count;
int main()
{
    int n;
    cout<<"\nenter n:";
    cin>>n;
    emp k[n];
    for(int i=0; i<n; i++){
        k[i].set_id();
        k[i].get_id();
}

cout<<"enter n val to be searched"<<endl;
cin>>n;
k[n-1].get_id();
}