    /////////////////////////////////////////////////////////////
   ////                                                    /////
  //// ***Sorting Array With Multi Threading Technique*** /////
 ////                                                    /////
/////////////////////////////////////////////////////////////
 
#include <stdio.h>
#include <stdint.h> //Include this header file for use intptr_t
#include <stdlib.h>
#include <pthread.h>

int array[8] = {16,25,4,13,18,5,19,12};
int sortedArray[8]; // Sorted array

void *Sort(void *num)
{
	int i;
	i = (intptr_t) num;
	int j; //Index of array
	int counter; //This is show how many number lower than each element array

	counter = 0;
	for (j=0; j<8; j++)
	{

		if (array[i]>array[j])
		{
			counter++;
		}
	}
	sortedArray[counter] = array[i];
}

int main(int argc, char *argv[])
{
	pthread_t thread_sorting[8]; //the thread identifier

	for (int i=0; i<8; i++)
	{

		pthread_create(&thread_sorting[i], NULL, Sort, (void *) (intptr_t) i); // create threads, I use (intptr_t) for prevention segmentation fault.
	}
	
	printf("%s \n", "Sorted array:");
	for (int i=0; i<8; i++)
	{

		pthread_join(thread_sorting[i], NULL); //wait for threads to exit
		printf("%d \n", sortedArray[i]); // Print sorted array
	}
	return 0;
}
