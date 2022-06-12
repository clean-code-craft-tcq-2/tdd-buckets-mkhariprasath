#define SAMPLES_OK      1
#define SAMPLES_NOT_OK  0

bool ConvertA2D_Amps(int *CurrentSamplesAnalog,int NumOfCurrentSamples,float *CurrentSamplesDigital,int A2DResolution, int MaxCurrentValue, int MinCurrentValue);
void PrintReadingsFaultyMessage(void);
float convertInputIntToAmpsValue(float conversionValue, float scalingFactor, int MinCurrentValue, int MaxCurrentValue);
int calculateTotalAmpsRange(int maxCurrentValue, int minCurrentValue);
float calculateMultiplyFactor(int x, int y);
int GetMaxValueOfConverter(int ResolutionSize);
