#include<bits/stdc++.h>
using namespace std;

void chuyendia(char a, char b, char c, int n){
	if(n==1){
		cout<<a<<"->"<<c<<endl;
	}else{
		chuyendia(a, c, b, n-1);
		chuyendia(a, b, c, 1);
		chuyendia(b, a, c, n-1);
	}	
}

main(){
	int n;
	cout<<"n= "; cin>>n;
	chuyendia('a', 'b', 'c', n);
}
