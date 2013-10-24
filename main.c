//
//  main.c
//  CS325_Project1
//
//  Created by Marty on 10/23/13.
//  Copyright (c) 2013 Marty. All rights reserved.
//


#define PROJECT1 0
#define PROJECT2 1

#include <stdio.h>
#include "project1.h"
#include "project2.h"

int main(int argc, const char * argv[])
{
#if PROJECT1
	main_project1(argc, argv);
#elif PROJECT2
	main_project2(argc, argv);
#endif
}