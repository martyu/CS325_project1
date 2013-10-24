//
//  main.h
//  CS325_Project1
//
//  Created by Marty on 10/23/13.
//  Copyright (c) 2013 Marty. All rights reserved.
//

#ifndef CS325_Project1_main_h
#define CS325_Project1_main_h

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

int closeToZero1(int arr[], int arrSize);
int closeToZero2(int arr[], int arrSize);
void printSubArray(struct subArrIndices indices, int array[]);
void printRuntime(struct algorithmRuntimes runtimes, int arraySize);
int sumOfArray(int arr[], int arrSize);
int sumOfSubArray(struct subArrIndices indices, int arr[]);
int main_project1(int argc, const char * argv[]);


#endif
