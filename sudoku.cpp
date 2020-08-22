#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (int) 1e9+7
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
#define N 9
ll xpow(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0)
	{
		ll k = xpow(a, b / 2);
		return k * k;
	}
	if (b % 2 != 0)
		return a * xpow(a, b - 1);
}
bool findEmptyCell(int mat[N][N], int &r, int &c) {
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			if (mat[r][c] == 0)
				return true;
		}
	}
	return false;
}
bool checkRow(int mat[N][N], int r, int val) {
	for (int c = 0; c < N; c++) {
		if (mat[r][c] == val)
			return true;
	}
	return false;
}
bool checkCol(int mat[N][N], int c, int val) {
	for (int r = 0; r < N; r++) {
		if (mat[r][c] == val)
			return true;
	}
	return false;
}
bool checkBox(int mat[N][N], int st, int en, int num) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (mat[i + st][j + en] == num)
				return true;
		}
	}
	return false;
}
bool isSafe(int mat[N][N], int r, int c, int num) {
	return !checkRow(mat, r, num) and !checkCol(mat, c, num) and !checkBox(mat, r - r % 3, c - c % 3, num) and mat[r][c] == 0;
}
bool solve(int mat[N][N]) {
	int r, c;
	if (findEmptyCell(mat, r, c) == false)
		return true;
	for (int val = 1; val <= 9; val++) {
		if (isSafe(mat, r, c, val)) {
			mat[r][c] = val;
			if (solve(mat))
				return true;
			mat[r][c] = 0;
		}
	}
	return false;
}
void printBox(int mat[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
#endif
	fio;
	int mat[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
		{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },
		{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
		{ 2, 6, 3, 0, 1, 5, 9, 8, 7 },
		{ 9, 7, 4, 8, 6, 0, 1, 2, 5 },
		{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
		{ 1, 3, 8, 0, 4, 7, 2, 0, 6 },
		{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
		{ 7, 4, 5, 0, 8, 6, 3, 1, 0 }
	};
	if (solve(mat))
		printBox(mat);
	else
		cout << "No Solution" << endl;
	return 0;
}