#include <bits/stdc++.h>
using namespace std;
int kmp(string &s){
    int n = s.size();
	vector<int> lps(n,0);
	int pref = 0;
	int suff = 1;
	
	while(suff < n){
	    if(s[pref] == s[suff]){
	        lps[suff] = pref+1;
	        pref++;
	        suff++;
	    }else{
	        if(pref == 0){
	            lps[suff] = 0;
	            suff++;
	        }else{
	            pref = lps[pref-1];
	        }
	    }
	}
	return lps[n-1];
}
int main() {
	string s = "ABCABDABCABDABDAB";
	cout << kmp(s) << endl;

}





















