//Most optimized solution
//TC: O(n)
//SC: O(n)
string isSubset(int a1[], int a2[], int n, int m) {
    string flag="Yes";
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(a1[i]);
    }
    for(int i=0;i<m;i++){
        if(s.find(a2[i])==s.end()){
            flag="No";
            return flag;
        }
    }
    return flag;
}
