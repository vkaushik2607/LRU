// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <unordered_map>
#include <sqlite3.h>

using namespace std;
//#include <sqlite3.h>

class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator , int>> ht;
    list<int> keyList;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    void moveToFirst(int key)
    {
        keyList.erase(ht[key].first);
        keyList.push_front(key);
        ht[key].first = keyList.begin();
    }
    int get(int key) {
        //Get will find and move to first, if not found retrun -1;
        if (ht.find(key) == ht.end())
            return -1;
        
        moveToFirst(key);
        return(ht[key].second);
    }
    
    void put(int key, int value) {
        //if found update , else add and move to first and delete the LRU
        if (ht.find(key) != ht.end())
        {
            ht[key].second = value;
            moveToFirst(key);
        }
        else
        {
            //push in the front 
            keyList.push_front(key);
            ht[key] = {keyList.begin(), value};
            cap--;
        }
        
        if(cap <0)
        {
            //delete the last element of the keyList
            ht.erase(keyList.back());
                keyList.pop_back();
            cap++;
        }
    }
};

int main() {
   

     int capacity = 50;
     LRUCache* obj = new LRUCache(capacity);
	 
	 int key = 2;
	 int value =5;
	 obj->put(key,value);
	 
	 obj->put(2,4);
	 obj->put(2,3);
	 obj->put(4,3);
	
	 int param_1 = obj->get(2);
	 
	cout<<param_1;
    return 0;
}