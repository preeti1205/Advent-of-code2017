/*
--- Day 4: High-Entropy Passphrases ---

A new system policy has been put in place that requires all accounts to use a passphrase instead of simply a password. A passphrase consists of a series of words (lowercase letters) separated by spaces.

To ensure security, a valid passphrase must contain no duplicate words.

For example:

aa bb cc dd ee is valid.
aa bb cc dd aa is not valid - the word aa appears more than once.
aa bb cc dd aaa is valid - aa and aaa count as different words.
The system's full passphrase list is available as your puzzle input. How many passphrases are valid?
*/

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<sstream>
using namespace std;
int main() {
	int result = 0;
	ifstream infile;
	infile.open("inputfile/textfile4.txt");
	string line;
	while(getline(infile, line)){
		unordered_map<string, int> uniqueList;
		bool isdupe = false;
		stringstream ss(line);
		string passphrase;
		while(ss >> passphrase){
			if(uniqueList.find(passphrase) != uniqueList.end()){
				isdupe = true;
				break;
			}
			else {
				uniqueList.insert(make_pair(passphrase, 1));
			}
		}
	if(!isdupe)
		++result;
	}
	cout << result << endl;
	return 0;
}