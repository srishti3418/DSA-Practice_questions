//Optimized solution
//TC: O(n1+n2+n3)
//SC: O(n1+n2+n3)
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i = 0;
            int j = 0;
            int k = 0;
            vector<int> res;
            while(i < n1 && j < n2 && k < n3)
            {
                if(A[i]==B[j] && B[j]==C[k])
                {
                    res.push_back(A[i]);
                    if(res.size() > 1 && res[res.size()-2] == res[res.size()-1])
                    {
                        res.pop_back();
                    }
                    i++;
                    j++;
                    k++;
                }
                else if(A[i] <= B[j] && A[i] <= C[k])
                {
                    i++;
                }
                else if(B[j] <= A[i] && B[j] <= C[k])
                {
                    j++;
                }
                else if(C[k] <= A[i] && C[k] <= B[j])
                {
                    k++;
                }
            }
            return res;
        }

};
