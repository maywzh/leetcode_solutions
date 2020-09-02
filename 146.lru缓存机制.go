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
	head, tail := &Node{0, 0, nil, nil}, &Node{0, 0, nil, nil}
	head.next = tail
	tail.prev = head
	return LRUCache{
		capacity: capacity,
		hash:     make(map[int]*Node),
		head:     head,
		tail:     tail,
	}
}

func (this *LRUCache) AddNode(node *Node) {
	head := this.head
	node.prev = head
	node.next = head.next
	head.next.prev = node
	head.next = node
	this.hash[node.key] = node
}

//删除节点 排除首节点和尾节点
func (this *LRUCache) Remove(node *Node) {
	if node != nil && node.prev != nil && node.next != nil {
		node.prev.next = node.next
		node.next.prev = node.prev
		node.prev, node.next = nil, nil
		delete(this.hash, node.key)
	}
}

func (this *LRUCache) RemoveOvercachedNode() {
	for this.capacity < len(this.hash) && len(this.hash) > 0 {
		this.Remove(this.tail.prev)
	}
}

func (this *LRUCache) MoveToFront(node *Node) {
	head := this.head
	node.prev.next = node.next
	node.next.prev = node.prev
	node.prev = head
	node.next = head.next
	head.next.prev = node
	head.next = node

}

func (this *LRUCache) Get(key int) int {
	if node, ok := this.hash[key]; ok {
		this.MoveToFront(node)
		return node.value
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.hash[key]; ok {
		node.value = value
		this.MoveToFront(node)
	} else {
		node = &Node{key, value, nil, nil}
		this.AddNode(node)
		this.RemoveOvercachedNode()
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

