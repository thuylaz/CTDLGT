#include<bits/stdc++.h>
using namespace std;

int fmax(int a[20], int l, int r){
	if(l==r) return a[l];
	int n= (l+r)/2;
	return max(fmax(a, l, n), fmax(a, n+1, r));
}

void nhapm(int a[20], int n){
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
}

void xuatm(int a[20], int n){
	cout<<"mang cua nhap la: ";
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
}

main(){
	int n, t, p;
	int a[20];
	cout<<"n= "; cin>>n;
	nhapm(a, n);
	xuatm(a, n);
	cout<<"max= "<<fmax(a, t, p);
}
