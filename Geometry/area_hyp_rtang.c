#include<stdio.h>
#include<math.h>

void findRightAngle(int A, int H)
{
    float D = pow(H,4) - 16 * A * A;
    if(D >= 0)
	{
	    float root1 = (H * H + sqrt(D))/2;
        float root2 = (H * H - sqrt(D))/2;
        float a = sqrt(root1);
        float b = sqrt(root2);
        if(b >= a)
            printf("%f %f %d", a, b, H);
        else
            printf("%f %f %d", b, a, H);
    }
	else
        printf("-1");
}

int main()
{
	int area, hypotenuse;
	scanf("%d %d", &area, &hypotenuse);
	findRightAngle(area, hypotenuse);
	return 0;
}
