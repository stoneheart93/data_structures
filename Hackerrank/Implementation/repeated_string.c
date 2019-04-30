#include<stdio.h>

int main()
{
	char str[200];
	long long int no, len, occ = 0, a = 0;
	int substr, i;
	
	scanf("%s", str);
	scanf("%lld", &no);
	
	for(len = 0; str[len]; len++)
	{
		if(str[len] == 'a')
			occ++;
	}
	
	a = (no / len) * occ;
	
	substr = no % len;
	for(i = 0; i < substr; i++)
	{
		if(str[i] == 'a')
			a++;
	}
	
	printf("%lld", a);
	return 0;
}
