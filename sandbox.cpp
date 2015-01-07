map<int, int> m;
m[5] = 34; m[33] = 1234;
m.size(); // 2: only contains the elements you added
map<string, int> ms;
ms["hello world"] = 42;
ms["leeroy jenkins"] = 12345;
// iterating through elements
map <int,int>::iterator it;
for (it = tour.begin(); it != tour.end(); ++it){
	cout << it->first << "->" << it->second << "\n";
}
