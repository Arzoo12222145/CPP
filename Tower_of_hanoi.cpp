#include<iostream>
using namespace std;

void toh(int n, char source, char auxilary, char destination)
{
    if(n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    toh(n-1,source,auxilary,destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    toh(n-1,auxilary,destination, source);

}

int main()
{
    int n = 3;

    toh(n,'A','B','C');

    return 0;
}
