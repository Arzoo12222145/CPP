// You are using GCC
#include<iostream>
using namespace std;
int main()
{
 int size=10;
 int key,n,i,index;
 int h[size];
 cin>>n;
 for(i=0;i<size;i++)
 h[i]=-1;
 for(i=0;i<n;i++)
 {
 cin>>key;
 index=key%size;
 if(h[index]==-1) // no collision
 h[index]=key;
 else // collision
 {
 while(h[index]!=-1)
 {
 index++;
 if(index==10)
 index=0;
 }

 h[index]=key;
 }
 }
 for(i=0;i<size;i++)
 cout<<" index "<<i<<" record no: "<<h[i]<<endl;
}
