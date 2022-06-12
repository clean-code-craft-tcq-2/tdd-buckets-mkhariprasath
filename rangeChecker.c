#include "frequentCurrentRanges.h"

int detectRanges(const float* readingsArray, int numOfReadings)
{
    int numofRange = 0;
   
    if((readingsArray != NULL) && (numOfReadings > 0))	
    {	   
	  float sortedArray[numOfReadings];
   	
      /*Sort the input array */	
      bubbleSortAscending(readingsArray, numOfReadings, sortedArray);
  
      /*check for ranges */
      float rangeMin = sortedArray[0];
      float rangeMax = sortedArray[0];
      int numOfReadingsInRange = 1;
	  printf("\nRange         Count\n");
      for (int i=0; i < numOfReadings;i++)
      {
        if(!(i == (numOfReadings-1)))
        {
            if((sortedArray[i+1] - sortedArray[i])<= 1.0f)
	        {
		      numOfReadingsInRange++;
		      rangeMax = sortedArray[i+1];
		      continue;
	        }    
        }
	    else
	    {
	        rangeMax = sortedArray[numOfReadings-1];
	    }
		printf("%.2f - %.2f , %d\n",rangeMin, rangeMax,numOfReadingsInRange);
        numOfReadingsInRange = 1;
	    rangeMin = sortedArray[i+1];
		rangeMax = sortedArray[i+1];
	    numofRange++;
      }	
    }
    else
    {
       printf("NULL array input");
    }
 
	return numofRange;
 
}
