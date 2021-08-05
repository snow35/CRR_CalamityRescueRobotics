#include<iostream>
#include<cmath> //sqrt 함수 사용
#include<algorithm>

#define ROW 10 //맵 가로 칸 수
#define COL 10 //맵 세로 칸 수


typedef pair<int, int> Pair;

typedef pair<double, pair<int, int>> Pair_2;

//각 노드별 정보 생성
struct node
{
	int node_x, node_y; //각각 노드의 x좌표 y좌표 저장
	double f, g, h; //휴리스틱 값 저장
};

//해당 노드가 유효한지 판단
bool isValid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

//해당 노드가 막히지 않았는지 판단. 1 = 벽 / 0 = 길
bool isUnblocked(int grid[][COL], int x, int y) 
{
	if (grid[x][y] == 0)
		return true;
	else
		return false;
}

//값 계산

double Hscore(int x, int y, Pair dest)
{
	double dx = abs(x - dest.first);
	double dy = abs(y - dest.second);
	return 1 * (dx + dy) + (2 - 2 * 1) * std::min<dx, dy>; //diagonal distance 알고리즘 사용
}
