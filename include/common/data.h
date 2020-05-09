/****************************************************************
*	@File  : data.h
*	@Breif : Conversion of integer to ASCII and ASCII to
*		 integer.
*
*	@Author: Sushrut Manu Singh
*	@Date  : 09-05-2020
*****************************************************************/

uint8_t my_itoa(int_32t data, unit8_t *ptr, unit32_t base);

/* @Breif To convert data from a standard integer type into an
 * ASCII string.
 * 
 * Convert a given 32 bit integer to ASCII string according to the base
 * provided by taking a char data set, integer and base as input.
 * 
 * @Return : Length of the string
 * /

int32_t my_atoi(uint_t *ptr, uint8_t digits, uint32_t base)

/* @Breif To convert data from an ASCII string into a standard
 * integer type data.
 * 
 * Convert a given ASCII string to an integer according to the base
 * provided by taking a pointer to char data set, length of string
 * and base as input.
 * 
 * @Return : Value of the integer
 * /

