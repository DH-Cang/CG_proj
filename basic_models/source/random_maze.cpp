#include "../include/random_maze.h"


RandomMaze::RandomMaze()
{
	int r = 2 * row + 1, c = 2 * column + 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			MazeId[i][j] = 1;//����ȫ��ǽ
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++) {
			MazeId[2 * i + 1][2 * j + 1] = 0; //�м�ճ��ռ�
		}
	}

	//Prime algo: randomly open the up left wall
	//
	constructRandomMaze();
	printf("hello random_maze, you should be like\n");
	for (int i = 1; i < r - 1; i++)
	{
		for (int j = 1; j < c - 1; j++)
		{
			if (MazeId[i][j]) {
				printf("x");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
void RandomMaze::constructRandomMaze() {
	int count = row * column;
	int accsize = 0;
	int acc[64], noacc[64]; //acc for accessed, and noacc for non-accessed
	//64 = count = row * column = 8 * 8

	int offR[4] = { -1, 1, 0, 0 };//ƫ������4�����ֱ��ʾ��������
	int offC[4] = { 0, 0, 1, -1 };//
	int offS[4] = { -1, 1, row, -row };

	for (int i = 0; i < count; i++)
	{
		acc[i] = 0;
		noacc[i] = 0;//��ʼ���е�û�б�����
	}

	//��㣨һֱ�����ģ�
	acc[0] = 36;
	int pos = acc[0];

	//��һ�������
	noacc[pos] = 1;
	while (accsize < count)
	{
		//ȡ�����µĵ�
		int x = pos % row;
		int y = pos / row;
		int offpos = -1;//������¼ƫ����
		int dir = 0; //��Ǳ��˵ķ���

		while (++dir < 5)
		{
			//�����������ĵ�
			int point = (rand() % (4 - 0)) + 0;//[0,4)
			int repos;
			int move_x, move_y;
			//����λ�Ʒ���
			repos = pos + offS[point];
			move_x = x + offR[point];
			move_y = y + offC[point];

			//�ж�λ���Ƿ�Ϸ�
			if (move_y > -1 && move_x > -1 && move_x < row && move_y < column && repos >= 0 && repos < count && noacc[repos] != 1)
			{
				noacc[repos] = 1;
				acc[++accsize] = repos;
				pos = repos;
				offpos = point;
				//���ڵĸ����м��ͨ
				MazeId[2 * x + 1 + offR[point]][2 * y + 1 + offC[point]] = 0;
				break;
			}
			else
			{
				if (accsize == count -1)
				{
					return;
				}
				continue;
			}
		}

		if (offpos < 0)
		{//�ܱ�û��·�ˣ����߹���·�������Ҹ����
			int index = rand() % ((accsize + 1) - 0);
			pos = acc[index];
		}
	}
}
int RandomMaze:: getMazeInfo(int i, int j) {
	return MazeId[i][j];
}

RandomMaze::~RandomMaze()
{
}