## 框架

### 滑动窗口

最小覆盖子串、字符串排列、找所有字母异位词、最长无重复子串 ¬

```c++
// 滑动窗口算法伪码框架
void slidingWindow(string s) {
    // 用合适的数据结构记录窗口中的数据，根据具体场景变通
    // 比如说，我想记录窗口中元素出现的次数，就用 map
    // 如果我想记录窗口中的元素和，就可以只用一个 int
    auto window = ...

    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        window.add(c);
        // 增大窗口
        right++;

        // 进行窗口内数据的一系列更新
        ...

        // *** debug 输出的位置 ***
        printf("window: [%d, %d)\n", left, right);
        // 注意在最终的解法代码中不要 print
        // 因为 IO 操作很耗时，可能导致超时

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            window.remove(d);
            // 缩小窗口
            left++;

            // 进行窗口内数据的一系列更新
            ...
        }
    }
}

```

```c++
// 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        // 记录window中的字符满足need条件的字符个数
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 扩大窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {

                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 是将移出窗口的字符
                char d = s[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }

        }
        // 返回最小覆盖子串
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

```

### 二分搜索

```c++
// 核心框架
// 函数 f 是关于自变量 x 的单调函数
int f(int x) {
    // ...
}

// 主函数，在 f(x) == target 的约束下求 x 的最值
int solution(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    // 问自己：自变量 x 的最小值是多少？
    int left = ...;
    // 问自己：自变量 x 的最大值是多少？
    int right = ... + 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (f(mid) == target) {
            // 问自己：题目是求左边界还是右边界？
            // ...
        } else if (f(mid) < target) {
            // 问自己：怎么让 f(x) 大一点？
            // ...
        } else if (f(mid) > target) {
            // 问自己：怎么让 f(x) 小一点？
            // ...
        }
    }
    return left;
}

```

```c++
int binary_search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}

int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 判断 target 是否存在于 nums 中
    if (left < 0 || left >= nums.size()) {
        return -1;
    }
    // 判断一下 nums[left] 是不是 target
    return nums[left] == target ? left : -1;
}

int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 由于 while 的结束条件是 right == left - 1，且现在在求右边界
    // 所以用 right 替代 left - 1 更好记
    if (right < 0 || right >= nums.size()) {
        return -1;
    }
    return nums[right] == target ? right : -1;
}
```

### BFS

```c++
int BFS(Node start, Node target) {
    queue<Node> q;
    set<Node> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node cur = q.front();
            q.pop();
            if (cur == target)
                return step;
            for (Node x : cur.adj()) {
                if (visited.count(x) == 0) {
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
    }
    // 如果走到这里，说明在图中没有找到目标节点
}
```

### Backtrace

```c++
//全排列
class Solution {
private:
    vector<vector<int>> res;
public:
    // 主函数，输入一组不重复的数字，返回它们的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        // 记录「路径」
        vector<int> track;
        // 「路径」中的元素会被标记为true，避免重复使用
        vector<bool> used(nums.size(), false);

        backtrack(nums, track, used);
        return res;
    }

    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used) {
        // 触发结束条件
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 排除不合法的选择
            if (used[i]) {
                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 进入下一层决策树
            backtrack(nums, track, used);
            // 取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};
```

```c++
// n皇后
class Solution {
private:
    vector<vector<string>> res;

public:
    // 输入棋盘边长 n，返回所有合法的放置
    vector<vector<string>> solveNQueens(int n) {
        // 每个字符串代表一行，字符串列表代表一个棋盘
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后
    // 选择列表：第 row 行的所有列都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string>& board, int row) {
        // 触发结束条件
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            // 排除不合法选择
            if (!isValid(board, row, col)) {
                continue;
            }
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    // 是否可以在 board[row][col] 放置皇后？
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i <= row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
```

### 单调队列

