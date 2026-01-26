# 【LeetCode】232. 用栈实现队列 (Implement Queue using Stacks) 解题笔记

## 1. 题目描述
仅使用两个栈实现先入先出队列 (FIFO)，支持 `push`, `pop`, `peek`, `empty` 操作。

## 2. 核心难点
* **栈 (Stack)**：后进先出 (LIFO)。
* **队列 (Queue)**：先进先出 (FIFO)。
我们需要利用两个栈将元素的顺序“倒转”过来。

## 3. 解题思路：双栈 + 懒惰策略 (Lazy Approach)
我们定义两个栈：
1.  **输入栈 (`s_in`)**：只负责接收 `push` 进来的数据。
2.  **输出栈 (`s_out`)**：只负责 `pop` 和 `peek` 数据。

### 关键逻辑
为了保证效率，我们不需要每次 push 都搬运数据，而是采用**“懒惰”**的策略：
* **入队 (`push`)**：直接压入 `s_in`。时间复杂度 $O(1)$。
* **出队/查看 (`pop`/`peek`)**：
    1.  首先检查 `s_out` 是否为空。
    2.  如果 `s_out` **不为空**：直接取栈顶（这就是最早进来的数据）。
    3.  如果 `s_out` **为空**：将 `s_in` 中的所有元素依次弹出并压入 `s_out`。
        * 这个过程实现了数据的逆序（栈底变栈顶）。
        * 搬运完成后，再从 `s_out` 取值。

### 为什么是均摊 O(1)？
虽然搬运过程是 $O(N)$，但每个元素在其生命周期内只会被搬运一次（进 `s_in` -> 搬到 `s_out` -> 出 `s_out`）。因此，平均到每次操作，时间复杂度依然是 $O(1)$。

## 4. 代码实现 (C++)

```cpp
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s_in;  // 输入栈
    stack<int> s_out; // 输出栈

public:
    MyQueue() {}
    
    void push(int x) {
        s_in.push(x);
    }
    
    // 复用逻辑：peek 负责检查并在必要时搬运数据
    int peek() {
        if (s_out.empty()) {
            // 只有当输出栈为空时，才把输入栈的东西倒过来
            while (!s_in.empty()) {
                s_out.push(s_in.top());
                s_in.pop();
            }
        }
        return s_out.top();
    }
    
    int pop() {
        // 直接调用 peek()，确保 s_out 中有数据
        int val = peek();
        s_out.pop();
        return val;
    }
    
    bool empty() {
        // 只有两个栈都为空时，队列才算空
        return s_in.empty() && s_out.empty();
    }
};
```

## 5. 复杂度分析
* **时间复杂度**：`push` 是 $O(1)$；`pop` 和 `peek` 是 **均摊 $O(1)$**。
* **空间复杂度**：$O(N)$，需要存储队列中的所有元素。