#include<iostream> 
#include<vector> 
#include<climits> 

using namespace std;

struct Point 
{
    int x;
    int y;
};

void merge(vector<Point> &elements, int left, int mid, int right) 
{ 
    vector<Point> left_Sub_Array(elements.begin() + left, elements.begin() + mid + 1); 
    vector<Point> right_Sub_Array(elements.begin() + mid + 1, elements.begin() + right + 1); 

    left_Sub_Array.push_back({INT_MAX, INT_MAX}); 
    right_Sub_Array.push_back({INT_MAX, INT_MAX});

    int index_Left_SA = 0; 
    int index_Right_SA = 0; 

    for (int index_Full_Array = left; index_Full_Array <= right; index_Full_Array++) 
    { 
        if ((left_Sub_Array[index_Left_SA].y + left_Sub_Array[index_Left_SA].x) >= (right_Sub_Array[index_Right_SA].y + right_Sub_Array[index_Right_SA].x))
        {		 
            elements[index_Full_Array] = left_Sub_Array[index_Left_SA]; 
            index_Left_SA++; 
        } 
        else 
        {	 
            elements[index_Full_Array] = right_Sub_Array[index_Right_SA]; 
            index_Right_SA++; 
        } 
    } 
} 

void mergesort(vector<Point> &elements, int left, int right) 
{ 
    if (left == right) 
        return; 
    
    int mid = (left + right) / 2; 
    mergesort(elements, left, mid); 
    mergesort(elements, mid + 1, right); 
    merge(elements, left, mid, right); 
} 

int main() 
{ 
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);

    cout << "Enter the coordinates of points (x y):" << endl;
    for (int i = 0; i < n; i++) { 
        cin >> points[i].x >> points[i].y; 
    } 

    clock_t tStart = clock(); 

    mergesort(points, 0, n-1); 

    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC; 

    cout<<"Time taken is "<<time1<<endl;

    cout << "Sorted points based on (x+y)/2 coordinates in decreasing order:" << endl;
    for (int i = 0; i < n; i++) { 
        cout << points[i].x << " " << points[i].y << endl; 
    }

    return 0;
}
