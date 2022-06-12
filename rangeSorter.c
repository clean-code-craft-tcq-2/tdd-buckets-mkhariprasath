#include "frequentCurrentRange.h"

void bubbleSortAscending(const float* inputArray, int numOfReadings, float* sortedArray)
{
   int c, d;
   float temp;
   
   /*Initialise sorting array with input array*/
   for(int i=0; i< numOfReadings ; i++)
   {
		sortedArray[i] = inputArray[i];
   }
      
   /*Bubble sorting */
  for (c = 0 ; c < numOfReadings; c++)
  {
    for (d = 0 ; d < numOfReadings - c - 1; d++)
    {
      if (sortedArray[d] > sortedArray[d+1]) 
      {
        temp       = sortedArray[d];
        sortedArray[d]   = sortedArray[d+1];
        sortedArray[d+1] = temp;
      }
    }
  }
   printf("\nSorted Array : ")  ;
      
   printArray (sortedArray,numOfReadings);
   
} 

void printArray (float *arrayIndex, int Arraysize)
{
	if (Arraysize <= 0)
	{
		printf("NULL ARRAY");	
	}
	else
	{
		for(int i=0; i< Arraysize ; i++)
		{
			printf("%.2f,", arrayIndex[i]);
		}
	}
}
