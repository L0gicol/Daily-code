# [Algorithm] LeetCode 21: 合并两个有序链表 - 迭代拼接与递归风险的工程权衡

> **发布时间**: 2026-01-22
> **标签**: `C++` `LeetCode` `Linked List` `Splicing`

## 1. 问题背景 (Problem)

**LeetCode #21 Merge Two Sorted Lists** 是归并排序 (Merge Sort) 中 "Merge" 步骤的独立实现。
题目要求将两个升序链表合并为一个新的升序链表。

**ZJU 考察视角**：
虽然可以用递归轻松解决，但在系统编程（System Programming）中，我们需要考察对 **栈空间 (Stack Space)** 的敏感度以及 **原地指针操作 (In-place Manipulation)** 的能力。

## 2. 解法演进 (Evolution)

* **解法一：递归法 (Recursive)**
    * *思路*：利用函数调用栈。`list1->next = merge(list1->next, list2)`。
    * *工程缺陷*：虽然代码简洁，但空间复杂度为 $O(N+M)$（栈深度）。如果链表极长（如 10万节点），会触发 **Stack Overflow**。这在生产环境中是不可控的风险。

* **解法二：迭代穿针引线法 (Iterative Splicing) [推荐]**
    * *思路*：维护一个 `tail` 指针，像拉拉链一样，调整现有节点的 `next` 指向。
    * *优势*：
        1.  **空间复杂度 $O(1)$**：仅使用常数级指针变量，无递归开销。
        2.  **零拷贝 (Zero Copy)**：直接复用原链表内存，不创建新节点 (`new`)，内存效率极高。

## 3. 标准代码 (ZJU Standard Code)

采用 **虚拟头节点 (Dummy Node)** + **尾插法**，消除头节点特判逻辑。

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. 工程技巧：虚拟头节点 (Dummy Node)
        // 避免处理 "新链表头是谁" 的边界情况，统一逻辑
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // 2. 穿针引线 (Splicing)
        // 只要两队都有人，就持续 PK
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;    // 接入 list1
                list1 = list1->next;   // list1 指针后移
            } else {
                tail->next = list2;    // 接入 list2
                list2 = list2->next;   // list2 指针后移
            }
            tail = tail->next;         // 尾指针永远指向最新接入的节点
        }

        // 3. O(1) 快速收尾
        // 循环结束时，必有一条链表非空。
        // 直接将剩余的一整串接在 tail 后面，无需遍历。
        tail->next = (list1 != nullptr) ? list1 : list2;

        // 4. 释放 dummy 内存 (C++ RAII 习惯)
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};
```

## 4. 核心复盘 (Critical Thinking)

### 权衡点：为什么循环结束后不需要 `while`？
初学者容易写成：
```cpp
while(list1) { tail->next = list1; list1 = list1->next; ... } // 冗余操作
```
**深度解析**：
链表本身已经是有序且连接好的。我们做的是“拼接”操作，不是“复制”操作。
既然 `list1` 剩下的一串都在内存里连着，直接把 `tail->next` 指向 `list1` 当前头节点，整串就都接上了。这是链表区别于数组的巨大优势。

### 内存管理：Dummy Node 的生命周期
在 LeetCode 刷题中容易忽略 `delete dummy`。但在实际 C++ 工程中，任何 `new` 出来的对象都必须有对应的 `delete`，否则就是 **Memory Leak**。养成手动释放辅助节点的习惯，是合格 C++ 工程师的基本素养。

## 5. 核心总结 (Takeaway)
> 链表合并的本质是 **指针重定向 (Pointer Redirection)**。在工程上，为了规避栈溢出风险，**迭代 (Iteration)** 永远优于递归。