```c++
#include <deque>
#include <cassert>
using namespace std;

template <typename E>
class MonotonicQueue {
private:
    deque<E> q;    // 标准队列，存储所有元素
    deque<E> maxq; // 元素降序排列的队列，头部是最大值
    deque<E> minq; // 元素升序排列的队列，头部是最小值

public:
    // 插入元素
    void push(const E& elem) {
        // 维护常规队列
        q.push_back(elem);

        // 维护 maxq：删除所有小于当前元素的元素
        while (!maxq.empty() && maxq.back() < elem) {
            maxq.pop_back();
        }
        maxq.push_back(elem);

        // 维护 minq：删除所有大于当前元素的元素
        while (!minq.empty() && minq.back() > elem) {
            minq.pop_back();
        }
        minq.push_back(elem);
    }

    // 获取最大值
    E max() const {
        assert(!maxq.empty());
        return maxq.front();
    }

    // 获取最小值
    E min() const {
        assert(!minq.empty());
        return minq.front();
    }

    // 弹出队列中的第一个元素
    E pop() {
        assert(!q.empty());
        E deleteVal = q.front();
        q.pop_front();

        // 如果被删除的元素是 maxq 和 minq 的头部，则同步删除
        if (!maxq.empty() && deleteVal == maxq.front()) {
            maxq.pop_front();
        }
        if (!minq.empty() && deleteVal == minq.front()) {
            minq.pop_front();
        }

        return deleteVal;
    }

    // 获取队列大小
    int size() const {
        return q.size();
    }

    // 检查队列是否为空
    bool isEmpty() const {
        return q.empty();
    }
};

```

### 单调栈

```c++
// 739. 每日温度
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] res = new int[n];
        // 这里放元素索引，而不是元素
        Stack<Integer> s = new Stack<>();
        // 单调栈模板
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && temperatures[s.peek()] <= temperatures[i]) {
                s.pop();
            }
            // 得到索引间距
            res[i] = s.isEmpty() ? 0 : (s.peek() - i);
            // 将索引入栈，而不是元素
            s.push(i);
        }
        return res;
    }
}
```

```c++
#include <stack>
#include <functional>
#include <cassert>
using namespace std;

template <typename E>
class MonotonicStack {
private:
    stack<E> stk;  // 标准栈
    function<bool(E, E)> cmp;  // 比较函数，用于决定单调性

public:
    // 构造函数，传入比较函数以决定单调性
    // 比如 std::less 表示递增栈，std::greater 表示递减栈
    MonotonicStack(function<bool(E, E)> cmpFunc) : cmp(cmpFunc) {}

    // 插入元素
    void push(const E& elem) {
        // 保证栈的单调性，根据 cmp 函数来决定是否弹出栈顶元素
        while (!stk.empty() && cmp(stk.top(), elem)) {
            stk.pop();
        }
        stk.push(elem);
    }

    // 获取栈顶元素
    E top() const {
        assert(!stk.empty());
        return stk.top();
    }

    // 弹出栈顶元素
    void pop() {
        assert(!stk.empty());
        stk.pop();
    }

    // 检查栈是否为空
    bool isEmpty() const {
        return stk.empty();
    }

    // 获取栈的大小
    int size() const {
        return stk.size();
    }
};

int main() {
    // 递减栈：栈内元素递减
    MonotonicStack<int> decStack(greater<int>());

    decStack.push(5);
    decStack.push(3);
    decStack.push(8);
    decStack.push(6);

    // 输出栈顶元素（应该是 8，因为 6 被弹出以保持递减顺序）
    cout << "Top of decStack: " << decStack.top() << endl; // 输出 8

    decStack.pop();  // 弹出 8
    cout << "Top after pop: " << decStack.top() << endl; // 输出 5

    // 递增栈：栈内元素递增
    MonotonicStack<int> incStack(less<int>());

    incStack.push(5);
    incStack.push(3);
    incStack.push(8);
    incStack.push(6);

    // 输出栈顶元素（应该是 6，因为 8 被弹出以保持递增顺序）
    cout << "Top of incStack: " << incStack.top() << endl; // 输出 6

    return 0;
}

```

