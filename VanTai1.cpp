#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<float> &x, int left, int right){
	if(left>=right)	return;
	int i = left, j = right;
	float pivot = x[(left + right) / 2];
	while(i<=j){
		while(x[i] > pivot)	i++;
		while(x[j] < pivot)	j--;
		if(i<=j){
			swap(x[i], x[j]);
			i++;
			j--;
		}
	}
	quickSort(x, left, j);
	quickSort(x, i, right);
}

int A4(vector<float> weights, int n, int d){
	vector<int> x;
	int i = 0;
	while(i < n && d >0){
		d = d - weights[i];
		i++;
	}
	if( d > 0)	return -1;
	else return i;
}

int main(){
	int n = 6;
	vector<float> weights= {4, 5, 10, 5.5, 7, 9};
	float d = 20;
	
	quickSort(weights, 0, n-1);
	
	cout<<endl;
	int ans = A4(weights, n, d);
	cout<<"so xe toi thieu la "<< ans<<endl;
	cout<<"Tai trong cua cac xe duoc su dung: ";
	for(int i =0; i<ans; i++){
		cout<<weights[i]<<", ";
	}
	
	return 0;
}