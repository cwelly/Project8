#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n,income,result[1000000];
	for (int i = 0; i < 1000000; i++) {
		result[i] = 10000;
	}
	result[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (i % 2 != 0) {//2�� �ȳ����� ���
			if (i % 3 != 0) {// 3���ε� �ȳ�����
				result[i] = result[i - 1] + 1;
			}
			else
				result[i] = min(result[i / 3], result[i - 1]) + 1;//2�δ� �ȳ����� 3���� ����
		}
		//2�γ����� ���
		else if (i % 3 != 0) {//2�γ�������, 3���� �ȳ���
			result[i] = min(result[i / 2], result[i - 1]) + 1;
		}
		else {
			result[i] = min(min(result[i / 2], result[i / 3]), result[i - 1]) + 1;
		}
	}
	cout << result[n];
	return 0;
}