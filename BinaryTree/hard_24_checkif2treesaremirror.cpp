//Optimized solution
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int checkMirrorTree(int N, int e, int *u, int *v)
	{

		unordered_map<int , stack<int> >mp;
    int j=0;
		for (int i = 0 ; i < e ; i++)
		{
		    mp[u[j]].push(u[j+1]);
            j=j+2;
		}
    j=0;
		for (int i = 0 ; i < e ; i++)
		{
			if(mp[v[j]].top() != v[j+1])
				return 0;
			mp[v[j]].pop();
            j=j+2;
		}

		return 1;
	}

int main()
{
	/*int N = 7, e = 6;
	
	//Tree 1
    int u[] = {1, 10, 1, 7, 1, 3, 10, 4, 10, 5, 10, 6};
	//Tree 2
    int v[] = {1, 3, 1, 7, 1, 10, 10, 6, 10, 5, 10, 4};*/
    
        int N = 3;
        int e = 2;
        int u[] = { 1, 2, 1, 3 };
        int v[] = { 1, 3, 1, 2 };

	if(checkMirrorTree(N, e, u, v))
	cout<<"Yes";
	else
	cout<<"No";
    cout<<endl;
	return 0;
}
