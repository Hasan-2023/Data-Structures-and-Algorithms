#include<iostream>
using namespace std;

 void bubblesort(int a[])
 {
     for(int i=0; i<5; i++)
     {
         for(int j=0; j<(5-i-1); j++)
         {
             if(a[j]>a[j+1])
             {
                 int temp = a[j];
                 a[j] = a[j+1];
                 a[j+1]= temp;
             }
         }
     }
 }

int main()
{
    int myarray[5];
    int size;

    cout<<"Enter 5 integer in any order"<<endl;
    for(int i =0; i<5; i++)
    {
        cin>>myarray[i];
    }

    cout<<"Before sorting"<<endl;
    for(int i=0; i<5; i++)

    {
        cout<<myarray[i]<<" ";
    }
        bubblesort(myarray);
        cout<<"After sorting"<<endl;
        for(int i=0; i<5; i++)
        {
            cout<<myarray[i]<<"  ";
        }


    return 0;
}