## 经典算法

### LRU

```c++
// 双向链表节点
class Node {
public:
    int key, val;
    Node* next, *prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

// 双向链表
class DoubleList {
private:
    // 头尾虚节点
    Node* head;
    Node* tail;
    // 链表元素数
    int size;

public:
    DoubleList() {
        // 初始化双向链表的数据
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // 在链表尾部添加节点 x，时间 O(1)
    void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    // 删除链表中的 x 节点（x 一定存在）
    // 由于是双链表且给的是目标 Node 节点，时间 O(1)
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    // 删除链表中第一个节点，并返回该节点，时间 O(1)
    Node* removeFirst() {
        if (head->next == tail)
            return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }

    // 返回链表长度，时间 O(1)
    int getSize() { return size; }
};

class LRUCache {
private:
    // key -> Node(key, val)
    unordered_map<int, Node*> map;
    // Node(k1, v1) <-> Node(k2, v2)...
    DoubleList cache;
    // 最大容量
    int cap;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        // 将该数据提升为最近使用的
        makeRecently(key);
        return map[key]->val;
    }

    void put(int key, int val) {
        if (map.count(key)) {
            // 删除旧的数据
            deleteKey(key);
            // 新插入的数据为最近使用的数据
            addRecently(key, val);
            return;
        }

        if (cap == cache.getSize()) {
            // 删除最久未使用的元素
            removeLeastRecently();
        }
        // 添加为最近使用的元素
        addRecently(key, val);
    }

    void makeRecently(int key) {
        Node* x = map[key];
        // 先从链表中删除这个节点
        cache.remove(x);
        // 重新插到队尾
        cache.addLast(x);
    }

    void addRecently(int key, int val) {
        Node* x = new Node(key, val);
        // 链表尾部就是最近使用的元素
        cache.addLast(x);
        // 别忘了在 map 中添加 key 的映射
        map[key] = x;
    }

    void deleteKey(int key) {
        Node* x = map[key];
        // 从链表中删除
        cache.remove(x);
        // 从 map 中删除
        map.erase(key);
    }

    void removeLeastRecently() {
        // 链表头部的第一个元素就是最久未使用的
        Node* deletedNode = cache.removeFirst();
        // 同时别忘了从 map 中删除它的 key
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }
};
```

### LFU

```c++
class LFUCache {
    // key 到 val 的映射，我们后文称为 KV 表
    std::unordered_map<int, int> keyToVal;
    // key 到 freq 的映射，我们后文称为 KF 表
    std::unordered_map<int, int> keyToFreq;
    // freq 到 key 列表的映射，我们后文称为 FK 表
    std::unordered_map<int, std::list<int>> freqToKeys;
    // 记录最小的频次
    int minFreq;
    // 记录 LFU 缓存的最大容量
    int cap;

public:
    LFUCache(int capacity) {
        this->cap = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) {
            return -1;
        }
        // 增加 key 对应的 freq
        increaseFreq(key);
        return keyToVal[key];
    }

    void put(int key, int val) {
        if (this->cap <= 0)
            return;

        // 若 key 已存在，修改对应的 val 即可
        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = val;
            // key 对应的 freq 加一
            increaseFreq(key);
            return;
        }

        // key 不存在，需要插入
        // 容量已满的话需要淘汰一个 freq 最小的 key
        if (keyToVal.size() >= this->cap) {
            removeMinFreqKey();
        }

        // 插入 key 和 val，对应的 freq 为 1
        // 插入 KV 表
        keyToVal[key] = val;
        // 插入 KF 表
        keyToFreq[key] = 1;
        // 插入 FK 表
        freqToKeys[1].push_back(key);
        // 插入新 key 后最小的 freq 肯定是 1
        this->minFreq = 1;
    }

private:
    void removeMinFreqKey() {
        // freq 最小的 key 列表
        auto &keyList = freqToKeys[this->minFreq];
        // 其中最先被插入的那个 key 就是该被淘汰的 key
        int deletedKey = keyList.front();
        keyList.pop_front();
        if (keyList.empty()) {
            freqToKeys.erase(this->minFreq);
            // 如果 freqToKeys[minFreq] 为空，需要更新 minFreq
        }
        // 删除 KV 表中的该 key
        keyToVal.erase(deletedKey);
        // 删除 KF 表中的该 key
        keyToFreq.erase(deletedKey);
    }

    void increaseFreq(int key) {
        int freq = keyToFreq[key];
        // 更新 KF 表
        keyToFreq[key] = freq + 1;
        // 更新 FK 表
        // 将 key 从 freq 对应的列表中删除
        auto &oldList = freqToKeys[freq];
        oldList.remove(key);
        // 将 key 加入 freq + 1 对应的列表中
        freqToKeys[freq + 1].push_back(key);
        // 如果 freq 对应的列表空了，移除这个 freq
        if (oldList.empty()) {
            freqToKeys.erase(freq);
            // 如果这个 freq 恰好是 minFreq，更新 minFreq
            if (freq == this->minFreq) {
                this->minFreq++;
            }
        }
    }
};
```

