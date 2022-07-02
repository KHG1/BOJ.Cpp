// https://www.acmicpc.net/problem/1427
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, digit;
	int arr[11] = { 0, };

	cin >> n;
	digit = (int)log10(n) + 1;					// 입력받은 수의 자릿수를 구함

	for (int i = 10; i >= 0; i--)
	{
		arr[i] = n % 10;
		n /= 10;
	}

	sort(arr, arr + 11);

	for (int i = 10; digit > 0; i--,digit--)
	{
		cout << arr[i];
	}

	return 0;
}