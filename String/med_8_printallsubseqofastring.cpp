// CPP program for the above approach
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Find all subsequences
unordered_set<string> s;
unordered_set<string> printSubsequence(string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (input.empty()) {
		s.insert(output);
		return s;
	}

	// output is passed with including
	// the Ist characther of
	// Input string
	unordered_set<string> ans1=printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	unordered_set<string> ans2=printSubsequence(input.substr(1), output);

	for(auto it=ans2.begin();it!=ans2.end();it++){
		ans1.insert(*it);
	}
	return ans1;
}

// Driver code
int main()
{
	// output is set to null before passing in as a
	// parameter
	string output = "";
	string input = "aaa";

	unordered_set<string> ans=printSubsequence(input, output);
	for(auto it=ans.begin();it!=ans.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
