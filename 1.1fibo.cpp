#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
	if(n<0)
		return -1;
	if(n==0) return 4;
	if(n==1) return 3;
	else return fibo(n-1) - fibo(n-2)-1;
}

main(){
	int n;
	cout<<"n= "; cin>>n;
	cout<<fibo(n);
}

//dinh nghia de quy
co a[2]=a[1]-a[0]-1= 3-4-1=-2;
tuong tu a[3]=a[2]-a[1]-1= -2-3-1=-6;
tu do co a[n]=a[n-1]-a[n-2]-1
