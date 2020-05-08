/*
 * =================================================================================================
 * main.c
 * =================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "common.h"

int main(int argc, char *argv[])
{
	unsigned int number = 0;
	char a = 0;
	
	common_init();

	while(1)
	{	
		common_refresh();
//		number++;
//		if(number == 1000)
//		{
//			fscanf(stdin, "%c", &a);
//			if(a == "q")
//				break;
//			else
//				number = 0;
//		}
	}
	
	return SUCCESS;
}
















