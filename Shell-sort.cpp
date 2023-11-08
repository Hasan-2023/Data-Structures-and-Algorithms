#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n)
{
    int total_passes = 0;
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<(n-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                total_passes++;
            }
            total_passes++;
        }
        total_passes++;
    }
    cout<<"Total passes "<<total_passes<<endl;
}

void shellsort(int arr[], int n)
{
    int total_passes = 0;
    for(int gap=n/2; gap>0; gap/=2)
    {
        for(int j=gap; j<n; j+=1)
        {
            int temp = arr[j];
            int i = 0;

            for( i = j; (i>=gap) && (arr[i-gap]>temp); i-=gap)
            {
                arr[i] = arr[i-gap];
                total_passes++;
            }
            arr[i] = temp;
            total_passes++;
        }
        total_passes++;
    }
    cout<<"Total passes "<<total_passes<<endl;
}

int main()
{
    int n;

    cout<<"Enter the size of array"<<endl;
    cin>>n;

    int arr1[n], arr2[n];

    cout<<"Enter "<<n<<" integers in any order "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr1[i];
        arr2[i] = arr1[i];
    }

    cout<<"Before sorting"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr1[i]<<" ";
    }

    cout<<endl<<endl<<"Shell sort "<<endl;

    shellsort(arr1, n);
    cout<<endl<<"After sorting"<<endl;
    {
            for(int i=0; i<n; i++)
            cout<<arr1[i]<<" ";
    }
    cout<<endl;

    cout<<endl<<"Bubble sort"<<endl;
    bubblesort(arr2, n);

    cout<<"After sorting"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr1[i]<<" ";
    }

    return 0;
}