### 拓扑排序

```c++
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 拓扑排序函数
vector<int> topologicalSort(int numCourses, const vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);  // 记录每个节点的入度
    vector<vector<int>> adjList(numCourses);  // 邻接表表示图
    vector<int> topoOrder;  // 存储拓扑排序的结果

    // 构建图并计算入度
    for (const auto& pre : prerequisites) {
        int course = pre[0];
        int prereq = pre[1];
        adjList[prereq].push_back(course);  // prereq -> course
        inDegree[course]++;  // course 的入度加一
    }

    // 使用队列存储所有入度为0的节点
    queue<int> zeroDegreeNodes;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            zeroDegreeNodes.push(i);  // 入度为0的节点可以作为拓扑排序的起点
        }
    }

    // 处理所有入度为0的节点
    while (!zeroDegreeNodes.empty()) {
        int node = zeroDegreeNodes.front();
        zeroDegreeNodes.pop();
        topoOrder.push_back(node);  // 将当前节点加入拓扑排序结果

        // 遍历该节点的邻接节点
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;  // 邻接节点的入度减一
            if (inDegree[neighbor] == 0) {
                zeroDegreeNodes.push(neighbor);  // 如果入度变为0，则将该节点加入队列
            }
        }
    }

    // 如果拓扑排序包含的节点数等于图中所有节点数，说明图是有向无环图
    if (topoOrder.size() == numCourses) {
        return topoOrder;
    } else {
        return {};  // 图中有环，无法进行拓扑排序
    }
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> result = topologicalSort(numCourses, prerequisites);

    if (result.empty()) {
        cout << "图中存在环，无法进行拓扑排序" << endl;
    } else {
        cout << "拓扑排序结果: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## 排序算法

### 堆排序

```c++
#include <iostream>
#include <vector>
using namespace std;

// 堆调整函数
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  // 递归调整子堆
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐一将堆顶元素移到数组末尾，然后调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

```

### 希尔排序

```c++
#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    shellSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

```

### 桶排序

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    // 把数组元素分配到不同的桶中
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // 对每个桶进行排序
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 合并所有桶中的元素
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);
    for (float num : arr) {
        cout << num << " ";
    }
    return 0;
}

```

### 快速排序

```c++
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

```

### 归并排序

```c++
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

```

### 总结：

堆排序时间复杂度为 O(n log n)。
希尔排序的时间复杂度与步长序列相关，通常介于 O(n log n) 和 O(n^2) 之间。
桶排序的时间复杂度在最优情况下为 O(n)，但依赖于输入数据的分布。
快速排序的平均时间复杂度为 O(n log n)，但在最坏情况下为 O(n^2)。
归并排序的时间复杂度稳定为 O(n log n)，但需要 O(n) 的额外空间。
