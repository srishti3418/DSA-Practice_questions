#include <iostream>
#include <cmath>
#include <unordered_map>
#include <utility>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;

		Node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
};

//First approach 
//TC: O(n)
//SC: O(n)
int calculate_maxsum(Node *root, unordered_map<Node *, int> &m);

int calc_grandchildren(Node *root, unordered_map<Node *, int> &m){
	
	int sum=0;

	if(root->left)
		sum += calculate_maxsum(root->left->left, m) + calculate_maxsum(root->left->right, m);
	
	if(root->right)
		sum += calculate_maxsum(root->right->left, m) + calculate_maxsum(root->right->right, m);

	return sum;
	
}

int calculate_maxsum(Node *root, unordered_map<Node *, int> &m){
	if(root==NULL)
		return 0;

	if(m.find(root)!=m.end())
		return m[root];

	int incl = root->data + calc_grandchildren(root, m);
	int excl = calculate_maxsum(root->left, m) + calculate_maxsum(root->right, m);

	m[root] = max(incl, excl);

	return m[root];
}

int maxsum(Node *root){
	if(root==NULL)
		return 0;
	unordered_map<Node *, int> mp;
	return calculate_maxsum(root, mp);
}

//Pair approach
//TC: O(n)
//SC: O(n) {because of recursion}
pair<int, int> pair_sum(Node *root){
	if(root==NULL){
		pair<int, int> sum(0,0); 
		return sum;
	}

	pair<int, int> sum1 = pair_sum(root->left);
	pair<int, int> sum2 = pair_sum(root->right);
	pair<int, int> sum;

	sum.first = root->data + sum1.second + sum2.second;
	sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);

	return sum;
}

int maxsum2(Node *root){
	if(root==NULL)
		return 0;
	pair<int, int> ans = pair_sum(root);
	return max(ans.first, ans.second);
}

int main(){
	Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);

	cout<<maxsum(root)<<endl;
	cout<<maxsum2(root)<<endl;
}
