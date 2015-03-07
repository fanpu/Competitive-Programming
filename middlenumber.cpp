#include <ext/pb_ds/assoc_container.hpp>	// include these headers
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;	// include these namespaces
using namespace __gnu_pbds;
#define mp make_pair
#define ll long long
typedef tree<
  pair<ll,ll>,
  int,
  less<pair<ll,ll> >,
  rb_tree_tag,
  tree_order_statistics_node_update> pbdsSet;
pbdsSet s;

int globalCounter = 0;

int returnMiddleNumber(){
	if(s.size()%2==0){
		return (s.find_by_order(s.size()/2) -> first.first + s.find_by_order(s.size()/2-1) -> first.first) / 2;
	} else return (s.find_by_order(s.size()/2)) ->first.first;
}

int init(int* arr, int length){
	for(int i = 0; i < length; i++){
		s.insert(mp(mp(arr[i], globalCounter),0));
		globalCounter++;
	}
	return returnMiddleNumber();
}

int add_number(int x){
	s.insert(mp(mp(x, globalCounter), 0));
	globalCounter++;
	return returnMiddleNumber();
}

int remove_number(int x){
	s.erase(s.lower_bound(mp(x,0)));
	return returnMiddleNumber();
}

int change_number(int oldx, int newx){
	s.erase(s.lower_bound(mp(oldx,0)));
	s.insert(mp(mp(newx, globalCounter), 0));
	globalCounter++;
	return returnMiddleNumber();
}


