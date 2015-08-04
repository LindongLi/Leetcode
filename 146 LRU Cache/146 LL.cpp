#include <iostream>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/lru-cache/

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache
{
private:
	struct lrulink
	{
		int key, value;
		struct lrulink *prev, *next;
		lrulink(int k, int v) : key(k), value(v) {}
	};
	lrulink *phead;
	unordered_map<int, lrulink*> seek;
	void lift(lrulink *node)
	{
		if (node == phead) return;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = phead;
		node->prev = phead->prev;
		phead->prev->next = node;
		phead->prev = node;
		phead = node;
	}
public:
	LRUCache(int capacity)
	{
		phead = new lrulink(-1, -1);
		phead->prev = phead;
		phead->next = phead;
		lrulink *node;
		while (--capacity > 0)
		{
			node = new lrulink(-1, -1);
			node->next = phead;
			node->prev = phead->prev;
			phead->prev->next = node;
			phead->prev = node;
		}
	}
	int get(int key)
	{
		if (seek.find(key) != seek.end())
		{
			lrulink *node = seek[key];
			lift(node);
			return node->value;
		}
		return -1;
	}
	void set(int key, int value)
	{
		if (seek.find(key) != seek.end())
		{
			lrulink *node = seek[key];
			lift(node);
			node->value = value;
		}
		else
		{
			phead = phead->prev;
			unordered_map<int, lrulink*>::iterator it;
			if ((it = seek.find(phead->key)) != seek.end())
			{
				seek.erase(it);
			}
			seek[key] = phead;
			phead->key = key;
			phead->value = value;
		}
	}
};

/*
idea: double direction link, using hash to find
complexity: Time O(N)
*/

int main(void)
{
	LRUCache engine(2);
	engine.set(2, 6);
	engine.set(1, 5);
	engine.set(1, 2);
	cout << engine.get(2) << '\n';
	return 0;
}