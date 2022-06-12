#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "adc.h"


void PrintReadingsFaultyMessage(void)
{
	printf("Readings are faulty\n");
}

float convertInputIntToAmpsValue(float conversionValue, float scalingFactor, int MinCurrentValue, int MaxCurrentValue){
	float currentValue;	
	currentValue = MinCurrentValue + (MaxCurrentValue * conversionValue * scalingFactor);
	return currentValue;
}

int calculateTotalAmpsRange(int maxCurrentValue, int minCurrentValue) {
	int totalCurrentRange;
	totalCurrentRange = maxCurrentValue - minCurrentValue;
	return totalCurrentRange;
}

float calculateMultiplyFactor(int x, int y) {
	float multiplyingFactor;
	multiplyingFactor = float(x) / float(y);
	return multiplyingFactor;
}

int GetMaxValueOfConverter(int ResolutionSize)
{
	return (pow(2,ResolutionSize) - 2);
}

void AtoDConvert(int CurrentSamplesAnalog[],int NumOfCurrentSamples,float CurrentSamplesDigital[],int A2DResolution, int MaxCurrentValue, int MinCurrentValue){
	int loopIndex;
	int totalCurrentRange;
	float currentCurrentValue;
	int maxConverterValue; 
	float conversionValue;
	float scalingFactor;
	
	maxConverterValue = GetMaxValueOfConverter(A2DResolution);
	totalCurrentRange = calculateTotalAmpsRange(MaxCurrentValue, MinCurrentValue);
	scalingFactor = calculateMultiplyFactor(totalCurrentRange, MaxCurrentValue);
	for (loopIndex=0; loopIndex< NumOfCurrentSamples; loopIndex++){
		conversionValue = calculateMultiplyFactor(CurrentSamplesAnalog[loopIndex], maxConverterValue);
		currentCurrentValue = convertInputIntToAmpsValue(conversionValue, scalingFactor, MinCurrentValue, MaxCurrentValue);
		CurrentSamplesDigital[loopIndex] = round(currentCurrentValue);
		if(CurrentSamplesDigital[loopIndex] <0){
			CurrentSamplesDigital[loopIndex] = abs(CurrentSamplesDigital[loopIndex]);
		}
	}
}

bool ConvertA2D_Amps(int *CurrentSamplesAnalog,int NumOfCurrentSamples,float *CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue){
  bool AreAllSamplesOk = SAMPLES_OK;
  int loopIndex;
  
  for(loopIndex=0;loopIndex<NumOfCurrentSamples;loopIndex++){
    if(CurrentSamplesAnalog[loopIndex] > (GetMaxValueOfConverter(A2DResolution))){
	AreAllSamplesOk = SAMPLES_NOT_OK;
	PrintReadingsFaultyMessage();	
	break;
	}
  }
  if(AreAllSamplesOk == SAMPLES_OK)
  {
	 AtoDConvert(CurrentSamplesAnalog, NumOfCurrentSamples,CurrentSamplesDigital, A2DResolution, MaxCurrentValue, MinCurrentValue);
  }
  
  return AreAllSamplesOk ;
}
