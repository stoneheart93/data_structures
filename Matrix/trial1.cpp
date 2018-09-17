#include<iostream>
using namespace std;
// Complete the CountNaturalNumber function below.
int CountNaturalNumber(int n) {
    int a[100];
    int temp[9];
    if(n <= 9)
    {
    	cout << "dwbug" << endl;
        for(int i = 0; i <= n; i++)
            a[i] = i;
    }
    for(int p = 0; p <= 9; p++)
            cout << a[p] << " ";
        cout << endl;
    if(n > 9)
    {
       for(int i = 10; i < n; i++)
       {
           int index = 0;
           while(i > 0)
           {
                int rem = i % 10;
                temp[index++] = rem;
                i = i % 10;
           }
           
           int count = 0;
           for(int j = 0; j < index - 1; j++)
           {
               if(temp[j] < temp[j+1])
                   break;
               else
                   count++;
           }
           if(count == index)
               a[i] = a[i-1] + 1;
           else
               a[i] = a[i-1];
            for(int p = 0; p <= 9; p++)
            cout << a[p] << " ";
        cout << endl;
    
           
       }
        
    
    }
    return a[n];
}

int main()
{
	int n = 10;
	cout << CountNaturalNumber(n) << endl;
	return 0;
	
}
