#include<iostream>
#include<unordered_set>
using namespace std;

void nuts_bolts(char nuts[], char bolts[], int n)
{
	unordered_set<char> hash;
	
	for(int i = 0; i < n; i++)
		hash.insert(nuts[i]);
	
	for(int i = 0; i < n; i++)
	{
		if(hash.find(bolts[i]) != hash.end())
			nuts[i] = bolts[i];
	}
	
	for(int i = 0; i < n; i++)
		printf("%c ", nuts[i]);

	printf("\n");
	
	for(int i = 0; i < n; i++)
		printf("%c ", bolts[i]);
}

int main()
{
	int n;
	char nuts[20], bolts[20];
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf(" %c", &nuts[i]);
	
	for(int i = 0; i < n; i++)
		scanf(" %c", &bolts[i]);

	nuts_bolts(nuts, bolts, n);
	
	return 0;
}
