#include<iostream>
#include<cmath> //sqrt 함수 사용

#define ROW 10 //맵 가로 칸 수
#define COL 10 //맵 세로 칸 수



//각 노드별 정보 생성
struct node
{
	int node_x, node_y; //각각 노드의 x좌표 y좌표 저장
	double f, g, h; //휴리스틱 값 저장
};

//해당 노드가 유효한지 판단
bool isvalid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

