# [Algorithm] LeetCode 0021: 合并两个有序链表 - 穿针引线法的工程实践

> **发布时间**: 2026-01-22
> **标签**: `C++` `LeetCode` `Linked List` `Two Pointers`

## 1. 问题背景 (Problem)

**LeetCode #21 合并两个有序链表 (Merge Two Sorted Lists)** 是链表操作的基石，也是归并排序 (Merge Sort) 的核心步骤。
题目要求将两个升序链表合并为一个新的升序链表。

虽然题目简单，但在追求 **极致性能 (0ms)** 和 **工程规范 (Clean Code)** 的过程中，非常考验对 C++ 指针操作和内存管理的理解。

## 2. 思维误区：深拷贝 (Deep Copy)

初次上手时，容易陷入一种思维定势：
> "我要创建一个新链表，遍历两个旧链表，谁小就 `new` 一个新节点接上去。"

**这种做法的缺陷：**
1.  **空间浪费**：空间复杂度达到 $O(N+M)$。如果链表节点包含大量数据，内存消耗将翻倍。
2.  **效率低下**：频繁的 `new` 操作极其耗时。

**正确思维：穿针引线 (Splicing)**
我们不需要创建新车厢，只需要做一个“调度员”。通过改变现有节点的 `next` 指针，将两个链表像拉拉链一样“缝”在一起。空间复杂度仅需 $O(1)$。

## 3. 核心技巧：虚拟头节点 (Dummy Node)

在处理链表合并时，新链表的**头节点**是不确定的（可能是 list1 的头，也可能是 list2 的头）。
为了避免写一堆繁琐的边界判断（如 `if (head == nullptr)`），工程上最优雅的解法是引入 **Dummy Node**。

* **定义**：`ListNode* dummy = new ListNode(-1);`
* **作用**：它作为一个固定的“桩子”，我们只需要维护一个 `tail` 指针永远指向新链表的末尾。
* **结果**：最后返回 `dummy->next` 即可，无需关心谁是第一个节点。

## 4. 标准代码实现 (C++ Beats 100%)

以下是经过优化的双指针解法，逻辑清晰，无冗余判断。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. 工程技巧：使用 Dummy Node 简化头节点逻辑
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy; // tail 始终指向合并后链表的尾部

        // 2. 准备双指针
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        // 3. 穿针引线 (Splicing)
        // 只要两个链表都不为空，就持续 PK
        while (p1 && p2) {
            if (p1->val < p2->val) {
                tail->next = p1;    // 谁小，tail 就指向谁
                p1 = p1->next;      // 只有被选中的指针后移
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;      // 尾指针永远跟在最后
        }

        // 4. 收尾 (O(1) 复杂度)
        // 循环结束说明有一条链表空了，直接把另一条剩余的“一串”接上即可
        // 避免了无意义的循环遍历
        if (p1 != nullptr) {
            tail->next = p1;
        } else {
            tail->next = p2;
        }

        // 5. 返回结果并释放 dummy (工程习惯)
        ListNode* result = dummy->next;
        delete dummy; // 防止内存泄漏
        return result;
    }
};
```

## 5. 避坑复盘 (Debug Notes)

在编写过程中，我排查了几个严重的逻辑漏洞：

### 坑点一：野指针 (Wild Pointer)
**错误写法**：`ListNode* head; ListNode* tail = head;`
**后果**：声明指针未初始化，`head` 指向随机内存地址。后续操作 `tail->next` 直接导致 **Segmentation Fault**。
**修正**：必须实例化 `new ListNode(-1)`。

### 坑点二：双指针移动逻辑
**错误写法**：在比较大小后，同时让 `p1` 和 `p2` 都向后移动。
**后果**：会导致较大的那个节点被直接跳过（丢失）。
**修正**：**谁小移谁**，大的那个指针保持不动，等待下一轮比较。

### 坑点三：冗余的尾部判断
**错误写法**：`while` 循环结束后，再次运行 `if` 比较 `p1` 和 `p2` 的值。
**后果**：此时必有一个指针为空，访问空指针的值会导致崩溃。
**修正**：循环结束后，逻辑上只剩下一条非空链表，直接 `tail->next = non_empty_list` 即可。

## 6. 性能总结
* **Time**: $O(N + M)$ - 必须遍历两个链表的所有节点。
* **Space**: $O(1)$ - 仅使用了 `dummy`, `tail`, `p1`, `p2` 四个指针变量，没有创建任何承载数据的新节点。

> **Takeaway**: 链表问题的核心在于**指针的调度**，而不是内存的分配。能用指针解决的，绝不 `new`。