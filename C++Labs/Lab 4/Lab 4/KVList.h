template<typename K, typename V, int n>
class KVList{
	K Keys[n];
	V Values[n];
	size_t count;
public:
	KVList() : count(0){};
	size_t size() const{ 
		return count; 
	}
	const K& key(int i) const {
		return Keys[i];
	}
	const V& value(int i) const{
		return Values[i];
	}
	KVList& add(const K& k, const V& v){
		if (count < n){
			Keys[count] = k;
			Values[count++] = v;
		}
		return *this;
	}
	int find(const K& k) const{
		int i;
		int position = 0;
		bool found = false;
		for (i = 0; i < count && !found; i++){
			if (Keys[i] == k){
				position = i;
				found = true;
			}
		}
		return position;
	}
	KVList& replace(int i, const K& k, const V& v){
		if (i < n){
			Keys[i] = k;
			Values[i] = v;
		}
		return *this;
	}
};