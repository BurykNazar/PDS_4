#include<iostream>
#include<vector>
#include<algorithm>
#include<Windows.h>

#define ull unsigned long long
#define ui unsigned int

using namespace std;

ull getFactorial(ui N) {
    if (N == 0)
        return 1;
    return N * getFactorial(N - 1);
}

void print(ui N) {
    cout << "Початкова згенерована множина: [";
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

bool nextCombination(vector<int>& perms, int R, int N) {
    int i = R - 1;
    while (i >= 0 && perms[i] == N - R + i + 1) {
        i--;
    }
    if (i < 0)
        return false;
    perms[i]++;
    for (int j = i + 1; j < R; j++) {
        perms[j] = perms[j - 1] + 1;
    }
    return true;
}

vector<vector<int>> find(ui N, ui R) {
    vector<vector<int>> perms;
    vector<int> perm(R);

    for (int i = 0; i < R; i++) {
        perm[i] = i + 1;
    }

    int i = 1;
    cout << "Номер r-сполучення без повторень = " << i << " {";
    for (int j = 0; j < R - 1; j++) {
        cout << perm[j] << ", ";
    }
    cout << perm[R - 1] << "}." << endl;

    perms.push_back(perm);

    while (nextCombination(perm, R, N)) {
        perms.push_back(perm);
        i++;
        cout << "Номер r-сполучення без повторень = " << i << " {";
        for (int j = 0; j < R - 1; j++) {
            cout << perm[j] << ", ";
        }
        cout << perm[R - 1] << "}." << endl;
    }
    return perms;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ui N = 6;
    ui R = 4;
    print(N);
    printLowes(N);
    find(N, R);
    return 0;
}
