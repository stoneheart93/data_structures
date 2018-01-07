#include<stdio.h>
#include<stdlib.h>

struct Box
{
	int h, w, d;  
};
 
int min(int x, int y)
{ 
	return (x < y)? x : y; 
}
 
int max(int x, int y)
{ 
	return (x > y)? x : y; 
}

int compare (const void *a, const void * b)
{
	return ((*(Box *)b).d * (*(Box *)b).w - (*(Box *)a).d * (*(Box *)a).w );
}
 
int maxStackHeight(Box a[], int n)
{
   	Box rot[3*n];
   	int index = 0, i, j, Max = -1;
   	for(i = 0; i < n; i++)
   	{
    	rot[index] = a[i];
      	index++;
 
      	rot[index].h = a[i].w;
      	rot[index].d = max(a[i].h, a[i].d);
      	rot[index].w = min(a[i].h, a[i].d);
      	index++;
 
 	    rot[index].h = a[i].d;
    	rot[index].d = max(a[i].h, a[i].w);
      	rot[index].w = min(a[i].h, a[i].w);
      	index++;
   	}
 
   	n = 3 * n;
 
   	qsort (rot, n, sizeof(rot[0]), compare);
 
   	int msh[n];
   	for(i = 0; i < n; i++)
    	msh[i] = rot[i].h;
 
   	for(i = 1; i < n; i++)
   	{
		for(j = 0; j < i; j++)
		{
        	if(rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h)
            	msh[i] = msh[j] + rot[i].h;
        }
	}
 
   	for(i = 0; i < n; i++)
    {
    	if(Max < msh[i])
        	Max = msh[i];
	}
   	return Max;
}
 
int main()
{
	Box a[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	int n = 4;
  	printf("The maximum possible height of stack is %d\n", maxStackHeight(a, n));
  	return 0;
}
