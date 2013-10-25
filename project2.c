//
//  main.c
//  CS325_Project2
//
//  Created by Marty on 10/23/13.
//  Copyright (c) 2013 Marty. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "project2.h"
#include "project1.h"


struct algorithmRuntimes _executeAlgorithms(int arraySize);
void checkRuntimes1();
int algorithm3And4(int arr[], int sizeOfArr, bool algorithm3);
void checkTestArrays1();

#define TEST_ARRAY_SIZE 100
#define NUM_OF_TEST_ARRAYS 10


static int testArrays[NUM_OF_TEST_ARRAYS][TEST_ARRAY_SIZE] = {
	{-360,948,-29,-447,515,-53,-491,-761,-719,-854,-77,-677,473,262,-95,844,-84,-875,241,-320,143,888,-524,-947,-652,260,503,882,-692,223,745,-245,37,-387,602,862,125,653,938,635,-960,-375,555,-730,-198,-691,-74,336,112,62,-319,-877,-416,-646,-207,616,608,737,-143,-747,-387,788,105,258,408,517,451,-718,358,118,-738,72,-457,-551,-726,580,-297,-662,-135,220,-267,773,117,669,905,152,-789,-243,-901,-241,-223,380,668,-514,-916,723,957,-222,605,-371},
	{536,565,-319,653,667,67,-331,297,-688,963,730,-725,298,21,797,557,286,-641,-290,-151,271,-534,730,865,986,-4,-984,762,-792,-450,428,-753,49,245,-141,-710,325,-862,294,-859,517,-911,-671,223,-577,778,916,-871,-835,541,986,593,-913,-357,-358,478,616,958,-440,-75,155,645,508,-29,-715,-275,633,-790,-441,6,98,-232,-78,-941,-67,-29,539,-791,702,-81,-477,-481,978,901,-784,563,-589,-712,-860,373,872,-315,-13,-691,-953,-602,380,834,-734,-778},
	{715,-782,469,548,438,-290,-560,-916,573,-362,-654,494,62,128,-589,-22,159,674,-875,490,-393,460,317,-350,232,872,470,-443,-814,-702,0,-126,-352,-945,-905,-113,-393,248,477,-720,-546,-102,785,826,-19,-943,872,857,50,935,894,416,794,448,-769,-88,728,-935,-96,-126,847,324,924,-389,-643,-253,523,-292,-786,-974,-155,-644,-895,246,771,457,-584,-537,477,34,879,782,0,158,5,-452,211,-780,-786,-638,-819,-751,226,-392,685,764,17,916,-823,562},
	{615,-462,-8,-141,-351,-936,-912,903,753,818,170,-188,-999,618,711,160,829,357,36,815,-817,-575,-795,-536,986,-124,471,-335,-910,-51,40,974,627,-20,-63,727,-767,526,-652,-384,818,-279,-523,-868,321,441,380,-786,-254,693,-522,356,298,367,-107,-534,149,662,62,-377,-693,38,-612,259,170,-76,-580,-893,-154,869,498,497,-32,-476,-898,-349,406,526,614,16,-820,-123,696,528,721,555,361,-62,-806,-98,-911,-615,-186,762,-629,287,888,611,-340,-900},
	{-653,922,-447,389,277,355,-917,77,-149,-428,-168,-999,-99,40,722,671,-977,-661,-151,-731,-1,-83,261,477,522,241,704,-158,-553,-389,578,256,-307,375,-623,335,502,-906,503,-70,632,881,229,210,-39,66,-804,-565,799,-674,330,-17,-242,-613,-412,822,-889,-479,-472,946,857,-460,-778,-484,-345,-729,70,117,640,581,524,-196,-507,-407,602,933,364,-957,307,725,-758,286,613,20,-564,-501,656,-967,-626,130,-507,201,580,-175,704,-229,-394,572,352,555},
	{-989,-519,553,820,-971,-75,-619,-180,614,-764,338,596,83,437,742,-56,469,-910,670,307,-906,-725,923,-677,-478,-639,-217,351,555,-539,544,-843,146,-308,-33,-554,307,-545,731,987,-281,811,254,-181,329,490,575,610,464,-636,745,704,468,-540,397,772,843,-154,344,245,-224,764,-315,938,988,545,-456,794,512,622,408,-559,-305,-751,-217,-37,-460,67,333,-300,833,916,534,-983,181,210,-469,-953,375,156,-65,-268,-12,-130,-877,-93,-253,-169,-891,415},
	{358,564,708,-378,-778,-971,793,56,10,227,-883,156,-900,-346,463,-575,-712,-36,254,-536,-486,-551,889,-383,-603,720,-265,959,131,-417,-36,-86,368,-719,996,-466,8,363,537,-849,-13,-885,-879,773,-333,552,482,18,322,983,-206,-165,-620,-850,-435,100,-282,-484,-69,268,-552,380,-873,906,642,-581,388,418,735,-516,158,-445,-601,-879,11,667,184,-981,770,-717,-526,-181,-631,765,-189,566,979,500,-45,624,-371,544,-266,-998,78,-553,-2,145,-447,-70},
	{467,-82,-307,-8,259,-907,-804,106,-25,666,-76,811,65,315,686,-179,-286,-609,-133,-158,-103,377,384,-687,-195,604,-845,-100,809,-230,858,-706,857,863,-364,389,-86,-366,710,246,709,477,611,-290,854,-213,-406,-706,361,-871,-6,676,-13,-643,56,294,-225,-137,76,-466,285,346,-938,-594,-603,378,-557,593,-727,-876,221,748,390,401,203,163,298,-671,805,-32,-683,-331,977,-987,-266,170,718,791,47,433,-614,-709,-682,31,-696,11,-46,596,-483,-480},
	{-306,345,-212,582,361,-947,-968,-757,657,-189,-893,272,-352,313,122,167,-267,242,64,16,-896,721,256,-602,-707,-691,467,-351,-990,-291,609,-381,378,-561,-249,138,-554,-478,759,-482,-406,531,179,319,445,661,-254,299,-475,159,696,308,522,133,405,-636,-221,-440,-542,452,456,-26,419,-845,-835,-192,-358,-403,-557,535,890,839,541,844,499,-399,-180,773,-680,972,-823,981,-123,-879,816,0,-849,-368,899,-203,780,389,422,454,301,-756,586,-850,175,-797},
	{487,-625,72,311,-819,-70,-560,5,643,138,-564,117,762,952,972,629,-622,-238,888,-258,-858,584,66,-558,-446,-146,132,229,-131,322,-858,197,538,240,-834,671,-588,-148,472,-502,452,-98,-950,371,-473,-707,593,363,896,-275,-230,309,-22,-875,-899,-292,-914,787,435,477,-505,-166,-65,29,339,977,-350,-883,-427,-513,685,341,-524,752,-515,946,167,-644,-692,-155,-1,124,536,-743,745,192,21,-161,-640,604,702,504,-936,-704,-361,843,-927,247,863,526}
};


