#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;

    BubbleSort(arr,n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}
