#include <iostream>
using namespace std;

string s = "abcdedc123";

bool A1(string s){
	int left = 0, right = s.length() - 1;
	while(left < right){
		if(s[left] != s[right])	return false;
		left ++;
		right --;
	}
	return true;
}

int A2(string s, int k){
	int left, right;
    int maxLength = 1; // Độ dài xâu con đối xứng dài nhất ban đầu là 1
    int start = k; // Vị trí bắt đầu của xâu con đối xứng dài nhất

    // Xâu có độ dài lẻ
    left = k;
    right = k;
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        if (right - left + 1 > maxLength)
        {
            maxLength = right - left + 1;
            start = left;
        }
        left--;
        right++;
    }
    return maxLength;
}

int main(){
	cout<<A1(s)<<endl;
	int k = 4;
	cout<<A2(s, k)<<endl;
	return 0;
}


