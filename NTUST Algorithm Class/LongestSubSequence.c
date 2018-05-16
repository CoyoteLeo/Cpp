#include <stdio.h>
#define MAX 1002
#define ARRAY_SIZE 4016016
#define RIGHT_UP 1
#define UP 2
#define RIGHT 3
#define pushchar(x, y, z)x[y]=z;++y;

#define scanf_s(x)x[0]=' ';io_index=1;while((ch=getchar())=='\n'||ch==EOF){}x[io_index++]=ch;                              \
	while ((ch = getchar()) != '\n' && ch != EOF)    \
		x[io_index++] = ch;                          \
	x[io_index] = '\0';

#define scanf_d(x)                               \
while ((ch = getchar()) == '\n' || ch == EOF) {} \
x = ch - 48;                                     \
while ((ch = getchar()) != '\n' && ch != EOF)    \
x = x * 10 + ch - 48;


int amount, ch, io_index, i, m, n, length_plus, max, max_temp, m_index, n_index, m_index_temp, n_index_temp, index_, b[MAX][MAX], c[MAX][MAX], even, len, temp;
char str1[MAX], str2[MAX];

int main()
{
	scanf_d(amount);
	for (i = 0; i < amount; ++i)
	{
		even = 1;
		scanf_s(str1);
		length_plus = io_index;
		len = length_plus - 1;
		for (n = 0; n < length_plus; ++n) {
			c[0][n] = 0;
			c[n][length_plus] = 0;
		}
		for (m = 1; m < length_plus; ++m)
		{
			temp = m - 1;
			for (n = len; n > temp; --n)
			{
				if (str1[m] == str1[n])
				{
					c[m][n] = c[m - 1][n + 1] + 1;
					b[m][n] = RIGHT_UP;
				}
				else if (!(c[m - 1][n] < c[m][n + 1]))
				{
					c[m][n] = c[m - 1][n];
					b[m][n] = UP;
				}
				else
				{
					c[m][n] = c[m][n + 1];
					b[m][n] = RIGHT;
				}
			}
		}
		for (max = max_temp = 0, m = 1, n = 1; n < length_plus; ++n, ++m)
		{
			if (c[m][n] > max)
			{
				max = c[m][n];
				m_index = m;
				n_index = n;
			}
			if (c[m][n + 1] > max_temp)
			{
				max_temp = c[m][n + 1];
				m_index_temp = m;
				n_index_temp = n;
			}
		}
		if (max == max_temp)
		{
			m_index = m_index_temp;
			n_index = n_index_temp;
		}
		else
			even = 0;

		for (index_ = 0; c[m_index][n_index] > 0;)
		{
			if (b[m_index][n_index] == RIGHT_UP)
			{
				pushchar(str2, index_, str1[n_index]);
				--m_index;
				++n_index;
			}
			else if (b[m_index][n_index] == UP)
				--m_index;
			else
				++n_index;
		}
		if (even)
		{
			printf("%d\n", max << 1);
			for (m = max - 1; m > -1; --m)
				putchar(str2[m]);
		}
		else {
			printf("%d\n", ((max << 1) - 1));
			for (m = max - 1; m > 0; --m)
				putchar(str2[m]);
		}
		for (m = 0; m < max; ++m)
			putchar(str2[m]);
		putchar('\n');
	}
	return 0;
}