#include<bits/stdc++.h> 
using namespace std; 

void msa(int l[], int n1, int r[], int n2, int b[])
{
	int i=0, j=0, k=0; 
	
	while(i<n1 && j<n2) 
	{
		if(l[i]<r[j])
		{
			b[k] = l[i]; 
			i++; 
			k++; 
		}
		else 
		{
			b[k] = r[j]; 
			j++; 
			k++; 
		}
	}
	
	while(i<n1)
		{
			b[k] = l[i]; 
			i++; 
			k++; 
		}
	
	while(j<n2)
		{
			b[k] = r[j]; 
			j++; 
			k++; 
		}
		
}
int main() 
{
	int n; 
	cin>>n; 
	
	int x; 
	cin>>x; 
	
	int A[n]; 
	
	for(int i=0; i<n; i++) 
	{
		cin>>A[i]; 
	}
	
	int n1 = x+1; 
	int l[n1];
	
	int n2 = n-x-1; 
	int r[n2]; 
	
	for(int i=0; i<n1; i++) 
	{
		l[i] = A[i]; 
	}
	
	for(int i=0; i<n2; i++)
	{
		r[i] = A[x+1+i]; 
	}
	
	int b[n1+n2]; 
	
	msa(l,n1,r,n2,b); 
	
	for(int i=0; i<n1+n2; i++)
	{
		cout<<b[i]<<" "; 
	}
	
	
}
