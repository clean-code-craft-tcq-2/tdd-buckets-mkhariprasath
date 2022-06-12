#include "frequentCurrentRanges.h"
#include "adc.h"
#include <assert.h>

#define A2D_RESOLUTION  12
#define MAXCURRENTVALUE 10
#define MINCURRENTVALUE 0

/*infers the number of ranges when all enteries are same*/
void TEST_CASE_01()
{
    float readingsArray[]={4,4,4,4};
    int numOfReadings = sizeof(readingsArray)/sizeof(readingsArray[0]);
    printf ("\n TEST_CASE_01 \nInput Array : ");
    printArray (readingsArray, numOfReadings);
    assert(detectRanges(readingsArray, numOfReadings) == 1);
}


int main()
{
	TEST_CASE_01();
	return 0;
}
