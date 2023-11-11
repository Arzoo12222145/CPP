#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;

    SelectionSort(arr,n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}
