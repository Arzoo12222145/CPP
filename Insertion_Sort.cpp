#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = arr[i];

        int j = i - 1;
        for(; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
               arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;

    InsertionSort(arr,n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

