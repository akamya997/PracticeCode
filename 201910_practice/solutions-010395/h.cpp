#include <string.h>
#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#define Tetra 105][105][105

i64 V[Tetra], R[Tetra], iR[Tetra], HR[Tetra], iHR[Tetra], HiR[Tetra], iHiR[Tetra];
i64 LiV[Tetra], rhomLaV[Tetra], trapeLaV[Tetra], verhomTV[Tetra], ivrhomTV[Tetra], vetrapeTV[Tetra], ivtrapeTV[Tetra];

int N, M, Q;

int main()
{
	//freopen("cot.in", "r", stdin);
	//freopen("cot.out","w",stdout);
	scanf("%d%d%d", &N, &M, &Q);
	int i, j, k;
	fortodo(i, 0, N + 3)
		fortodo(j, 0, i + 3)
			fortodo(k, 0, j + 3)
				HR[i][j][k] = iHR[i][j][k] = HiR[i][j][k] = iHiR[i][j][k] = 0;
	fortodo(i, 1, M)
		{
			int Mxi, Myi, Mzi, Mai;
			scanf("%d%d%d%d", &Mxi, &Myi, &Mzi, &Mai);
			HR[Mxi][Myi][Mzi]++;
			HR[Mxi + Mai][Myi][Mzi]--;
			HiR[Mxi][Myi][Mzi + 1]++;
			HiR[Mxi + Mai][Myi][Mzi + 1]--;
			iHR[Mxi][Myi + 1][Mzi]++;
			iHR[Mxi + Mai][Myi + Mai + 1][Mzi]--;
			iHiR[Mxi][Myi + 1][Mzi + 2]++;
			iHiR[Mxi + Mai][Myi + Mai + 1][Mzi + Mai + 2]--;
		}
	fortodo(i, 1, N - 1)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				{
					HR[i + 1][j][k] += HR[i][j][k];
					HiR[i + 1][j][k] += HiR[i][j][k];
					iHR[i + 1][j + 1][k] += iHR[i][j][k];
					iHiR[i + 1][j + 1][k + 1] += iHiR[i][j][k];
				}
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				{
					R[i][j][k] = HR[i][j][k] - iHR[i][j][k];
					iR[i][j][k] = HiR[i][j][k] - iHiR[i][j][k];
				}
	fortodo(i, 1, N)
		fortodo(j, 1, i - 1)
			fortodo(k, 1, j)
				{
					R[i][j + 1][k] += R[i][j][k];
					iR[i][j + 1][k + 1] += iR[i][j][k];
				}
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				V[i][j][k] = R[i][j][k] - iR[i][j][k];
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j - 1)
				V[i][j][k + 1] += V[i][j][k];
	// 去差分完成 
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				LiV[i][j][k] = V[i][j][k];
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 2, j)
				LiV[i][j][k] += LiV[i][j][k - 1];
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				rhomLaV[i][j][k] = trapeLaV[i][j][k] = LiV[i][j][k];
	fortodo(i, 1, N)
		fortodo(j, 1, i - 1)
			fortodo(k, 1, j)
				{
					rhomLaV[i][j + 1][k] += rhomLaV[i][j][k];
					trapeLaV[i][j + 1][k + 1] += trapeLaV[i][j][k];
				}
	fortodo(i, 0, N + 1)
		fortodo(j, 0, i + 1)
			fortodo(k, 0, j + 1)
				verhomTV[i][j][k] = ivrhomTV[i][j][k] = vetrapeTV[i][j][k] = ivtrapeTV[i][j][k] = 0;
	fortodo(i, 1, N)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				{
					verhomTV[i][j][k] = ivrhomTV[i][j][k] = rhomLaV[i][j][k];
					vetrapeTV[i][j][k] = ivtrapeTV[i][j][k] = trapeLaV[i][j][k];
				}
	fortodo(i, 1, N - 1)
		fortodo(j, 1, i)
			fortodo(k, 1, j)
				{
					verhomTV[i + 1][j][k] += verhomTV[i][j][k];
					ivrhomTV[i + 1][j + 1][k] += ivrhomTV[i][j][k];
					vetrapeTV[i + 1][j][k] += vetrapeTV[i][j][k];
					ivtrapeTV[i + 1][j + 1][k + 1] += ivtrapeTV[i][j][k];
				}
	fortodo(i, 1, Q)
		{
			int Qxi, Qyi, Qzi, Qai;
			scanf("%d%d%d%d", &Qxi, &Qyi, &Qzi, &Qai);
			Qxi--; Qyi--; Qzi--;
			i64 ans = 0;
			ans += ivtrapeTV[Qxi + Qai][Qyi + Qai][Qzi + Qai];
			ans -= ivtrapeTV[Qxi][Qyi][Qzi];
			ans -= vetrapeTV[Qxi + Qai][Qyi][Qzi];
			ans += vetrapeTV[Qxi][Qyi][Qzi];
			ans -= ivrhomTV[Qxi + Qai][Qyi + Qai][Qzi];
			ans += ivrhomTV[Qxi][Qyi][Qzi];
			ans += verhomTV[Qxi + Qai][Qyi][Qzi];
			ans -= verhomTV[Qxi][Qyi][Qzi];
			printf(INT64 "\n", ans);
		}
}

