#include <iostream>
#include<fstream>
#define N 9


const std::string FILE_NAME = "Question.txt";

void print(char a[N][N]);
char a[N][N] = { 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n' };
int main()
{
	
	print(a);
	system("pause");
	return 0;
}

// 印出矩陣
void print(char a[N][N])
{
	for (int i = 0; i < N; i++)
	{
		printf(" ---------  ---------  ---------\n");
		if (i == 3 || i == 6)
			printf(" ---------  ---------  ---------\n");

		for (int j = 0; j < N; j++)
		{
			if (j == 3 || j == 6)
				printf("｜");
			printf("｜%c", a[i][j]);
		}
		printf("｜\n");
	}
	printf(" ---------  ---------  ---------\n");
}