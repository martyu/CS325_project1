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

struct algorithmRuntimes
{
	double algorithm1;
	double algorithm2;
};

struct subArrIndices closeToZero1(int arr[]);
struct subArrIndices closeToZero2(int arr[]);
void printSubArray(struct subArrIndices indices, int array[]);
struct algorithmRuntimes executeAlgorithms(int arraySize);
void printRuntime(struct algorithmRuntimes runtimes, int arraySize);


int main(int argc, const char * argv[])
{
	for (int arraySize = 100; arraySize <= 900; arraySize += 100)
	{
		struct algorithmRuntimes avgRuntime = {0.0, 0.0};
		for (int testNumber = 0; testNumber < 10; testNumber++)
		{
			struct algorithmRuntimes currentRuntime = executeAlgorithms(arraySize);
			avgRuntime.algorithm1 += currentRuntime.algorithm1;
			avgRuntime.algorithm2 += currentRuntime.algorithm2;
		}

		avgRuntime.algorithm1 /= (double)10.0;
		avgRuntime.algorithm2 /= (double)10.0;

		printRuntime(avgRuntime, arraySize);
	}
}

struct algorithmRuntimes executeAlgorithms(int arraySize)
{
	int arr[arraySize];
	struct algorithmRuntimes runTimes;

	for (int i = 0; i < arraySize; i++)
	{
		arr[i] = arc4random();
	}

	clock_t startTime;
	clock_t endTime;
	struct subArrIndices closeToZeroIndices;


	// Algorithm 1

	startTime = clock();
	closeToZeroIndices = closeToZero1(arr);
	endTime = clock();

	runTimes.algorithm1 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;


	// Algorithm 2

	startTime = clock();
	closeToZeroIndices = closeToZero2(arr);
	endTime = clock();

	runTimes.algorithm2 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	return runTimes;
}

struct subArrIndices closeToZero1(int arr[])
{
	int bestTotal = INT_MAX;
	struct subArrIndices indices;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		for (int j = i; j < 100; j++)
		{
			indices.start = i;
			indices.end = j;

			int total = 0;
			for (int k = indices.start; k <= indices.end; k++)
			{
				total += arr[k];
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

//	printf("Best subarray total found: %i\n", bestTotal);
//	printf("Best subarray indices: %i, %i\n", bestTotalIndices.start, bestTotalIndices.end);

	return bestTotalIndices;
}

struct subArrIndices closeToZero2(int arr[])
{
	int bestTotal = INT_MAX;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		int total = arr[i];

		if (abs(total) < abs(bestTotal))
		{
			bestTotal = total;

			bestTotalIndices.start = i;
			bestTotalIndices.end = i;

			if (bestTotal == 0)
			{
				goto end_loop;
			}
		}

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

//	printf("Best subarray total found: %i\n", bestTotal);
//	printf("Best subarray indices: %i, %i\n", bestTotalIndices.start, bestTotalIndices.end);

	return bestTotalIndices;
}

void printSubArray(struct subArrIndices indices, int array[])
{
	printf("Close to zero sub array: [");
	for (int i = indices.start; i <= indices.end; i++)
	{
		printf("%i,", array[i]);
	}
	printf("]\n");
}

void printRuntime(struct algorithmRuntimes runtimes, int arraySize)
{
	printf("Average runtime for algorithm 1 with array size %i: %lf\n", arraySize, runtimes.algorithm1);
	printf("Average runtime for algorithm 2 with array size %i: %lf\n\n", arraySize, runtimes.algorithm2);
}

