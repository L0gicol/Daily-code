# 【LeetCode】155. 最小栈 (Min Stack) 解题笔记

## 1. 题目描述
设计一个支持 `push` ，`pop` ，`top` 操作，并能在常数时间 $O(1)$ 内检索到最小元素的栈。

## 2. 核心难点
普通栈的 `push` 和 `pop` 都能轻松满足 $O(1)$，但获取最小值 `getMin` 通常需要遍历整个栈 ($O(N)$)。为了实现 $O(1)$ 的 `getMin`，我们需要一种机制来记录“历史上的最小值”。

## 3. 解题思路：辅助栈 (Auxiliary Stack)
我们使用两个栈来协作：
1.  **数据栈 (`s_data`)**：负责存储所有插入的元素，维护正常的栈逻辑。
2.  **辅助栈 (`s_min`)**：负责存储**当前的最小值**。

### 关键逻辑
这两个栈的数据需要保持“逻辑同步”：
* **入栈 (`push`)**：
    * 数据栈：无条件压入新元素。
    * 辅助栈：只有当 **新元素 $\le$ 辅助栈栈顶** (即新元素更小或相等) 时，才压入辅助栈。
    * *注意：这里必须包含相等的情况，防止重复的最小值被误删。*
* **出栈 (`pop`)**：
    * 数据栈：无条件弹出。
    * 辅助栈：只有当 **数据栈弹出的元素 == 辅助栈栈顶** 时，说明这个最小值失效了，辅助栈才同步弹出。
* **获取最小值 (`getMin`)**：
    * 直接返回辅助栈的栈顶元素。

## 4. 代码实现 (C++)

```cpp
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> s_data; // 数据栈
    stack<int> s_min;  // 最小栈（辅助栈）

public:
    MinStack() {}
    
    void push(int val) {
        // 1. 如果辅助栈为空，或者新来的值更小（或相等），则压入辅助栈
        // 注意：这里必须是 <=，如果遇到相同的最小值，也需要压入一份备份
        if (s_min.empty() || val <= s_min.top()) {
            s_min.push(val);
        }
        // 2. 数据栈正常压入
        s_data.push(val);
    }
    
    void pop() {
        // 只有当弹出的元素就是当前的最小值时，辅助栈才同步弹出
        if (s_data.top() == s_min.top()) {
            s_min.pop();
        }
        s_data.pop();
    }
    
    int top() {
        return s_data.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};
```

## 5. 复杂度分析
* **时间复杂度**：所有操作 (`push`, `pop`, `top`, `getMin`) 均为 $O(1)$。
* **空间复杂度**：$O(N)$，最坏情况下（数据递减插入），辅助栈的大小与数据栈相同。