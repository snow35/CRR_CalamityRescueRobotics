#include<iostream>
#include<cmath> //sqrt �Լ� ���?
#include<algorithm>
#include<utility>
#include<stack>

#define ROW 10 //�� ���� ĭ ��
#define COL 10 //�� ���� ĭ ��


using Pair = std::pair<int, int>;
using Pair_2 = std::pair<double, std::pair<int, int>>;

//�� ���? ���� ����
struct node
{
	int node_x, node_y; //���� �����? x��ǥ y��ǥ ����
	double f, g, h; //�޸���ƽ �� ����
};

//�ش� ���? ��ȿ���� �Ǵ�
bool isValid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

//�ش� ���? ������ �ʾҴ��� �Ǵ�. 1 = �� / 0 = ��
bool isUnblocked(int grid[][COL], int x, int y) 
{
	if (grid[x][y] == 0)
		return true;
	else
		return false;
}

//�� ���?  

double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance �˰����� ���?
}

//�ش� ��尡 ��ǥ �������� Ȯ��
bool isDest(int x, int y, Pair dest)
{
	if(x == dest.first && y == dest.second)
		return (true);
	else
		return (false);
}

//������� (��� �������)
void tracepath(node nodeDetails[][COL], Pair dest)
{
	printf("\n��δ� : ");
	int x = dest.first;
	int y = dest.second;

	std::stack<Pair> Path;

	while
}
