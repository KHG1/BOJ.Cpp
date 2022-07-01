// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int sum = 0, mode = 0, mode_value = 0;	// 산술평균 - 총합, 최빈값, 최빈값의 빈도 수
	bool is_second = false;					// 최빈값 - 조건에서, 두 번째 수인지 판별하기 위한 변수
	int count[8001] = { 0, };				// 최빈값을 검출하기 위한 배열

	cin >> n;

	int* arr = new int[n];

	// 수 입력 및 총합 계산
	for (int i = 0; i < n; i++)
	{
		int input;

		cin >> input;

		sum += input;
		arr[i] = input;
		count[input + 4000]++;
	}

	// 정렬
	sort(arr, arr + n);

	// 최빈값 계산
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] == 0)
			continue;

		else if (count[i] > mode_value)
		{
			mode = i - 4000;
			mode_value = count[i];
			is_second = true;
		}

		else if (count[i] == mode_value)
		{
			if (is_second) 
			{
				mode = i - 4000;
				mode_value = count[i];
				is_second = false;
			}
		}
	}

	// 출력
	cout << (int)round((double)sum / (double)n) << endl;	// 산술평균
	cout << arr[n / 2] << endl;								// 중앙값
	cout << mode << endl;									// 최빈값
	cout << arr[n - 1] - arr[0] << endl;					// 범위

	delete[] arr;

	return 0;
}