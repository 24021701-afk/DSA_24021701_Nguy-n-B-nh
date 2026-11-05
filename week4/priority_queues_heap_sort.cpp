#include <algorithm>
#include <iostream>
using namespace std;

void sink(int a[], int k, int N) {
    while (2 * k <= N) {
        int j = 2 * k;

        if (j < N && a[j] < a[j + 1])
            j++;

        if (a[k] >= a[j])
            break;

        swap(a[k], a[j]);
        k = j;
    }
}

void sort(int a[], int N) {
    for (int k = N / 2; k >= 1; k--)
        sink(a, k, N);

    while (N > 1) {
        swap(a[1], a[N]);
        N--;
        sink(a, 1, N);
    }
}

int main() {
    int n;
    if (!(cin >> n) || n < 0)
        return 0;

    int* a = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        if (!(cin >> a[i])) {
            delete[] a;
            return 0;
        }
    }

    sort(a, n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    delete[] a;
    return 0;
}
