#include "frequentCurrentRange.h"
#include "a2dConverter.h"
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

/*"infers the number of ranges when NULL"*/
void TEST_CASE_02()
{
    float *readingsArray = NULL;
    int numOfReadings = 0;
    printf ("\n TEST_CASE_02 \nInput Array : ");
    printArray (readingsArray, numOfReadings);
    assert(detectRanges(readingsArray, numOfReadings) == 0);
}

/*"infers the number of ranges when mixed values*/
void TEST_CASE_03()
{
    float readingsArray[]={3, 3, 5, 4, 10, 11, 12};
    int numOfReadings = sizeof(readingsArray)/sizeof(readingsArray[0]);
    printf ("\n TEST_CASE_03 \nInput Array : ");
    printArray (readingsArray, numOfReadings);
    assert(detectRanges(readingsArray, numOfReadings) == 2);
}

/*"infers the number of ranges when mixed values in float*/
void TEST_CASE_04()
{
    float readingsArray[]={3.7, 1.2, 2.5, 4.5, 1.1, 11.2, 12.1,10.5,20,20.5};
    int numOfReadings = sizeof(readingsArray)/sizeof(readingsArray[0]);
    printf ("\n TEST_CASE_04 \nInput Array : ");
    printArray (readingsArray, numOfReadings);
    assert(detectRanges(readingsArray, numOfReadings) == 5);
}

//A2D Conversion
// Test Instance 1 
void TEST_CASE_05()
{
  int CurrentSamplesAnalog[] = {4095};
  int numOfReadings = sizeof(CurrentSamplesAnalog) / sizeof(CurrentSamplesAnalog[0]);
  float CurrentSamplesDigital[numOfReadings];
  printf ("\n TEST_CASE_05 \n Test Instance 1 : Error Reading available");
  assert(ConvertA2D_Amps(CurrentSamplesAnalog, numOfReadings,CurrentSamplesDigital,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == SAMPLES_NOT_OK);
}

// Test Instance 2 
void TEST_CASE_06()
{
  int CurrentSamplesAnalog[] = {4094, 819,3790,1230,1640,2870};
  int numOfReadings = sizeof(CurrentSamplesAnalog) / sizeof(CurrentSamplesAnalog[0]);
  float CurrentSamplesDigital[numOfReadings];
  printf ("\n TEST_CASE_06 \n Test Instance 2 : Test Conversion and Setting of Ranges for 12 bit");
	
  int ExpectedCurrentinAmps[] = {10, 2, 9, 3, 4 , 7};
  assert(ConvertA2D_Amps(CurrentSamplesAnalog, numOfReadings,CurrentSamplesDigital,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == SAMPLES_OK);
  for(int i = 0; i < numOfReadings; ++i)
	{
		assert(CurrentSamplesDigital[i] == ExpectedCurrentinAmps[i]);
	}
  assert(detectRanges(CurrentSamplesDigital, numOfReadings) == 3);
}

// Test Instance 3 
#define A2D_RESOLUTION  10
#define MAXCURRENTVALUE 15
#define MINCURRENTVALUE -15

void TEST_CASE_07()
{
  int CurrentSamplesAnalog_10bit[] = {1022,511,0};
  int numOfReadings = sizeof(CurrentSamplesAnalog_10bit) / sizeof(CurrentSamplesAnalog_10bit[0]);
  float CurrentSamplesDigital_10bit[numOfReadings];
  printf ("\n TEST_CASE_07 \n Test Instance 3 : Test Conversion and Setting of Ranges for 10 bit");
	
  int ExpectedCurrentinAmps_10bit[] = {15,0,15};
  assert(ConvertA2D_Amps(CurrentSamplesAnalog_10bit, numOfReadings,CurrentSamplesDigital_10bit,A2D_RESOLUTION,MAXCURRENTVALUE,MINCURRENTVALUE) == SAMPLES_OK);
  for(int i = 0; i < numOfReadings; ++i)
	{
		assert(CurrentSamplesDigital_10bit[i] == ExpectedCurrentinAmps_10bit[i]);
	}
  assert(detectRanges(CurrentSamplesDigital_10bit, numOfReadings) == 2);
}

int main()
{
	TEST_CASE_01();
	TEST_CASE_02();
	TEST_CASE_03();
	TEST_CASE_04();
	TEST_CASE_05();
	TEST_CASE_06();
	TEST_CASE_07();
	return 0;
}
