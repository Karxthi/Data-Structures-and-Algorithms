#include <iostream>
using namespace std;
class square
{
    int s;
    public:
        square(int x)
        {
            s=x;
        }
        void operator > (square a)
        {
            if(s*s>((a.s)*(a.s)))
            {
                cout<<s*s<<"is larger than "<<endl;

            }
        }
        void operator < (square a)
        {
            if(s*s<((a.s)*(a.s)))
            {
                cout<<s*s<<"is smaller than "<<endl;
            }
        }
};
int main()
{
    int s1,s2;
    cin >> s1 >> s2;
    square sq1(s1);
    square sq2(s2);
    sq1>sq2;
    sq1<sq2;
    
}