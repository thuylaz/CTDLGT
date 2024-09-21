#include<bits/stdc++.h>
using namespace std;

void xuat(int a[], int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<"\t";
	}
}

int sxnb(int a[], int n){
	for(int i=1; i<n; i++){
		for(int j=0; j<n-i; j++){
			if(a[j]>a[j+1]){
				int tg=a[j];
				a[j]=a[j+1];
				a[j+1]= tg;
			}
		}
		cout<<"mang sau lan duyet thu "<<i<<" la: ";
		xuat(a,n);
		cout<<"\n";
	}	
}

int sxc(int a[], int n){
	for(int i=1; i<n; i++){
		int tam= a[i];
		int j=i-1;
		while(j>-1&&a[j]>tam){
			a[j+1]= a[j];
			j--;
		}
		a[j+1]= tam;
		cout<<"mang sau lan duyet thu "<<i<<" la: ";
		xuat(a,n);
		cout<<"\n";
	}
}



int sxlc(int a[], int n){
	for(int i=0; i<n-1; i++){
		int m=i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[m]){
				m=j;
			}
		}
			swap(a[m], a[i]);
		cout<<"mang sau lan duyet thu "<<i<<" la: ";
		xuat(a,n);
		cout<<"\n";
	}
}

int timpt(int a[], int n, int x){
	for(int i=0; i<n; i++){
		if(i=x)
		return a[i];
		return -1;
	}
}

int fx(int x){
	if(x>=7) return 7;
	return pow(x,2)+ fx(x+1);
}

int tk(int a[], int n, int kh){
	int i=0;
	while(i<n&&a[i]!=kh)
	i+=1;
	if(i<n) return i;
	return -1;
}

int tknp(int *a, int l, int r, int kh){
	int j;
	if(l>r) return -1;
	else{
		j=(l+r)/2;
		if(a[j]==kh) return j;
		else if(kh<a[j]) return tknp(a, l, j-1, kh);
		else return tknp(a, j+1, r, kh);
	}
}

int tinh(int n){
	if(n<0) return -1;
	else{
		if(n==0) return 0;
		if(n==1) return 3;
		if (n==2) return 7;
		return tinh(n-1)+ tinh(n-2)+ 2;
	}
}

main(){
	int n;
	cin>>n;
	cout<<"tinh= "<<tinh(n);
	
}