int main_project2(int argc, const char * argv[])
{
//	int arr1[] = {31, -41, 59, 26, -53, 58, -6, 97, -93, -23, 84};
//	int arr2[] = {9, -74, 68, 4, 100, 67, 95};
//	int arr3[] = {59, 26, -53, 58, -6, 97, -93, -23, 9, -74, 68, 4, 100, 67, 95};
//
//	int closeToZeroProblems[NUM_OF_TEST_ARRAYS][TEST_ARRAY_SIZE] = {
//		{360,-948,-29,447,515,-53,491,761,719,-854,77,-677,473,-262,95,844,84,875,241,-320,143,-888,-524,947,652,-260,-503,-882,-692,-223,-745,-245,37,387,-602,-862,-125,653,938,635,-960,375,-555,730,-198,-691,74,-336,112,62,-319,-877,416,646,207,616,608,-737,143,-747,387,788,105,258,408,517,451,-718,-358,-118,738,72,457,551,-726,580,297,-662,135,-220,-267,773,117,-669,905,152,789,-243,901,-241,-223,-380,668,514,-916,-723,957,-222,605,371},
//		{-536,565,-319,653,667,67,331,297,-688,-963,730,725,-298,21,-797,557,-286,-641,290,151,-271,534,730,-865,986,-4,984,-762,-792,-450,428,753,49,-245,-141,-710,-325,862,-294,859,-517,-911,-671,-223,-577,-778,-916,871,835,541,-986,-593,-913,357,358,478,-616,-958,440,-75,-155,-645,508,-29,715,275,-633,790,-441,-6,98,-232,78,-941,67,-29,539,791,-702,-81,-477,481,-978,-901,784,-563,-589,712,860,373,872,315,-13,-691,953,-602,-380,-834,-734,-778},
//		{715,-782,469,548,438,290,-560,-916,573,362,654,494,62,-128,-589,22,159,-674,-875,-490,393,-460,317,350,-232,872,-470,443,814,-702,0,-126,352,945,905,113,-393,-248,-477,720,-546,102,785,-826,19,-943,-872,-857,-50,-935,894,416,-794,-448,769,-88,728,-935,96,-126,847,-324,-924,389,-643,-253,-523,-292,786,974,-155,-644,-895,-246,771,-457,-584,537,477,-34,879,-782,0,158,-5,-452,211,-780,-786,-638,819,751,-226,-392,-685,-764,17,-916,823,-562},
//		{-615,462,8,141,-351,-936,-912,903,753,-818,170,-188,999,618,-711,160,829,-357,-36,815,817,575,795,-536,-986,-124,-471,-335,-910,-51,40,-974,627,-20,-63,727,767,526,-652,384,818,279,-523,868,-321,-441,380,-786,254,-693,522,-356,-298,367,107,-534,149,662,-62,-377,693,38,-612,259,-170,76,580,893,-154,869,498,497,32,476,898,-349,406,526,614,-16,-820,-123,696,528,721,-555,361,-62,806,98,911,615,186,-762,-629,-287,888,-611,340,900},
//		{-653,922,-447,389,277,355,917,-77,149,-428,-168,999,-99,40,-722,671,977,661,-151,-731,1,-83,-261,-477,-522,241,704,-158,553,-389,578,256,-307,375,-623,-335,502,-906,503,-70,-632,881,229,210,39,66,804,-565,799,-674,330,-17,-242,613,412,-822,-889,-479,-472,-946,-857,-460,-778,484,345,729,-70,-117,-640,581,524,-196,-507,407,602,-933,-364,-957,-307,-725,758,-286,613,-20,564,501,-656,-967,-626,-130,507,-201,580,-175,-704,-229,-394,-572,-352,555},
//		{-989,519,-553,-820,971,75,619,180,614,-764,-338,1,83,437,-742,-56,-469,910,670,307,-906,-725,-923,-677,-478,639,217,351,555,-539,-544,843,146,308,33,554,307,-545,731,-987,281,811,-254,-181,-329,-490,575,610,-464,636,-745,-704,468,-540,397,-772,843,154,344,-245,224,764,315,938,988,-545,456,794,-512,-622,408,559,305,-751,-217,-37,460,67,333,300,-833,-916,534,-983,-181,210,469,-953,375,-156,65,-268,-12,130,877,-93,-253,169,-891,415},
//		{358,564,708,-378,778,-971,793,-56,10,227,883,156,-900,-346,-463,-575,-712,-36,-254,-536,486,-551,889,383,-603,720,265,959,131,-417,-36,-86,-368,-719,-996,466,8,-363,-537,849,-13,-885,879,-773,-333,552,-482,-18,322,983,-206,-165,-620,-850,-435,-100,282,-484,-69,268,552,-380,873,906,-642,581,388,-418,-735,-516,158,-445,-601,-879,11,-667,184,-981,-770,717,-526,-181,631,765,189,-566,-979,-500,-45,624,-371,544,266,998,-78,553,-2,-145,447,70},
//		{-467,-82,307,8,-259,-907,804,-106,-25,-666,76,-811,-65,-315,686,-179,-286,609,-133,-158,-103,377,-384,687,195,-604,845,100,809,-230,-858,-706,857,-863,364,-389,-86,366,-710,246,709,477,611,290,-854,-213,-406,-706,-361,871,6,676,-13,643,56,294,-225,137,-76,466,-285,346,-938,594,603,-378,-557,-593,-727,-876,-221,-748,390,401,-203,163,298,671,-805,32,683,331,977,-987,-266,170,-718,791,-47,-433,614,-709,682,-31,696,-11,-46,596,-483,480},
//		{306,345,212,582,-361,-947,968,757,-657,-189,-893,272,352,313,-122,-167,267,-242,64,-16,-896,-721,256,-602,707,691,467,-351,-990,-291,-609,-381,378,-561,-249,-138,-554,-478,-759,482,-406,-531,179,319,-445,661,254,-299,475,-159,-696,-308,522,133,405,636,221,-440,-542,-452,456,26,-419,845,835,192,358,403,557,-535,-890,-839,-541,844,-499,-399,-180,773,680,-972,-823,-981,-123,-879,816,0,849,-368,899,-203,780,-389,422,-454,-301,-756,586,-850,-175,-797},
//		{-487,-625,-72,-311,819,70,560,5,-643,138,564,117,-762,-952,-972,629,-622,238,-888,258,-858,-584,66,558,-446,146,132,-229,-131,322,-858,197,-538,-240,-834,671,-588,-148,-472,-502,-452,98,-950,371,-473,707,-593,363,896,275,-230,-309,-22,875,899,292,-914,-787,435,-477,-505,166,65,-29,339,977,-350,-883,427,-513,-685,341,-524,752,-515,-946,-167,644,-692,-155,-1,124,-536,743,-745,192,21,161,640,604,702,-504,-936,704,361,-843,927,247,863,-526},
//	};

	// split array into two halves
//	int halfArr_1[5];
//	int halfArr_2[6];
//
//	// make first half
//	for(int i = 0; i < 5; i++)
//	{
//		halfArr_1[i] = arr1[i];
//	}
//
//	// make second half
//	for(int i = 5, j = 0; i < 11; i++, j++)
//	{
//		halfArr_2[j] = arr1[i];
//	}
//
//	for (int problem = 0; problem < 10; problem++)
//	{
//		checkTestArrays1();
//	}

	checkRuntimes1();

	return 0;
}

