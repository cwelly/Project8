//�������� by indegree way
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> arr[100];
queue<int> answer;
vector<int> inde(100, 0);
void topp(queue<int>& answer, vector<int>& inde, int size);
void main() {


	int n = 9, size = 9;
	arr[1].push_back(2);
	arr[2].push_back(9);
	arr[4].push_back(6);
	arr[5].push_back(1);
	arr[5].push_back(7);
	arr[5].push_back(8);
	arr[7].push_back(3);
	arr[8].push_back(4);
	arr[9].push_back(4);


	inde[1] = 1;
	inde[2] = 1;
	inde[3] = 1;
	inde[4] = 2;
	inde[6] = 1;
	inde[7] = 1;
	inde[8] = 1;
	inde[9] = 1;
	//while (n--) {
	//	int u, v;
	//	cin >> u >> v;
	//	arr[u].push_back(v);        //adj�� ��������Ʈ ���
	//	inde[v]++;              //indegree ������Ʈ
	//}
	topp(answer, inde, size);
	cout << "ANSWER : ";
	while (!answer.empty()) {
		cout << answer.front() << " ";
		answer.pop();
	}
	cout << '\n';

}
void topp(queue<int>& answer, vector<int> &inde, int size) {
	int inde_count = 0, tmp, inde_vertex_size, s;
	queue<int> count;
	while (inde_count != size) {// ���� ��� ���ؽ��� answer�� push�Ҷ����� �ݺ��Ѵ�.
		inde_count = 0;

		for (int i = 1; i < size + 1; i++) {// �ε�׸��� 0�ΰ��� count ť�� �ִ´�

			if (inde[i] == -1) { inde_count++; }
			else if (inde[i] == 0) { count.push(i); }
		}
		while (!count.empty()) {// ���� 0�� ���ؽ��� ���ʷ� answerť�� �ְ�, ���õ� ���ؽ��� ã�ư� �ε�׸� �� �ϳ������ε� count���� ��
			answer.push(count.front());//count �� �տ��ִ°�( �ε�׸��� 0�� ���ؽ�)�� answer�� ���ؽ� �߰�
			//���õ� ���ؽ��� ã�ư� �ε�׸� �ϳ������δ�
			inde_vertex_size = arr[count.front()].size();
			while (inde_vertex_size != 0) {//�ش� ���ؽ� ���;ȿ� �ִ� ����ŭ �ݺ�
				inde[arr[count.front()].at(inde_vertex_size - 1)]--;
				inde_vertex_size--;
			}
			inde[count.front()] = -1;//�ش� ���ؽ��� �ε�׸����� -1�� ����
			count.pop();// �ε�׸��� 0�ΰ��� �ٿ�������.
		}

	}

}