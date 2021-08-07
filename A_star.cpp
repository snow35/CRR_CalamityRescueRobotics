#include<iostream>
#include<cmath> //sqrt �Լ� ���
#include<utility> //pair �Լ� ���
#include<algorithm>
#include<stack>

#define ROW 10 
#define COL 10 

using Pair = std::pair<int, int>;
using Pair_2 = std::pair<double, std::pair<int, int>>;

//��忡 ���� ������ ��´�
struct node
{
	int node_x, node_y; 
	double f, g, h; 
};

//�ش� ��尡 ��ȿ���� �Ǵ��Ѵ�
//�ʱ⿡ ������ ������ ������ �Ǵ�
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

//H�� ���
double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance �˰��� ���
}

//�ش� ��尡 ���������� �Ǵ�
bool isDest(int x, int y, Pair dest)
{
	if(x == dest.first && y == dest.second)
		return (true);
	else
		return (false);
}

//��� ���
void tracepath(node nodeDetails[][COL], Pair dest)
{
	printf("\n��δ� ������ �����ϴ�: ");
	int x = dest.first;
	int y = dest.second;

	std::stack<Pair> Path;

	while (!(nodeDetails[x][y].node_x == x && nodeDetails[x][y].node_y == y)) 
	{
		Path.push(std::make_pair(x, y));
		int temp_x = nodeDetails[x][y].node_x;
		int temp_y = nodeDetails[x][y].node_y;
		x = temp_x;
		y = temp_y;
	}

	Path.push(std::make_pair(x, y));
	while (!Path.empty())
		{
			std::pair<int, int> p = Path.top();
			Path.pop();
			printf("-> (%d, %d)", p.first, p.second);
		}
	return;
}

