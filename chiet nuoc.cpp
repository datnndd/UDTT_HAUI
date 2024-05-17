#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int> &x, int left, int right){
	if(left>=right)	return;
	int i = left, j = right;
	int pivot = x[(left + right) / 2];
	while(i<=j){
		while(x[i] < pivot)	i++;
		while(x[j] > pivot)	j--;
		if(i<=j){
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	quick_sort(x, left, j);
	quick_sort(x, i, right);
}

int A2(vector<int> x, int n, int d){
	int i = 0;
	while(d>=x[i] && i<n){
		d = d-x[i];
		i++;
	}
	if(i != 0) return i;
	else return -1;
}

void printBottles(vector<int> x, int n){
	for (int i = 0; i<n; i++){
		cout<<x[i]<<", ";
	}
	cout<<endl;
}

int main(){
	int n = 6;
	int d = 10;
	vector<int> V_binh = {4, 5, 10, 1, 2, 3};
	
	quick_sort(V_binh, 0, n-1);
	
	int ans = A2(V_binh, n, d);
	if(ans == -1)	cout<<"Khong co chai nao"<<endl;
	else{
		cout<<"So luong chai toi da duoc do day la: "<<ans<<endl;
		cout<<"Dung tich cac chai lan luot la: ";
		printBottles(V_binh, ans);
	}
	return 0;
}