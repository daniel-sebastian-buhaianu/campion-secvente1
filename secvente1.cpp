#include <fstream>
#define MAX_N 15000
#define MAX_NR 30000
using namespace std;
bool esteNumarPPrim(int x, int p);
int main()
{
	ifstream fin("secvente1.in");
	ofstream fout("secvente1.out");
	int nrSeturiDeDate;
	fin >> nrSeturiDeDate;
	while (nrSeturiDeDate > 0)
	{
		int n, p, k, i, j;
		int a[MAX_N], nrp[MAX_N];
		fin >> n >> p >> k;
		fin >> a[0];
		// nrp[i] = numarul de numere p prime
		// din secventa a[0], a[1], ... , a[i]
		nrp[0] = esteNumarPPrim(a[0], p) ? 1 : 0;
		int nrSecvente = 0;
		int st[MAX_N], dr[MAX_N];
		if (nrp[0] && k == 1)
		{
			st[nrSecvente] = dr[nrSecvente] = 1;
			nrSecvente++;
		}
		for (i = 1; i < n; i++)
		{
			fin >> a[i];
			if (esteNumarPPrim(a[i], p))
				nrp[i] = nrp[i-1] + 1;
			else
				nrp[i] = nrp[i-1];
			if (i+1 == k
			    && nrp[0] && nrp[i] > nrp[i-1])
			{
				st[nrSecvente] = 1;
				dr[nrSecvente++] = i+1;
			}
		}
		for (i = 1; i <= n-k; i++)
			for (j = i+k-1; j < n; j++)
				if (esteNumarPPrim(a[i], p)
				    && esteNumarPPrim(a[j], p)
				    && nrp[j]-nrp[i-1] == k)
				{
					st[nrSecvente] = i+1;
					dr[nrSecvente] = j+1;
					nrSecvente++;
				}
		fout << nrSecvente << '\n';
		for (i = 0; i < nrSecvente; i++)
			fout << st[i] << ' ' << dr[i] << '\n';
		nrSeturiDeDate--;
	}
	fin.close();
	fout.close();
	return 0;
}
bool estePrim(int numar)
{
	if (numar == 1) return 0;
	if (numar == 2) return 1;
	if (numar % 2 == 0) return 0;
	for (int divizor = 3; divizor*divizor <= numar; divizor += 2)
		if (numar % divizor == 0) return 0;
	return 1;
}
bool esteNumarPPrim(int numar, int p)
{
	int numarulInitial, exponent, produs, q;
	numarulInitial = numar;
	for (exponent = 0, produs = 1; numar % p == 0;
	     produs *= p, numar /= p, exponent++);
	if (!exponent)
		return estePrim(numarulInitial) ? 1 : 0;
	q = numarulInitial / produs;
	if (q == 1) return 1;
	return estePrim(q) ? 1 : 0;
}
