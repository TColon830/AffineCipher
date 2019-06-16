#include <iostream>
#include <algorithm>
#include <vector> 

//TColon 
//Short program to find the smallest a and N values such that
//the affine cipher ax + b (mod N) requires only 8 steps 

using namespace std;

bool isGcdEqualToOne (int a, int b)
{
	if (__gcd(a,b) == 1)
		return true;
	else
		return false; 
}

int main ()
{
	
	bool endWhile = false; 
	vector <int> sols;
	int tempValue; 
	
	for (int a = 1; a < 100; a++){
		
		for (int N = 1; N < 100; N++){
	 
			if (isGcdEqualToOne(a,N) && N > a){
				sols.clear(); 
				sols.push_back(a);
				sols.push_back(N);
				
				while (endWhile == false){
					
					sort(sols.begin(), sols.end());
					tempValue = sols[1] % sols[0];
					
					if (tempValue > 0)
						sols.push_back(tempValue);
					
					else if (tempValue == 0)
						endWhile = true; 
					
					sort(sols.begin(), sols.end());
					if (sols[0] == 1)
						endWhile = true; 
				}//end while
				
				sols.pop_back();
				if (sols.size() == 8){
					cout << "a: " << a << " N: " << N << endl;
				
					for (int i = 0; i < sols.size(); i++)
						cout << sols[i] << " ";
					cout << endl; 
				}//end if condition to check the size of the array 
			
				endWhile = false; 
			}//end if GCD = 1	
			
			else
				{}

		}//end inner-for-loop
	}//end outter-for-loop
} 
