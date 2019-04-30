#include<stdio.h>

int main()
{
	int hh, mm, ss;
	char t;
	scanf("%d:%d:%d%c", &hh, &mm, &ss, &t);
	if(t == 'A')
	{
		if(hh == 12)
			hh = 0;
		printf("%02d:%02d:%02d", hh, mm, ss);
	}
	else
	{
		hh += 12;
		if(hh == 24)
			hh = 12;
		printf("%02d:%02d:%02d", hh, mm, ss);
	}
	return 0;
}
