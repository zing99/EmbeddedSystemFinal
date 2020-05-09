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
/*
 * @file <stats.h> 
 * @brief <Header files for stats.c >
 *
 * @author Sushrut Manu Singh
 * @date 24.04.2020
 *
 */

#ifndef stats_h
#define stats_h


void print_statistics(unsigned char arr[], int min, int max, 
		      float mea, float med);
/* 
 * @breif Prints statistics of the array and the values 
 *        calculated.
 * 
 *  Prints the value of minimun, maximum, mean and median
 *  of the array by taking their values as input from the
 *  other fucntions. 
 *
 */

void print_array(unsigned char arr[]);
/*
 * @breif Prints the array provided.
 *
 * Takes the value of the the array provided with question
 * and prints its value by using a simple for loop fucntion.
 *
 * @param arr[]: Array to be printed
 *
 */

float find_mean(unsigned char arr[], int length);
/*
 * @breif Calculates mean of array
 *
 * Takes the value of the array provided and find its mean
 * value by adding all numbers and dividing it by length.
 *
 * @param arr[], length: length of array
 *
 */

float find_median(unsigned char arr[],int length);
/*
 * @brief Calculates median of array
 *
 * Divides the value of lenth by 2 and finds the middle values 
 * of the array. Returns two values for even value of length and
 * one value for odd value of length.
 *
 * @param arr[], length
 *
 */

int find_maximum(unsigned char arr[], int length);
/*
 * @breif Finds maximum value among the values of the array
 *
 * Takes the provided value of the array and then passes it
 * through the sort array function and then returns the first
 * value of the sorted array.
 *
 * @params arr[], lenght
 *
 */

int find_minimum(unsigned char arr[], int length);
/* 
 * @brief Finds minimum value among the values of the array
 *
 * Takes the value of the given array and then passes it 
 * through the sort array fuction and then returns the last
 * element of the sorted array.
 *
 * @params arr[], length
 *
 */

void sort_array(unsigned char arr[], int length);
/*
 * @breif Sorts the given array in descending order.
 *
 * Takes the given array and sorts it in descending order
 * Then stores the sorted array in old variable itself.
 *
 * @params arr[], length
 *
 */

#endif /* stats_h*/