void checkTestArrays1()
{
	int testAnswers[] = {0, -2, 0, 0, 0, -3, -2, 1, 0, -1};

	printf("\nclose to zero test:\n");
	for (int i = 0; i < NUM_OF_TEST_ARRAYS; i++)
	{
		int sum = closeToZero1(testArrays[i], TEST_ARRAY_SIZE);

		printf("Test %i ", i);

		if (sum == testAnswers[i])
		{
			printf("passed.\n");
		}
		else
		{
			printf("failed. expected: %i, got: %i\n", testAnswers[i], sum);
			exit(1);
		}
	}

	printf("\nalgorithm 3 test:\n");
	for (int i = 0; i < NUM_OF_TEST_ARRAYS; i++)
	{
		int sum = algorithm3And4(testArrays[i], TEST_ARRAY_SIZE, true);

		printf("Test %i ", i);

		if (sum == testAnswers[i])
		{
			printf("passed.\n");
		}
		else
		{
			printf("failed. expected: %i, got: %i\n", testAnswers[i], sum);
			exit(1);
		}
	}


	printf("\nalgorithm 4 test:\n");
	for (int i = 0; i < NUM_OF_TEST_ARRAYS; i++)
	{
		int sum = algorithm3And4(testArrays[i], TEST_ARRAY_SIZE, false);

		printf("Test %i ", i);

		if (sum == testAnswers[i])
		{
			printf("passed.\n");
		}
		else
		{
			printf("failed. expected: %i, got: %i\n", testAnswers[i], sum);
			exit(1);
		}
	}

}


