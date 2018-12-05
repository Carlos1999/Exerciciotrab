#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using std::set;

using std::cout;

class Primo{
public:
	Primo(){};
	~Primo(){};

	bool operator() (int n) const{
		int max = sqrt(n);
		for (int i=2; i<=max; i++){
			if(n%i == 0){
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char const* argv[]){

	Primo p;

	set<int> num;

	int ab = atoi(argv[1]);

	for(int i=1; i<=ab; i++){
		num.insert(i);
	}
	std::cout << "Numeros primos [1-" << ab << "]: ";
	auto it = num.begin();
	do{
		it = find_if(it, num.end(), p);
		if(it == num.end()){
			break;
		}
		cout << *it << " ";
		it++;
	}while(1);

	return 0;
}