#include <iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int> &x, int left, int right){
	if(left>= right)	return;
	int i =left, j = right;
	int pivot = x[ (left + right) / 2];
	while(i<=j){
		while(x[i] > pivot)	i++;
		while(x[j] < pivot)	j--;
		if(i<=j){
			swap(x[i], x[j]);
			i++;
			j--;
		}	
	}
	quick_sort(x, left, j);
	quick_sort(x, i, right);
}

int coin_changing(vector<int> coin_arr, int n_coin, int money, vector<int>& S){
	int i = 0;
	int ans = 0;
	while(money >0 && i< n_coin){
		S[i] = money / coin_arr[i];
		ans += S[i];
		money = money % coin_arr[i];
		i++;
	}
	if(money > 0)	return -1;
	else return ans;
}

void printCoin(vector<int> x, vector<int> y, int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] != 0)
            cout << "Can " << x[i] << " dong xu co menh gia la " << y[i] << endl;
    }
    cout << endl;
}

int main(){
	int n = 6;
	vector<int> coin_arr = {2, 5, 10, 20 , 50, 100};
	vector<int> S(n, 0);
	int m = 448;
	
	quick_sort(coin_arr, 0, n-1);
	
	int ans = coin_changing(coin_arr, n, m, S);
	if(ans != -1){
		cout<<"Can toi thieu: "<<ans<<endl;
		printCoin(S, coin_arr, n);
	}
	else	cout<<"Khong tim duoc"<<endl;
	return 0;
}