#include<string>
#include<iostream>
using namespace std;

int makeEqualLength(string& num1, string& num2)
{
	int length = max(num1.length(), num2.length());
	
	while(num1.length() < length)
		num1.insert(0,"0");
	
	while(num2.length() < length)
		num2.insert(0,"0");
		
	return length;
}

string add(string num1, string num2)
{
	int length = makeEqualLength(num1, num2);
	int sum, carry = 0;
	string result = "";
	
	for(int i = length - 1; i >= 0; i--)
	{
		sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		result.insert(0, to_string(sum % 10));
		carry = sum / 10;
	}
	
	if(carry)
		result.insert(0, to_string(carry));
	
	return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string num1, string num2)
{
	int length = makeEqualLength(num1, num2);
	int diff;
	string result = "";
	
	for(int i = length - 1; i >= 0; i--)
	{
		diff = (num1[i] - '0') - (num2[i] - '0');
		if(diff >= 0)
			result.insert(0, to_string(diff));
		else
		{
			int j = i - 1;
			while(j >= 0)
			{
				num1[j] = (num1[j] - '0') - 1 + '0';
				if(num1[j] != '9')
					break;
				else 
					j--;
			}
			result.insert(0, to_string(diff + 10));
		}
	}
	
	return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string mul10(string num, int n)
{
	for(int i = 0; i < n; i++)
		num += "0";

	return num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
}

string karatsuba(string num1, string num2)
{
	int n = makeEqualLength(num1, num2);
	
	cout << n << " " << num1 << " " << num2 << endl;
	
	if(n == 1)
        return to_string((num1[0] - '0') * (num2[0] - '0'));
	
	int fh = n / 2;
	int sh = n - fh;
	
	string a = num1.substr(0, fh);
	string b = num1.substr(fh, sh);
	
	string c = num2.substr(0, fh);
	string d = num2.substr(fh, sh);
	
	string ac = karatsuba(a, c);
	
	string bd = karatsuba(b, d);

	string a_plus_b = add(a, b);
	string c_plus_d = add(c, d);
	
	string ad_plus_bc = subtract(karatsuba(a_plus_b, c_plus_d), add(ac, bd));

	
	int m = n - n / 2; 
	
	string ac_mul_10_n = mul10(ac, 2 * m);
	string ad_plus_bc_mul_10_n_by_2 = mul10(ad_plus_bc, m);
	
	
	string result = add(add(ac_mul_10_n, ad_plus_bc_mul_10_n_by_2), bd);
	
	return result;	
}

int main()
{
	string s1, s2;
    cin >> s1 >> s2;
    cout << karatsuba(s1,s2) << endl;
    return 0;
}

