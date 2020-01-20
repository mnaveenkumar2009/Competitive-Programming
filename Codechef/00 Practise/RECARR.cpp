#include <bits/stdc++.h>
using namespace std;

int n = 1e5, c = 0;
vector <int> A(n, 0);
int quer(int l, int r){
	cout << "1 " << l + 1 << ' ' << r + 1 << endl;
	int x;
	cin >> x;
	c++;
	assert(c <= 9e4);
	return x;
}
void query(int i){
	int x = quer(i*3, i*3 + 2);
	if(x == 3 || x == 0){
		A[i*3] = A[i*3 + 1] = A[i*3 + 2] = x/3;
		return;
	}
	if(x == 2){
		A[i*3] = A[i*3 + 1] = A[i*3 + 2] = 1;
		int y = rand() % 3;
		x = quer(i*3 + y, i*3 + y);
		if(x == 0)
			A[i*3 + y] = 0;
		else{
			x = quer(i*3 + (y  + 1) % 3, i*3 + (y  + 1) % 3);
			if(x == 0)
				A[i*3 + (y + 1) % 3] = 0;
			else
				A[i*3 + (y + 2) % 3] = 0;
		}
	}
	else{
		int y = rand() % 3;
		x = quer(i*3 + y, i*3 + y);
		if(x == 1)
			A[i*3 + y] = 1;
		else{
			x = quer(i*3 + (y  + 1) % 3, i*3 + (y  + 1) % 3);
			if(x == 1)
				A[i*3 + (y + 1) % 3] = 1;
			else
				A[i*3 + (y + 2) % 3] = 1;
		}
	}
}
int main(){
	srand(time(0));
	for(int i = 0; i < n/3; i++)
		query(i);
	A[n - 1] = quer(n - 1, n - 1);
	cout << "2 ";
	for(int i = 0; i < n; i++)
		cout << A[i] << ' ';
	cout << endl;
}