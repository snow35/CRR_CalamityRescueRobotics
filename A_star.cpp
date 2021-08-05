#include<iostream>
#include<cmath> //sqrt �Լ� ���
#include<algorithm>

#define ROW 10 //�� ���� ĭ ��
#define COL 10 //�� ���� ĭ ��


typedef pair<int, int> Pair;

typedef pair<double, pair<int, int>> Pair_2;

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
		return true;
	else
		return false;
}

//�� ���

double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance �˰��� ���
}
