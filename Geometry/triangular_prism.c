#include<stdio.h>

float findVolume(float l, float b, float h)
{
    float volume = (l * b * h) / 2;
    return volume;
}
 
int main()
{
	float l = 18, b = 12, h = 9;
	printf("Volume of triangular prism: %f", findVolume(l, b, h));
	return 0;
}
