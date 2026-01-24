# [Algorithm] LeetCode 142: 环形链表 II - 破解数学黑箱

> **发布时间**: 2026-01-24
> **标签**: `C++` `LeetCode` `Two Pointers` `Math`

## 1. 问题背景 (Problem Context)
**LeetCode #142 Linked List Cycle II** 是 #141 的进阶版。
如果说 #141 是问“有没有环”（Yes/No），那 #142 就是要求找出 **“环的入口在哪里”**（Return Node）。

**ZJU 考察视角**：
这道题是区分“普通码农”和“算法工程师”的分水岭。
* **普通解法**：用 `std::unordered_set` 记录访问过的节点，第一次重复的就是入口。空间复杂度 $O(N)$，在嵌入式或内核开发中会被直接否决。
* **满分解法**：**双指针 + 数学推导**。要求 $O(1)$ 空间，且逻辑必须严密，不能出现空指针崩溃。

## 2. 解法演进 (Solution Evolution)

* **阶段一：物理直觉 (Phase 1)**
    * 使用快慢指针（Fast & Slow Pointers）。
    * Fast 走 2 步，Slow 走 1 步。
    * 如果相遇，说明有环。
    * *坑点*：相遇点 (Meeting Point) 通常**不是**环的入口，而是在环中某个随机位置。

* **阶段二：数学魔法 (Phase 2)**
    * **推导核心**：假设起点到入口距离为 $a$，入口到相遇点距离为 $b$，相遇点再走回入口距离为 $c$。
    * 利用速度差公式可得：**$a = c + (n-1)L$**。
    * **物理意义**：从**起点 (Head)** 出发走的距离，和从**相遇点 (Meeting Point)** 继续往前走的距离，在到达入口时是**同步**的（忽略多转的圈数）。
    * **操作**：相遇后，将一个指针重置回 `head`，另一个保留在相遇点。两人同时改为**每次走 1 步**。再次相遇处即为入口。

## 3. ZJU 标准代码 (ZJU Standard Code)

经过优化的工程级写法，去除了冗余变量和复杂的 `break` 逻辑。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: 判圈 (The Race)
        // 必须先判断 fast 和 fast->next 都不为空，防止 SegFault
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // v = 1
            fast = fast->next->next;    // v = 2

            // 第一次相遇：确认有环
            if (slow == fast) {
                // Phase 2: 找入口 (The Reunion)
                // 1. 将 slow 扔回起点
                slow = head;
                
                // 2. 两个指针同速前进 (v = 1)
                // 利用 while 条件直接判断，逻辑最简
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                // 3. 再次相遇点即为入口
                return slow;
            }
        }
        
        // 无环情况
        return nullptr;
    }
};
```

## 4. 避坑复盘 (Debug Notes)

在实现过程中，修正了以下严重隐患：

1.  **SegFault 陷阱**：
    * *错误写法*：`while (fast->next != nullptr && fast != nullptr)`
    * *修正*：必须遵循 **短路求值 (Short-circuit evaluation)** 原则，先判 `fast` 再判 `fast->next`。否则当链表为空时，访问 `fast->next` 会直接导致程序崩溃。

2.  **逻辑死循环/误判**：
    * *错误思路*：在 Phase 2 强行先移动再判断。
    * *修正*：Phase 2 必须采用 **"Check-Do"** 模式（`while(slow != fast)`）。
    * *原因*：如果环的入口恰好就是头节点（Head），`slow` 重置后立刻与 `fast` 重合。如果先移动，就会错过正确答案，甚至死循环。

## 5. 核心总结 (Core Takeaway)

> 只要利用好“相对速度”，我们可以证明：**“回头是岸”的距离 (Head to Entry)** 刚好等于 **“继续前行”的距离 (Meeting to Entry)**。代码的尽头是数学。