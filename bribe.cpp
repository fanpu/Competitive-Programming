#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> al;
int main(){
	int n; cin >> n; int a[n+1];
	al.assign(n+1,vi());
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	int b,c,e; cin >> e;
	while(e--){
		scanf("%d %d",&b,&c);
		al[b].push_back(c);
		al[c].push_back(b);
	}
	double worth = 0; int label = -1;
	for(int i = 1; i <= n; i++){
		//cout << "worth is " << worth << endl;
		//cout << double((double)al[i].size()/(double)a[i]) << endl;
		if(double((double)al[i].size()/(double)a[i]) > worth){
			worth = double((double)al[i].size()/(double)a[i]);
			label = i;
		}
	}
	cout << label;
}