void checkRuntimes1()
{
	for (int arraySize = 100; arraySize <= 900; arraySize += 100)
	{
		struct algorithmRuntimes avgRuntime = {0.0, 0.0};
		for (int testNumber = 0; testNumber < 10; testNumber++)
		{
			struct algorithmRuntimes currentRuntime = _executeAlgorithms(arraySize);
			avgRuntime.algorithm1 += currentRuntime.algorithm1;
			avgRuntime.algorithm2 += currentRuntime.algorithm2;
			avgRuntime.algorithm3 += currentRuntime.algorithm3;
			avgRuntime.algorithm4 += currentRuntime.algorithm3;
		}

		avgRuntime.algorithm1 /= (double)10.0;
		avgRuntime.algorithm2 /= (double)10.0;
		avgRuntime.algorithm3 /= (double)10.0;
		avgRuntime.algorithm4 /= (double)10.0;

		printRuntime(avgRuntime, arraySize);
	}

	for (int arraySize = 1000; arraySize <= 9000; arraySize += 1000)
	{
		struct algorithmRuntimes avgRuntime = {0.0, 0.0};
		for (int testNumber = 0; testNumber < 10; testNumber++)
		{
			struct algorithmRuntimes currentRuntime = _executeAlgorithms(arraySize);
			avgRuntime.algorithm1 += currentRuntime.algorithm1;
			avgRuntime.algorithm2 += currentRuntime.algorithm2;
			avgRuntime.algorithm3 += currentRuntime.algorithm3;
			avgRuntime.algorithm4 += currentRuntime.algorithm4;
		}

		avgRuntime.algorithm1 /= (double)10.0;
		avgRuntime.algorithm2 /= (double)10.0;
		avgRuntime.algorithm3 /= (double)10.0;
		avgRuntime.algorithm4 /= (double)10.0;

		printRuntime(avgRuntime, arraySize);
	}
}

