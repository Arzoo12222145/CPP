#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void dlt(){
        if ( size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){

        int left = 2 * i;
        int right = 2 * i + 1;

        if(left < size && arr[left] > arr[i]){
            swap(arr[i], arr[left]);
             i = left;
        }

        else if(right < size && arr[right] > arr[i]){
            swap(arr[i], arr[right]);
            i = right;
        }
        else{
            return;
        }

        }
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    heap h;
    h.insert(30);
    h.insert(50);
    h.insert(70);
    h.insert(20);
    h.insert(65);
    h.insert(40);
    h.print();
    h.dlt();
    h.print();

    int arr[6] = {-1,50,40,65,20,30};
    int n = 5;
    for(int i = n/2; i >0; i--){
        h.heapify(arr, n , i);
    }

    cout << "Printing the array: " << endl;
    for(int i = 1; i < n+1; i++){
        cout << arr[i] << " ";
    }
}
