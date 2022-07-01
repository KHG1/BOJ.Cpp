// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int arr[8001] = { 0, };

	cin >> n;

	int i, sum = 0;

	for (i = 0; i < n; i++) {
		int input;
		
		cin >> input;
		
		sum += input;
		arr[input + 4000]++;
	}

	int aaa = -1;
	int k;

	for (k = 0; aaa < n / 2; k++) {
		for (int j = 0; j < arr[k]; j++) {
			aaa++;

			if (aaa == n / 2)
				break;
		}
	}

	int bbb = 0, ccc = 0;
	bool tmp = false;

	for (i = 0; i < 8001; i++) {
		if (!arr[i])
			continue;
		
		else if (arr[i] > ccc) {
			bbb = i;
			ccc = arr[i];
			tmp = true;
		}

		else if (arr[i] == ccc) {
			if (tmp) {
				bbb = i;
				ccc = arr[i];
				tmp = false;
			}
		}
	}

	int j;

	for (i = 0; !arr[i]; i++);
	for (j = 8000; !arr[j]; j--);

	cout << (int)round((double)sum / n) << endl;
	cout << k - 4001 << endl;
	cout << bbb - 4000 << endl;
	cout << (j - 4000) - (i - 4000) << endl;

	return 0;
}