struct algorithmRuntimes _executeAlgorithms(int arraySize)
{
	int arr[arraySize];
	struct algorithmRuntimes runTimes;

	// split array into two halves
	int halfArr1_size = arraySize/2;
	int halfArr2_size = arraySize - arraySize/2;
	int *halfArr_1 = (int*)malloc(sizeof(int) * halfArr1_size);
	int *halfArr_2 = (int*)malloc(sizeof(int) * halfArr2_size);

	// make first half
	for(int i = 0; i < arraySize/2; i++)
	{
		halfArr_1[i] = arr[i];
	}

	// make second half
	for(int i = arraySize/2, j = 0; i < arraySize; i++, j++)
	{
		halfArr_2[j] = arr[i];
	}

	for (int i = 0; i < arraySize; i++)
	{
		arr[i] = arc4random();
	}

	clock_t startTime;
	clock_t endTime;
	int closestToZero1, closestToZero2, closestToZero3, closestToZero4;

	// Algorithm 1

	if (arraySize <= 900)
	{
		startTime = clock();
		closestToZero1 = algorithm1(halfArr_1, halfArr1_size, halfArr_2, halfArr2_size);
		endTime = clock();

		runTimes.algorithm1 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;
	}


	// Algorithm 2

	startTime = clock();
	closestToZero2 = algorithm2(halfArr_1, halfArr1_size, halfArr_2, halfArr2_size);
	endTime = clock();

	runTimes.algorithm2 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;


	// Algorithm 3

	if (arraySize <= 900)
	{
		startTime = clock();
		closestToZero3 = algorithm3And4(arr, arraySize, true);
		endTime = clock();

		runTimes.algorithm3 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;
	}

	// Algorithm 4

	startTime = clock();
	closestToZero4 = algorithm3And4(arr, arraySize, false);
	endTime = clock();

	runTimes.algorithm4 = (double)(endTime - startTime) / (double)CLOCKS_PER_SEC;

	return runTimes;
}

#pragma mark Algorithms

int algorithm1(int arr1[], int sizeOfArr1, int arr2[], int sizeOfArr2)
{
	int closestSumToZero = INT_MAX;

	for (int i = sizeOfArr1 - 1; i >= 0; i--)
	{
		int subArr1Total = computeSumOfSubArray(arr1, makeIndices(i, sizeOfArr1-1));

		for (int j = sizeOfArr2 - 1; j >= 0; j--)
		{
			int subArr2Total = computeSumOfSubArray(arr2, makeIndices(j, sizeOfArr2-1));

			int sumOfSuffices = subArr1Total + subArr2Total;

			if (abs(sumOfSuffices) < abs(closestSumToZero))
			{
				closestSumToZero = sumOfSuffices;
			}
		}
	}

	return closestSumToZero;
}

