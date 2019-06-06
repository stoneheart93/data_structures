#include<unordered_map>
#include<list>
#include<utility>
using namespace std;

class LRUCache
{
	list<int> cache;
	unordered_map<int, pair<int, list<int>::iterator> >hash; 
    int capacity;
    
    public: 
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
}

int LRUCache::get(int key)
{
	if(hash.find(key) != hash.end())
	{
		int value = hash[key].first;
		list<int>::iterator pos_key = hash[key].second;
		
		cache.erase(pos_key);
		cache.push_front(key);
		hash[key] = make_pair(value, cache.begin());
		
		return value;
	}
	else
		return -1;
}

void LRUCache::put(int key, int value)
{
	if(hash.find(key) != hash.end())
	{
		list<int>::iterator pos_key = hash[key].second;
		
		cache.erase(pos_key);
		cache.push_front(key);
		hash[key] = make_pair(value, cache.begin());
	}
	else
	{
		if(hash.size() == capacity)
		{
			hash.erase(cache.back());
			cache.pop_back();
		}
		
		cache.push_front(key);
		hash[key] = make_pair(value, cache.begin());
	}
}

int main()
{
	LRUCache lrucache(2);
	lrucache.put(1, 10);
	lrucache.put(2, 20);
	printf("%d\n", lrucache.get(10));
	lrucache.put(3, 30);
	printf("%d\n", lrucache.get(2));
	lrucache.put(4, 40);
	printf("%d\n", lrucache.get(1));
	printf("%d\n", lrucache.get(3));
	printf("%d\n", lrucache.get(4));
	
	
	return 0;
}
