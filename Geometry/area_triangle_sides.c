#include<stdio.h>
#include<math.h>

float area(int a, int b, int c)
{
	//validity
	if (a < 0 || b < 0 || c < 0 || (a+b <= c) || a+c <= b || b+c <= a) // triangle inequality theorem
    {
        printf("Not a valid triangle");
        return -1;
    }
	float s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("Area: %f", area(a, b, c));
	return 0;
}
