#include <algorithm>
#include <iostream>
using namespace std;

bool isEmpty(int N) {
    return N == 0;
}

int size(int N) {
    return N;
}

void swim(int pq[], int k) {
    while (k > 1 && pq[k / 2] < pq[k]) {
        swap(pq[k], pq[k / 2]);
        k = k / 2;
    }
}

void sink(int pq[], int k, int N) {
    while (2 * k <= N) {
        int j = 2 * k;

        if (j < N && pq[j] < pq[j + 1])
            j++;

        if (pq[k] >= pq[j])
            break;

        swap(pq[k], pq[j]);
        k = j;
    }
}

bool insert(int pq[], int& N, int key) {
    pq[++N] = key;
    swim(pq, N);
    return true;
}

bool max(int pq[], int N, int& maximum) {
    if (isEmpty(N))
        return false;

    maximum = pq[1];
    return true;
}

bool delMax(int pq[], int& N, int& maximum) {
    if (isEmpty(N))
        return false;

    maximum = pq[1];
    swap(pq[1], pq[N]);
    N--;
    sink(pq, 1, N);
    return true;
}

int main() {
    int n;
    if (!(cin >> n) || n < 0)
        return 0;

    int* pq = new int[n + 1];
    int N = 0;

    for (int i = 0; i < n; i++) {
        int value;
        if (!(cin >> value) || !insert(pq, N, value)) {
            delete[] pq;
            return 0;
        }
    }

    while (!isEmpty(N)) {
        int maximum;
        delMax(pq, N, maximum);
        cout << maximum << " ";
    }

    delete[] pq;
    return 0;
}
