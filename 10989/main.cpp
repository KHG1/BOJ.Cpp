// https://www.acmicpc.net/problem/10989

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[10001] = { 0 };
	// 수의 범위가 10000보다 작거나 같은 자연수로 명시되었으므로

	cin >> n;

	// 계수 정렬
	for (int i = 0; i < n; i++) {
		int index;
		cin >> index;

		arr[index]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}