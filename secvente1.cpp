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
		int n, p, k, x, i, nrPPrime;
		int pozitie[MAX_N];
		fin >> n >> p >> k;
		for (nrPPrime = i = 0; i < n; i++)
		{
			fin >> x;
			if (esteNumarPPrim(x, p))
				pozitie[nrPPrime++] = i;
		}
		if (k > nrPPrime)
			fout << 0 << '\n';
		else
		{
			fout << nrPPrime-k+1 << '\n';
			for (i = 0; i < nrPPrime-k+1; i++)
				fout << pozitie[i]+1 << ' ' << pozitie[i+k-1]+1 << '\n';
		}
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
