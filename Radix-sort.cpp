#include<bits/stdc++.h>
using namespace std;

int getmax(int arr[], int size)
{
    int max = arr[0];
    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingsort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
        count[(arr[i]/div)%10]++;

    for(int i=1; i<10; i++)
        count[i]+=count[i-1];

    for(int i = size-1; i>=0; i--)
    {
        output[count[(arr[i]/div)%10]-1] = arr[i];
        count[(arr[i]/div)%10]--;
    }

    for(int i=0; i<size; i++)
        arr[i] = output[i];
}

void redixsort(int arr[], int size)
{
    int m = getmax(arr, size);
    for(int div=1; m/div>0; div*=10)
    {
        countingsort(arr, size, div);
    }
}

int main()
{
    int size;

    cout<<"Enter the size of array"<<endl;
    cin>>size;

    int arr[size];
    cout<<"Enter "<<size<<" integers in any order"<<endl;

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"Before sorting"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

    redixsort(arr, size);

    cout<<endl<<"After sorting "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}
