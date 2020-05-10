/*******************************************************************
* @author Sushrut Singh
* @date 10-05-2020
*
*******************************************************************/
#include "data.h"
#include <stdint.h>

/******************************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t len;
	int32_t t;
	uint8_t i = 0;
	char flag = 0;
	
	if(data < 0 && base == 10) /* For signed data */
	{
		flag = 1;
		data = -data;
	}

	if(data == 0) 
	{
		*(ptr + ++i) = '\0';
		return i+1;
	}

	*(ptr + i++) = '\0';

	while( data != 0) 
	{
		*(ptr + i) =	data%base;
		i = i+1;
		data = data/base;
	}

	if( flag == 1 ) /* If there is no sign */
	{	
		*(ptr + i++) = '-';
	}

	len = i;
	i = 0;

        for ( i = 0; i < (len)/2; i++)
	{
                t = *(ptr + i );
                *(ptr + i ) = *( ptr + len - i - 1);
                *( ptr + len - i - 1) = t;

        }
        
	return len;
}
/*******************************************************************/

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

	int32_t data = 0;
	uint8_t t = (uint8_t)base;
	base = 1;
	uint8_t i = digits-2;
		
	if(!ptr)
		return -1;
	
	while( i > 0 ) {
		data += *(ptr + i ) * ( base ) ;
		i = i - 1;
		base*= t;
	}
	
	
	if(t == 10 && *(ptr + i) == '-')    
		data = -data;
	else
		data += *(ptr + i) * ( base ); 
	
	return data;

}
/*********************************************************************/


