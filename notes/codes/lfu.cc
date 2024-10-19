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