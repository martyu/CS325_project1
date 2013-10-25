//
//  project2.h
//  CS325_Project1
//
//  Created by Marty on 10/23/13.
//  Copyright (c) 2013 Marty. All rights reserved.
//

#ifndef CS325_Project1_project2_h
#define CS325_Project1_project2_h

#include <stdbool.h>

int main_project2(int argc, const char * argv[]);
int algorithm1(int arr1[], int sizeOfArr1, int arr2[], int sizeOfArr2);
int algorithm2(int arr1[], int sizeOfArr1, int arr2[], int sizeOfArr2);
struct indices makeIndices(int index1, int index2);
int computeSumOfSubArray(int arr[], struct indices subArrIndices);
int compare(const void * item1, const void * item2);

struct indices
{
	int index1;
	int index2;
};

struct sufficeSum
{
	int sum;
	bool negatedValue;
};

#endif
