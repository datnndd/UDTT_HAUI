#include<iostream>
using namespace std;


//Khai bao
#define N 6
#define M 12
int n = N;
int m = M;
int w[N+1] = {0,3, 6, 2, 7, 1, 5};
int v[N+1] = {0,4, 5, 2, 6, 1, 3};
int dp[N+1][M+1];// gia tri lon nhat cua cac do vat co the cho vao ba lo
			// khi xet den do vat thu i va trong luong la j
			// neu chon dp[i][j] =dp[i - 1][j-w[i]] + v[i];
			// neu khong chon dp[i][j] = dp[i-1][j];
			
void Q2(){
	for (int j = 0; j <=m;j++)	dp[0][j] = 0;
	
	for(int i = 1; i<=n;i++){
		for(int j = 0; j <=m;j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= w[i]){
				int temp = dp[i- 1][j - w[i]] + v[i];
				if(dp[i][j] < temp){
					dp[i][j] = dp[i- 1][j - w[i]] + v[i];
				} 
			}
		}
	}

}			
			
void result(int &u, int *d){
	u = 0;
	int i = n, j= m;
	while(i!=0){
		if(dp[i][j] != dp[i-1][j]){
			d[u] = i; //d[0] = 4; d[1] = 3; d[2] = 
			j = j - w[j];
			u++;
		}
		i--;
	}
}


int main(){
	Q2();
	
	int u = 0;
	int *d = new int[N];
	result(u, d);
	
	cout<<"Lay duoc: "<< u <<"goi hang"<<endl;
	cout<<"Cac goi hang do la: "<<endl;
	cout<<"Weight\tValue"<<endl;
	for(int i = 0; i<u;i++){
		cout<<w[d[i]]<<"\t"<<v[d[i]]<<endl;
	}
	return 0;

}