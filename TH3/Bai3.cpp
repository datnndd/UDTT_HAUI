#include<iostream>
using namespace std;

void sort_chiadetri(float arr[], int left, int right) {
	if (left > right)	return;
	int i = left, j = right;
	float pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot)	i++;
		while (arr[j] > pivot)	j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	sort_chiadetri(arr, left, j);
	sort_chiadetri(arr, i, right);
}

int main() {
	int n = 15;
	float arr[] = { 1.1, 9, 8, 7, 5.5, 7.7, 4, 3 , 2.2, 9.9, 15.5, 44.4, 14.4, 14.9, 15.5 };
	sort_chiadetri(arr, 0, 14);
	for (int i = 0; i < n; i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
