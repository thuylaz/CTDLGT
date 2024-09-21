#include<bits/stdc++.h>
using namespace std;


void nhapm(int a[], int n){
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
}

void xuatm(int a[], int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<"\t";
	}
}

//sx noi bot
//giam dan
int sxnb(int a[], int n){
	for(int i=1; i<n; i++){
		for(int j=0; j<n-i; j++){
			if(a[j]<a[j+1]){
				int tg=a[j];
				a[j]=a[j+1];
				a[j+1]= tg;
			}
		}
	}
}

int sxc(int a[], int n){
	for(int i=0; i<n; i++){
		int tam=a[i];
		int j=i-1;
		while(j>-1 && a[j]<tam){
			a[j+1]= a[j];
			j--;
		}
		a[j+1]=tam;
	}
}

void sxlc(int a[], int n){
	for(int i=0; i<n-1; i++){
		int m=i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[m]){
				m=j;
			}
		}
		if(m!=i){
			int tg=a[m];
			a[m]= a[i];
			a[i]= tg;
		}
		cout<<"mang sau lan duyet "<<i<<" la: ";
		xuatm(a,n);
		cout<<"\n";
	}
}



main(){
	int n=3;
	int a[n]={1,5,2};
	sxlc(a, n);


}
