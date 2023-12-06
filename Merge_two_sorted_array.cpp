#include<bits/stdc++.h>
using namespace std;

void msa(int A[], int m, int B[], int n, int C[])
{
	int i=0, j=0, k=0;

	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			C[k] = A[i];
			i++;
			k++;
		}

		else
		{
			C[k] = B[j];
			j++;
			k++;
		}
	}

	while(i<m)
	{
		C[k] = A[i];
		i++;
		k++;
	}

	while(j<n)
	{
		C[k] = B[j];
		j++;
		k++;
	}
}

int main()
{

	int m,n;

	cout<<"Enter the size of your 1st array"<<endl;
	cin>>m;

	cout<<"Enter the size of your 2nd array"<<endl;
	cin>>n;


	int A[m];
	int B[n];

    cout<<"Enter the elements of your 1st Array"<<endl;
	for(int i=0; i<m; i++)
	{
		cin>>A[i];
	}

	cout<<"Enter the elements of your 2nd Array"<<endl;

	for(int i=0; i<n;  i++)
	{
		cin>>B[i];
	}

    int C[m+n];

	msa(A,m,B,n,C);

	for(int i=0 ; i<m+n; i++)
	{
		cout<<C[i]<<" ";
	}


}
