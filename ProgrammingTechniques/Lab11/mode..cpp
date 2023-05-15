#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("soarece1.in");
ofstream fout("soarece1.out");

int n, m, is, js, ib, jb;
int a[11][11];

char s;

bool found;

const int di[] = { 0 ,  0 , 1 , -1 };
const int dj[] = { 1 , -1 , 0 ,  0 };

bool inside(int i, int j)
{
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

void afisare()
{
	found = true;

	for (int i = 1; i <= n; ++i, fout << '\n')
	{
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == -1)
				fout << 0 << " ";
			else
				fout << a[i][j] << " ";
	}
}

void back(int i, int j, int pas)
{
	for (int d = 0; d <= 3 && !found; ++d)
	{
		int inou = i + di[d];
		int jnou = j + dj[d];

		if (inside(inou, jnou) && a[inou][jnou] == 0)
		{
			a[inou][jnou] = pas;

			if (inou == ib && jnou == jb)
				afisare();
			else
				back(inou, jnou, pas + 1);

			a[inou][jnou] = 0;
		}
	}
}

int main()
{
	fin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			fin >> s;

			if (s == '_')
			{
				a[i][j] = 0;
			}
			else
			{
				if (s == '#')
				{
					a[i][j] = -1;
				}
				else
				{
					if (s == 'S')
					{
						a[i][j] = 0;
						is = i;
						js = j;
					}
					else
					{
						if (s == 'B')
						{
							a[i][j] = 0;
							ib = i;
							jb = j;
						}
					}
				}
			}
		}

	a[is][js] = 1;

	back(is, js, 2);

	if (!found)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				fout << 0 << " ";
			fout << '\n';
		}
	}
	return 0;
}
