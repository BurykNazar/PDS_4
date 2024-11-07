#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

#define ull unsigned long long
#define ui unsigned int

using namespace std;

ull getFactorial(ui N){
	if (N == 0)
		return 1;
	return N * getFactorial(N - 1);
}


void print(ui N) {
	cout << "[";
	for (size_t i = 0; i < N - 1; i++)
		cout << (i + 1) << ", ";
	cout << N << "] " << endl;
}

void printLowes(ui N) {
	cout << "Найменшою перестановкою у множині є: "
		<< "{";
	for (size_t i = 0; i < N - 1; i++)
		cout << (i + 1) << ", ";
	cout << N << "}." << endl;
}

vector<vector<int>> findPermutations(ui N) {
	vector<vector<int>> perms;
	vector<int> perm = vector<int>(N);
	
	for (size_t i = 0; i < N; i++)
		perm[i] = i + 1;
	
	perms.push_back(perm);
	for (size_t i = 1; i < getFactorial(N); i++) {
		int j = N - 2;
		while (j >= 0 && perm[j] >= perm[j + 1])
			j--;
		if (j < 0)
			break;
		int k = N - 1;
		while (perm[k] <= perm[j])
			k--;
		swap(perm[j], perm[k]);
		reverse(perm.begin() + j + 1, perm.end());

		cout << "Номер перестановки = " << (i + 1) << " {";
		for (int i = 0; i < N - 1; i++)
			cout << perm[i] << ", ";
		cout << perm[N - 1] << "}." << endl;
		perms.push_back(perm);
	}
	return perms;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ui N = 5;
	cout << "Задана множина: ";
	print(N);
	printLowes(N);
	findPermutations(N);
	return 0;
}
