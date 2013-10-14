//
//  main.c
//  CS325_Project1


#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

struct subArrIndices
{
	int start;
	int end;
};

int computeSum(int arr[], struct subArrIndices subArrIndices);

int main(int argc, const char * argv[])
{
	int arr[] = {
		-360,948,-29,-447,515,-53,-491,-761,-719,-854,-77,-677,473,262,-95,844,-84,-875,241,-320,143,888,-524,-947,-652,
		260,503,882,-692,223,745,-245,37,-387,602,862,125,653,938,635,-960,-375,555,-730,-198,-691,-74,336,112,62,-319,
		-877,-416,-646,-207,616,608,737,-143,-747,-387,788,105,258,408,517,451,-718,358,118,-738,72,-457,-551,-726,580,
		-297,-662,-135,220,-267,773,117,669,905,152,-789,-243,-901,-241,-223,380,668,-514,-916,723,957,-222,605,-371
	};

	int total;
	int bestTotal = INT_MAX;
	struct subArrIndices indices;
	struct subArrIndices bestTotalIndices;

	for (int i = 0; i < 100; i++)
	{
		for (int j = i+1; j < 100; j++)
		{
			indices.start = i;
			indices.end = j;
			total = computeSum(arr, indices);
			if (abs(total) < abs(bestTotal))
			{
				bestTotal = total;
				bestTotalIndices = indices;
			}
		}
	}

    return 0;
}


int computeSum(int arr[], struct subArrIndices subArrIndices)
{
	int sum = 0;
	for (int i = subArrIndices.start; i < subArrIndices.end - 1; i++)
	{
		sum += arr[i];
	}

	return sum;
}