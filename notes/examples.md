## JSON Validator

```c++
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class JsonValidator {
public:
    bool isValidJson(const string &json) {
        int index = 0;
        bool valid = parseValue(json, index);
        return valid && index == json.size();
    }
    void trimEnd(string &str) { str.erase(str.find_last_not_of(" \t\n\r") + 1); }

    void trimStart(string &str) { str.erase(str.find_first_not_of(" \t\n\r")); }

private:
    bool parseValue(const string &json, int &index) {
        skipWhitespace(json, index);
        if (index >= json.size())
            return false;

        char ch = json[index];
        if (ch == '{') {
            return parseObject(json, index);
        } else if (ch == '[') {
            return parseArray(json, index);
        } else if (ch == '\"') {
            return parseString(json, index);
        } else if (isdigit(ch) || ch == '-') {
            return parseNumber(json, index);
        } else if (json.substr(index, 4) == "true") {
            index += 4;
            return true;
        } else if (json.substr(index, 5) == "false") {
            index += 5;
            return true;
        } else if (json.substr(index, 4) == "null") {
            index += 4;
            return true;
        }

        return false;
    }
    bool parseObject(const string &json, int &index) {
        index++;
        skipWhitespace(json, index);
        if (index < json.size() && json[index] == '}') {
            index++;
            return true;
        }

        while (index < json.size()) {
            if (!parseString(json, index))
                return false;
            skipWhitespace(json, index);
            if (index >= json.size() || json[index] != ':')
                return false;
            index++;
            if (!parseValue(json, index))
                return false;
            skipWhitespace(json, index);
            if (index < json.size() && json[index] == '}') {
                index++;
                return true;
            } else if (index >= json.size() || json[index] != ',') {
                return false;
            }
            index++;
        }
        return false;
    }

    bool parseArray(const string &json, int &index) {
        index++;
        skipWhitespace(json, index);
        if (index < json.size() && json[index] == ']') {
            index++;
            return true;
        }

        while (index < json.size()) {
            if (!parseValue(json, index))
                return false;
            skipWhitespace(json, index);
            if (index < json.size() && json[index] == ']') {
                index++;
                return true;
            } else if (index >= json.size() || json[index] != ',') {
                return false;
            }
            index++;
        }
        return false;
    }
    bool parseString(const string &json, int &index) {
        index++;
        while (index < json.size()) {
            char ch = json[index];
            if (ch == '\"') {
                index++;
                return true;
            } else if (ch == '\\') {
                index += 2;
            } else {
                index++;
            }
        }
        return false;
    }
    bool parseNumber(const string &json, int &index) {
        if (json[index] == '-')
            index++;
        if (index >= json.size() || !isdigit(json[index]))
            return false;

        while (index < json.size() && isdigit(json[index])) {
            index++;
        }
        if (index < json.size() && json[index] == '.') {
            index++;
            if (index >= json.size() || !isdigit(json[index]))
                return false;
            while (index < json.size() && isdigit(json[index])) {
                index++;
            }
        }
        if (index < json.size() && (json[index] == 'e' || json[index] == 'E')) {
            index++;
            if (index < json.size() && (json[index] == '+' || json[index] == '-')) {
                index++;
            }
            if (index >= json.size() || !isdigit(json[index]))
                return false;
            while (index < json.size() && isdigit(json[index])) {
                index++;
            }
        }

        return true;
    }

    void skipWhitespace(const string &json, int &index) {
        while (index < json.size() && isspace(json[index])) {
            index++;
        }
    }
};

int main() {
    JsonValidator validator;
    string testJson;
    ifstream inputFile("input.json");
    if (!inputFile.is_open()) {
        cerr << "无法打开文件!" << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        testJson += line + '\n';
    }
    inputFile.close();
    validator.trimEnd(testJson);
    cout << "读取到的 JSON 字符串为：" << endl << testJson << endl;
    if (validator.isValidJson(testJson)) {
        cout << "JSON 字符串合法!" << endl;
    } else {
        cout << "JSON 字符串不合法!" << endl;
    }
    return 0;
}

```

## 省份数量

```c++
int findCircleNum(vector<vector<int>> &isConnected) {
    unordered_set<int> visited;
    int n = isConnected.size();
    int count = 0;
    function<void(int)> dfs = [&](int i) {
        visited.insert(i);
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !visited.count(j)) {
                dfs(j);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            count++;
            dfs(i);
        }
    }
    return count;
}
```

## 跳跃游戏

```c++
bool canJump(vector<int> &nums) {
    int maxReach = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > maxReach) {
            return false;
        }
        maxReach = maxReach < i + nums[i] ? i + nums[i] : maxReach;
        if (maxReach >= n - 1)
            return true;
    }
    return false;
}
```
