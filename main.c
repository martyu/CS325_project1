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
		715,-782,469,548,438,-290,-560,-916,573,-362,-654,494,62,128,-589,-22,159,674,-875,490,-393,460,317,-350,232,872,470,-443,-814,-702,0,-126,-352,-945,-905,-113,-393,248,477,-720,-546,-102,785,826,-19,-943,872,857,50,935,894,416,794,448,-769,-88,728,-935,-96,-126,847,324,924,-389,-643,-253,523,-292,-786,-974,-155,-644,-895,246,771,457,-584,-537,477,34,879,782,0,158,5,-452,211,-780,-786,-638,-819,-751,226,-392,685,764,17,916,-823,562
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

	printSubArray(closeToZeroIndices, arr);

	printf("Run time of algorithm 1: %lf\n\n", runTime);


	// Algorithm 2

	startTime = clock();
	closeToZeroIndices = closeToZero2(arr);
	endTime = clock();

	runTime = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	printSubArray(closeToZeroIndices, arr);

	printf("Run time of algorithm 2: %lf\n", runTime);

	return 0;
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

	return bestTotalIndices;
}

struct subArrIndices closeToZero2(int arr[])
{
	int bestTotal = INT_MAX;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		int total = arr[i];

		for (int j = i; j < 100; j++)
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


