#include<iostream>
using namespace std;

int f[100] = {0};

int Q1(int m, int n){
	f[0] = 1;
	for(int i = 1; i<=m; i++){
		for(int j = i; j<=n ; j++){
			if(i>j){
				f[j] = f[j] + f[j-i];
			}
		}
	}
	return f[n];
}

int main(){
	int n = 5;
	cout << "So cach phan tich so "<<n<<"thanh tong cac day so nguyen duong la "<< Q1(n,n)<<endl;
	return 0;
}