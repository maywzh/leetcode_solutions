/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU缓存机制
 */

// @lc code=start
type LRUCache struct {
	capacity   int
	hash       map[int]*Node
	head, tail *Node
}
type Node struct {
	key, value int
	prev, next *Node
}

func Constructor(capacity int) LRUCache {
	cache := LRUCache{
		hash:     make(map[int]*Node),
		head:     &Node{0, 0, nil, nil},
		tail:     &Node{0, 0, nil, nil},
		capacity: capacity,
	}
	cache.head.next = cache.tail
	cache.tail.prev = cache.head
	return cache
}

func (this *LRUCache) AddNode(node *Node) {
	

}

func (this *LRUCache) Get(key int) int {
	if elem, ok := hash[key]; ok {
		if head.next != elem {
			elem.prev.next = elem.next
			elem.next.prev = elem.prev
			elem.prev = head
			elem.next = head.next
			head.next = elem
		}
		ret := m[key].value
		return ret
	} else {
		return -1
	}
}

func (this *LRUCache) RemoveOldestNode() {
	for this.capacity < len(hash) {
		oldest := tail.prev
		delete(hash, oldest.key)
		tail.prev = oldest.prev
		oldest.prev.next = tail
	}
}

func (this *LRUCache) Put(key int, value int) {
	if elem, ok := hash[key]; ok {
		elem.value = value
	} else {
		elem = &Node{key, value, nil, nil}

	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

