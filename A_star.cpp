#include<iostream>
#include<cmath> //sqrt �Լ� ���

#define ROW 10 //�� ���� ĭ ��
#define COL 10 //�� ���� ĭ ��



//�� ��庰 ���� ����
struct node
{
	int node_x, node_y; //���� ����� x��ǥ y��ǥ ����
	double f, g, h; //�޸���ƽ �� ����
};

//�ش� ��尡 ��ȿ���� �Ǵ�
bool isvalid(int x, int y)
{
	return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL);
}

