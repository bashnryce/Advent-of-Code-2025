/* Psuedo Code

 given a range of numbers 
example: 11-22, 95-115, etc.
find all numbers that have a pattern that is repeated at least twice
example: 555555 646464 123123
add all of these numbers that match the pattern together

start
	get first range
	for i in that range
		i int to string
		get length of the string
		loop from 2 to length  
			if length % i == 0 (if it divides evenly in i parts)
				factors[] = i  
		end loop
		for each factor[j]
			for 1 to factor[j] (for each chunk of a potential pattern)
				chunk[k] = string.substr((length/factor)*(k-1),(length/factor)*k);
			for 1 to chunk[k]
				if(chunk[0] == chunk[x])
					equal_flag = 1;
				else	
					equal_flag = 0;
					break (exits this loop)
			if(equal_flag == 1)
				break factor loop
		end loop
		if(equal_flag == 1)
			total += i;
	end loop
end

*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

string rangeStr;
string rangeStartStr;
string rangeEndStr;

ifstream File("puzzleInput2.txt");

long rangeStart;
long rangeEnd;

string currentNum;
string firstHalf;
string secondHalf;

int NumDigits;

long total = 0;

while(getline(File, rangeStr, ',')) {
	
	rangeStartStr = rangeStr.substr(0, rangeStr.find('-'));
	rangeEndStr = rangeStr.substr(rangeStr.find('-')+1);
	
	//cout << "Start: " << rangeStartStr << endl;
	//cout << "End: " << rangeEndStr << endl << endl;
	
	rangeStart = stol(rangeStartStr);
	rangeEnd = stol(rangeEndStr);
	
	
	for(long i = rangeStart; i <= rangeEnd; i++) { //loop through the values of the current range
		
		//cout << "I: " << i << endl;
		currentNum = to_string(i);
		NumDigits = currentNum.length();
		//cout << NumDigits << endl;
		
		vector<int> factors(NumDigits);
		int factor_index = 0;
		
		//loop to get all factors of number of digits (all ways the number can be divided into equal chunks)
		for(int j = 2; j <= NumDigits; j++) { 	//possible factors loop start at 2 because we need minimum of 2 repetitions of the pattern
			if(NumDigits%j == 0) {				//if j is a factor
				factors[factor_index] = j;	//add factor to vector
				factor_index++;				
			}			
		}
		
		int equal_flag = 0;

		for(int k = 0; k <= factor_index; k++) { //for each factor
		
			vector<string> chunk(factors[k]);    //vector to hold divided up chunks of the current number
			
			for(int x = 0; x < factors[k]; x++) { //create and check each chuck for the current num and factor
					
				chunk[x] = currentNum.substr((NumDigits/factors[k])*(x),(NumDigits/factors[k])); //gets chunk based off size of chunk and chunk position
				
				//debug prints
				//cout << "CurrentNum (I): " << i << endl;
				//cout << "factor: " << factors[k] << endl;
				//cout << "start Index: " << (NumDigits/factors[k])*(x) << endl;
				//cout << "length Index: " << (NumDigits/factors[k]) << endl;
				//cout << "X: " << x << endl;
				//cout << "chunk[x]:" << chunk[x] << endl << endl;
				
				if(x != 0) { //start checking chunks after first one is created
					if(chunk[0] == chunk[x]) {
						equal_flag = 1;
					}
					else {	//if they're not equal no need to continue checking this factor
						equal_flag = 0;
						break;
					}
				}	
			}
			if(equal_flag == 1) { //if one factor worked and a pattern in found we can stop checking other factors
				break;
			}
			
		}

		if(equal_flag == 1){
			total += i;
			cout << "match: " << i << "     <--------------------------" << endl << endl;
		}		
	}
}

cout << "Total: " << total << "     <---------------------------------------" << endl;

File.close();
return 0;

}