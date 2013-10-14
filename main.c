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

struct subArrIndices closeToZero1(int arr[]);
struct subArrIndices closeToZero2(int arr[]);
void printSubArray(struct subArrIndices indices, int array[]);


int main(int argc, const char * argv[])
{
	int arr[] = {
		536,565,-319,653,667,67,-331,297,-688,963,730,-725,298,21,797,557,286,-641,-290,-151,271,-534,730,865,986,-4,-984,762,-792,-450,428,-753,49,245,-141,-710,325,-862,294,-859,517,-911,-671,223,-577,778,916,-871,-835,541,986,593,-913,-357,-358,478,616,958,-440,-75,155,645,508,-29,-715,-275,633,-790,-441,6,98,-232,-78,-941,-67,-29,539,-791,702,-81,-477,-481,978,901,-784,563,-589,-712,-860,373,872,-315,-13,-691,-953,-602,380,834,-734,-778
	};

	clock_t startTime;
	clock_t endTime;
	double runTime;
	struct subArrIndices closeToZeroIndices;


	// Algorithm 1

	startTime = clock();
	closeToZeroIndices = closeToZero1(arr);
	endTime = clock();

	runTime = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	printf("Run time of algorithm 1: %lf\n", runTime);

	printSubArray(closeToZeroIndices, arr);


	// Algorithm 2

	startTime = clock();
	closeToZeroIndices = closeToZero2(arr);
	endTime = clock();

	runTime = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	printf("Run time of algorithm 2: %lf\n", runTime);

	printSubArray(closeToZeroIndices, arr);


	return 0;
}

struct subArrIndices closeToZero1(int arr[])
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

	return bestTotalIndices;
}

struct subArrIndices closeToZero2(int arr[])
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

	return bestTotalIndices;
}


void printSubArray(struct subArrIndices indices, int array[])
{
	printf("[");
	for (int i = indices.start; i <= indices.end; i++)
	{
		printf("%i,", array[i]);
	}
	printf("]\n");
}


