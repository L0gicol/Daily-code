# [Algorithm] LeetCode 141: 环形链表 - 快慢指针的物理学本质

> **发布时间**: 2026-01-23
> **标签**: `C++` `LeetCode` `Two Pointers` `Floyd's Cycle-Finding`

## 1. 问题背景 (Problem)

**LeetCode #141 Linked List Cycle** 是链表算法中的“果蝇”级实验题，也是 **Floyd 判圈算法 (Floyd's Cycle-Finding Algorithm)** 的直观应用。
题目要求判断链表中是否有环。

**ZJU 考察视角**：
这道题是浙大机试和面试的高频题，核心考点不在于“做出来”，而在于：
1.  **空间敏感度**：能否在不申请额外内存（$O(1)$ Space）的情况下解决？（拒绝哈希表）。
2.  **指针安全**：在高速移动指针（`next->next`）时，能否确保不发生 **Segmentation Fault**。

## 2. 解法演进 (Evolution)

* **直觉解法：哈希表记账 (Hash Set)**
    * *思路*：遍历链表，每到一个节点就把地址存入 `std::unordered_set`。如果遇到已存在的地址，说明有环。
    * *缺陷*：空间复杂度为 $O(N)$。在操作系统内核或嵌入式设备等对内存极度敏感的场景下，这是不可接受的。

* **工程解法：快慢指针 (Fast & Slow Pointers) [推荐]**
    * *思路*：利用**相对速度**。定义慢指针 `slow` 每次走 1 步，快指针 `fast` 每次走 2 步。
        * 若无环：`fast` 会率先抵达终点 (`nullptr`)。
        * 若有环：`fast` 必然会在环内从背后追上 `slow`（套圈）。
    * *优势*：**$O(1)$ 空间复杂度**，零内存分配，代码极其精简。

## 3. 标准代码 (ZJU Standard Code)

摒弃多余的 `Dummy Node` 和复杂的 `while(1)`，采用最纯粹的条件判断。

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
    bool hasCycle(ListNode *head) {
        // 1. 边界防御：空链表或单节点链表不可能有环
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // 2. 初始化双指针
        // slow 走一步，fast 走两步
        ListNode* slow = head;
        ListNode* fast = head;

        // 3. 核心循环 (Floyd's Algorithm)
        // 关键点：必须确保快指针的当前节点(fast)和下一跳(fast->next)均不为空
        // 否则 fast->next->next 会触发 SegFault
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // v = 1
            fast = fast->next->next;    // v = 2

            // 物理碰撞检测：如果指针指向同一地址，说明有环
            if (slow == fast) {
                return true;
            }
        }

        // 4. 循环正常结束，说明快指针跑到了尽头，无环
        return false;
    }
};
```

## 4. 避坑复盘 (Debug Notes)

在编写过程中，排查了以下潜在的工程隐患：

* **坑点一：野指针崩溃 (Segmentation Fault)**
    * *错误写法*：`while (slow != fast)` 或只判断 `fast != nullptr`。
    * *后果*：当链表长度为奇数或偶数不同情况时，`fast->next` 可能是空指针，直接访问 `fast->next->next` 会导致程序崩溃。
    * *修正*：严格使用 `while (fast && fast->next)` 作为护盾。

* **坑点二：过度设计 (Over-engineering)**
    * *错误习惯*：习惯性使用 `Dummy Node`。
    * *反思*：本题是只读操作（Read-only），不涉及链表结构的修改（如插入/删除），引入 Dummy Node 是画蛇添足，且容易忘记 `delete` 导致微小的内存泄漏。

## 5. 核心总结 (Takeaway)

> 环形链表问题的本质是 **追及问题**：在一个有环的有限空间内，速度差为 1 的两个物体必然会相遇。