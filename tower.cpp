#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,q; cin >> n >> q;
	int width[n];
	for(int i = 0; i < n; i++){
		cin >> width[i];
	}
	sort(width,width+n);
	
	int cmult=1;
	for(int i=1;i<numboats;i++){
		 cmult=(cmult*(i+1-(lower_bound(widths,widths+i,widths[i]-jump)-widths)))%1000000007;
	}
	// your code goes here
	return 0;
}
