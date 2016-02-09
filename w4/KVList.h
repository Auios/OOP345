//KVList.h
template <class K, class V, int N>
class KVList
{
private:
	//K k[N];
	//V v[N];
	struct
	{
		K k;
		V v;
	} data[N];
	size_t count;
public:
	KVList() : count(0) {}
	size_t size() const
	{
		return count;
	}

	const K& key(int i) const
	{
		//return k[i];
		return data[i].k;
	}

	const V& value(int i) const
	{
		//return v[i];
		return data[i].v
	
	}
	KVList& add(const K& kk, const V& vv)
	{
		if (count < N)
		{
			//k[count] = kk, v[count] = vv;
			data[count].k = k, data[count.v = vv; ]
			count++;
		}
		return *this;
	}

	int find(const K& kk) const
	{
		//Returns the index of the first element in the list with a key equal to k - defaults to 0
		for (int i = 0; i < count; i++)
		{
			//if (kk == k[i]) return i;
			if (kk == data[i].k) return i;
		}
		return 0;
	}

	KVList& replace(int i, const K& kk, const V& vv)
	{
		//Replaces element i in the list with the key and value received and returns a reference to the current object
		if (i >= 0 && i < count)
		{
			//k[i] = kk, v[i] = vv;
			data[i].k = kk, data[i].v = vv;
		}
		return *this;
	}
};