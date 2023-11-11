#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n, int key)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e-s)/ 2;

    while( s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return -1;
}

int main()
{
    int even[7] = {2,4,6,8,10,12,18};
    int odd[7] = {3,8,11,14,16};

    int key1;
    cout << "Enter the key to search in even array: " << endl;
    cin >> key1;

    int evenIndex = BinarySearch(even,7, key1);
    cout << "Key found at Index: " << evenIndex << endl;

    int key2;
    cout << "Enter the key to search in odd array: " << endl;
    cin >> key2;

    int oddIndex = BinarySearch(odd,5, key2);
    cout << "Key found at Index: " << oddIndex << endl;

}
