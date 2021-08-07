#include<iostream>
#include<cmath> //sqrt 함수 사용
#include<utility> //pair 함수 사용
#include<algorithm>
#include<stack>

#define ROW 10 
#define COL 10 

using Pair = std::pair<int, int>;
using Pair_2 = std::pair<double, std::pair<int, int>>;

//노드에 대한 정보를 담는다
struct node
{
	int node_x, node_y; 
	double f, g, h; 
};

//해당 노드가 유효한지 판단한다
//초기에 정해진 범위를 가지고 판단
bool isValid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}


//해당 노드가 막히지 않았는지 판단. 1 = 벽 / 0 = 길
bool isUnblocked(int grid[][COL], int x, int y)
{
	if (grid[x][y] == 0)
		return (true);
	else
		return (false);
}

//H값 계산
double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance 알고리즘 사용
}

//해당 노드가 목적지인지 판단
bool isDest(int x, int y, Pair dest)
{
	if(x == dest.first && y == dest.second)
		return (true);
	else
		return (false);
}

//경로 출력
void tracepath(node nodeDetails[][COL], Pair dest)
{
	printf("\n경로는 다음과 같습니다: ");
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

