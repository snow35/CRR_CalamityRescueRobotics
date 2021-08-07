#include<iostream>
#include<cmath> //sqrt �Լ� ���
#include<utility> //pair �Լ� ���

#define ROW 10 //�� ���� ĭ ��
#define COL 10 //�� ���� ĭ ��

using Pair pair<int, int>;
using Pair_2 pair<double, pair<int, int>>;

//�� ��庰 ���� ����
struct node
{
	int node_x, node_y; //���� ����� x��ǥ y��ǥ ����
	double f, g, h; //�޸���ƽ �� ����
};

//�ش� ��尡 ��ȿ���� �Ǵ�
bool isValid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

//�ش� ��尡 ������ �ʾҴ��� �Ǵ�. 1 = �� / 0 = ��
bool isUnblocked(int grid[][COL], int x, int y)
{
	if (grid[x][y] == 0)
		return (true);
	else
		return (false);
}

//��ǥ �������� �Ǵ� (��� ��ǥ�� ������ ��ǥ ��)
bool isDest(int x, int y, Pair dest) {
	if (x == dest.first && y == dest.second)
		return (true);
	else
		return (false);
}

//H�� ���
double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance �˰��� ���
}

//

   
