/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Main program file>
 *
 * @author <Sushrut Manu Singh>
 * @date <24.04.2020>
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"
#include "course1.h"

#define SIZE (40)


int main() {
  int arlen= 40;
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

 
  
  float mean = find_mean(test,arlen);
  float median = find_median(test,arlen);
  int max = find_maximum(test,arlen);
  int min = find_minimum(test,arlen);
  sort_array(test,40);
  printf("****STATS****\n");
  print_statistics(test, min, max, mean, median);
  unsigned char *ptr = test;
  print_array(ptr,40);
  #ifdef COURSE1
	course1();
  #endif
  return 0;
}

void print_statistics(unsigned char ar[], int mi, int ma, 
			float me, float md)
{	
	printf("***SORTED ARRAY***\n");
	sort_array(ar,40);
	printf("\n");
	printf("Maximum :%d\nMinimum :%d\nMean :%f\nMedian :%f\n",
		ma,mi,me,md);
	printf("Array will be printed only if VERBOSE FLAG is enabled\n");
}
	

void print_array(unsigned char * t, int size)
{	int i;
	if(t == NULL)
		return;
	#if !defined (VERBOSE) && defined (HOST)
	#undef PRINTF
	#define PRINTF(...)  
	#endif
	PRINTF("ARRAY\n");
	for( i = 0; i < size; i++)
		PRINTF("%u\t",(unsigned char)t[i]);
	PRINTF("\n");
	#if defined (VERBOSE) && defined (HOST)
	#undef PRINTF 
	#define PRINTF(...) printf(__VA_ARGS__)
	#endif
}

void sort_array(unsigned char inarr[], int size)
{
	int swap = 0;
	for(int i = 0; i<40; i++)
	{
		for(int j = 0; j<40; j++)
		{
			if(inarr[j]>inarr[i])
			{
				swap=inarr[i];
				inarr[i]=inarr[j];
				inarr[j]=swap;
			}
		}
	}
}

int find_maximum(unsigned char inparr[], int len)
{
	sort_array(inparr,len);
	return inparr[0];
}

int find_minimum(unsigned char inpuarr[], int leng)
{
	sort_array(inpuarr,leng);
        return inpuarr[39];
}


float find_mean(unsigned char meaarr[],int lenn)
{
	float sumt=0;
	float arrmea=0;
	for(int i=0; i<40; i++)
	{
		sumt=meaarr[i]+sumt;
	}
	arrmea = sumt/40.00;
	return arrmea;
	
}

float find_median(unsigned char inputarr[], int lengt)
{	float medianval;
	int centre = lengt/2;
	if(lengt%2==1)
	{medianval= inputarr[centre+1];}

	else medianval=(inputarr[centre]+inputarr[centre+1])/2;
	return medianval;
}
