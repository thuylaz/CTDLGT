#include<bits/stdc++.h>
using namespace std;

int giaithua(int n){
	if(n==1)
		return 1;
		return (n*giaithua(n-1));	
}

main(){
	int n;
	cout<<"n= "; cin>>n;	
	cout<<n<<"!= "<<giaithua(n);

}
