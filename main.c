//
//  main.c
//  CS325_Project1


#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct subArrIndices
{
	int start;
	int end;
};

void closeToZero1(int arr[]);
void closeToZero2(int arr[]);


int main(int argc, const char * argv[])
{
	int arr[] = {
		-360,948,-29,-447,515,-53,-491,-761,-719,-854,-77,-677,473,262,-95,844,-84,-875,241,-320,143,888,-524,-947,-652,
		260,503,882,-692,223,745,-245,37,-387,602,862,125,653,938,635,-960,-375,555,-730,-198,-691,-74,336,112,62,-319,
		-877,-416,-646,-207,616,608,737,-143,-747,-387,788,105,258,408,517,451,-718,358,118,-738,72,-457,-551,-726,580,
		-297,-662,-135,220,-267,773,117,669,905,152,-789,-243,-901,-241,-223,380,668,-514,-916,723,957,-222,605,-371,
	};

	clock_t startTime;
	clock_t endTime;
	double runTime;

	startTime = clock();
	closeToZero1(arr);
	endTime = clock();

	runTime = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	printf("Run time of algorithm 1: %lf\n", runTime);

	startTime = clock();
	closeToZero2(arr);
	endTime = clock();

	runTime = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	printf("Run time of algorithm 2: %lf\n", runTime);

	return 0;
}

void closeToZero1(int arr[])
{
	int bestTotal = INT_MAX;
	struct subArrIndices indices;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		for (int j = i+1; j < 100; j++)
		{
			indices.start = i;
			indices.end = j;

			int total = 0;
			for (int i = indices.start; i <= indices.end; i++)
			{
				total += arr[i];
			}

			if (abs(total) < abs(bestTotal))
			{
				bestTotal = total;
				bestTotalIndices = indices;

				if (bestTotal == 0)
				{
					goto end_loop;
				}
			}
		}
	}
end_loop:

	printf("Best subarray total found: %i\n", bestTotal);
	printf("Best subarray indices: %i, %i\n", bestTotalIndices.start, bestTotalIndices.end);
	printf("Values at those indices: %i, %i\n", arr[bestTotalIndices.start], arr[bestTotalIndices.end]);
}

void closeToZero2(int arr[])
{
	int bestTotal = INT_MAX;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		int total = arr[i];

		for (int j = i+1; j < 100; j++)
		{
			total += arr[j];

			if (abs(total) < abs(bestTotal))
			{
				bestTotal = total;

				bestTotalIndices.start = i;
				bestTotalIndices.end = j;

				if (bestTotal == 0)
				{
					goto end_loop;
				}
			}
		}
	}
end_loop:

	printf("Best subarray total found: %i\n", bestTotal);
	printf("Best subarray indices: %i, %i\n", bestTotalIndices.start, bestTotalIndices.end);
	printf("Values at those indices: %i, %i\n", arr[bestTotalIndices.start], arr[bestTotalIndices.end]);

}