int algorithm2(int arr1[], int sizeOfArr1, int arr2[], int sizeOfArr2)
{
	int closestSumToZero = INT_MAX;

	struct sufficeSum *suffixTotalsArr = (struct sufficeSum*)malloc(sizeof(struct sufficeSum) * (sizeOfArr1 + sizeOfArr2));
	int totalsArrIndex = 0;

	for (int i = sizeOfArr1 - 1; i >= 0; i--)
	{
		struct sufficeSum sufficeSum;
		sufficeSum.sum = computeSumOfSubArray(arr1, makeIndices(i, sizeOfArr1 - 1));
		sufficeSum.negatedValue = false;
		suffixTotalsArr[totalsArrIndex++] = sufficeSum;
	}

	for (int i = sizeOfArr2 - 1; i >= 0; i--)
	{
		struct sufficeSum sufficeSum;
		sufficeSum.sum = -computeSumOfSubArray(arr2, makeIndices(i, sizeOfArr2 - 1));
		sufficeSum.negatedValue = true;
		suffixTotalsArr[totalsArrIndex++] = sufficeSum;
	}

	mergesort(suffixTotalsArr, sizeOfArr1+sizeOfArr2, sizeof(struct sufficeSum), compare);

	for (int i = 0; i < sizeOfArr2 + sizeOfArr1 - 1; i++)
	{
		// find the closest neighbor from the opposite source array.
		int j = i+1;
		struct sufficeSum arr1Value, arr2Value;

		// make sure it's not from the same source array
		while (suffixTotalsArr[i].negatedValue == suffixTotalsArr[j].negatedValue)
		{
			j++;
		}

		// get the two values to compare.
		arr1Value = suffixTotalsArr[i];
		arr2Value = suffixTotalsArr[j];

		// get the non-negated value.
		if (arr1Value.negatedValue)
			arr1Value.sum = -arr1Value.sum;
		else if (arr2Value.negatedValue)
			arr2Value.sum = -arr2Value.sum;
		else
			exit(EXIT_FAILURE);

		// check if it's closer to zero than the current closest.
		if (abs(arr1Value.sum + arr2Value.sum) < abs(closestSumToZero))
			closestSumToZero = arr1Value.sum + arr2Value.sum;
	}

	return closestSumToZero;
}

int algorithm3And4(int arr[], int sizeOfArr, bool algorithm3)
{
	if (sizeOfArr == 1)
		return arr[0];

	// split array into two halves
	int halfArr1_size = sizeOfArr/2;
	int halfArr2_size = sizeOfArr - sizeOfArr/2;
	int *halfArr_2_backwards = (int*)malloc(sizeof(int) * halfArr2_size);
	int *halfArr_1 = (int*)malloc(sizeof(int) * halfArr1_size);
	int *halfArr_2 = (int*)malloc(sizeof(int) * halfArr2_size);

	// make backwards second half
	for(int i = sizeOfArr-1, j = 0; i >= sizeOfArr/2; i--, j++)
	{
		halfArr_2_backwards[j] = arr[i];
	}

	// make first half
	for(int i = 0; i < sizeOfArr/2; i++)
	{
		halfArr_1[i] = arr[i];
	}

	// make second half
	for(int i = sizeOfArr/2, j = 0; i < sizeOfArr; i++, j++)
	{
		halfArr_2[j] = arr[i];
	}

	// recurse on each half, save result
	int closestToZero1 = algorithm3And4(halfArr_1, sizeOfArr/2, algorithm3);
	int closestToZero2 = algorithm3And4(halfArr_2, sizeOfArr - sizeOfArr/2, algorithm3);

	// get smallest sum of each half combined
	int sumOfSuffices;
	if (algorithm3)
		sumOfSuffices = algorithm1(halfArr_1, halfArr1_size, halfArr_2_backwards, halfArr2_size);
	else
		sumOfSuffices = algorithm2(halfArr_1, halfArr1_size, halfArr_2_backwards, halfArr2_size);

	if (abs(closestToZero1) < abs(closestToZero2) && abs(closestToZero1) < abs(sumOfSuffices))
	{
		return closestToZero1;
	}
	else if (abs(closestToZero2) < abs(sumOfSuffices))
	{
		return closestToZero2;
	}
	else
	{
		return sumOfSuffices;
	}

}


#pragma mark Helper functions

int compare(const void * item1, const void * item2)
{
    struct sufficeSum f = *((struct sufficeSum*)item1);
    struct sufficeSum s = *((struct sufficeSum*)item2);
    if (f.sum > s.sum) return  1;
    if (f.sum < s.sum) return -1;
    return 0;
}


int computeSumOfSubArray(int arr[], struct indices subArrIndices)
{
	int total = 0;
	for (int i = subArrIndices.index1; i <= subArrIndices.index2; i++)
	{
		total += arr[i];
	}

	return total;
}


struct indices makeIndices(int index1, int index2)
{
	struct indices ret;
	ret.index1 = index1;
	ret.index2 = index2;
	return ret;
}

