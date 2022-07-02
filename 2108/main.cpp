// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, i, j;
	int sum = 0, median, mode_index = 0, mode_value = 0;	// 산술평균을 위한 합계, 중앙값 인덱스, 최빈값 인덱스, 최빈값 빈도 수
	bool is_second = false;									// 최빈값 조건에서 두번째 최빈값인지를 판별하기 위한 변수
	int arr[8001] = { 0, };

	cin >> n;

	for (i = 0; i < n; i++) {
		int input;

		cin >> input;

		sum += input;										// 입력과 동시에 총합을 증가
		arr[input + 4000]++;
	}

	// 중앙값
	for (median = 0, i = -1; i < n / 2; median++) {
		for (int j = 0; j < arr[median]; j++) {
			i++;

			if (i == n / 2)
				break;
		}
	}

	// 최빈값
	for (i = 0; i < 8001; i++) {
		if (!arr[i])
			continue;

		else if (arr[i] > mode_value) {
			mode_index = i;
			mode_value = arr[i];
			is_second = true;
		}

		else if (arr[i] == mode_value) {
			if (is_second) {
				mode_index = i;
				mode_value = arr[i];
				is_second = false;
			}
		}
	}

	// 범위
	for (i = 0; !arr[i]; i++);
	for (j = 8000; !arr[j]; j--);

	// 출력
	cout << (int)round((double)sum / n) << endl;
	cout << median - 4001 << endl;
	cout << mode_index - 4000 << endl;
	cout << (j - 4000) - (i - 4000) << endl;

	return 0;
}