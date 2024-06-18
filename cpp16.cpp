#include <iostream>
using namespace std;

class array
{
   
    int arr[50];
    public:
        array(int ptr[])
        {

            arr=ptr;

        }
        int operator - (int arr[])
        {
            int count = 0;
            for (int i = 0; arr[i]!=0; i++)
            {
                count++;
            }
            return count;
        }
};
int main()
{
    int n;
    cin >> n;
    int cnt;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cnt=-arr[n];
    cout << "count is "<<cnt << endl;
}