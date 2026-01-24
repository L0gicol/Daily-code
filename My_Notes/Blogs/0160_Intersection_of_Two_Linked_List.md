# [Algorithm] LeetCode 160: 相交链表 - 代码里的极致浪漫

> **发布时间**: 2026-01-24
> **标签**: `C++` `LeetCode` `Two Pointers` `Romantic Code`

## 1. 问题背景 (The Problem)

**LeetCode 160. Intersection of Two Linked Lists**
给你两个单链表的头节点 `headA` 和 `headB`，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null`。

* **难点**：两个链表长度不一样。如果两个指针同时出发，无法在“起跑线不同”的情况下同时到达交点。
* **约束**：要求 $O(N)$ 时间复杂度，$O(1)$ 空间复杂度。

## 2. 核心思路：双向奔赴 (The "Romantic" Algorithm)

这道题的官方解法常被称为 **“浪漫算法”**。

### 💡 直觉
我们无法消除链表的**长度差**，但我们可以通过**“互换道路”**来消除这个差异。
* 指针 `p1`：走完 A 链表后，立刻跳去走 B 链表。
* 指针 `p2`：走完 B 链表后，立刻跳去走 A 链表。

### 📐 数学证明
假设 A 独有长度为 $a$，B 独有长度为 $b$，公共长度为 $c$。
**两条路线的总路程完全相等**：
1.  `p1` 的轨迹：$a + c + b$
2.  `p2` 的轨迹：$b + c + a$

**结论**：
只要按照这个规则走，无论谁长谁短，它们一定会**在同一时刻**到达那个“相交点”。即使没有相交点，也会在终点同时变成 `nullptr`。

## 3. ZJU 标准代码 (ZJU Standard Code)

利用 C++ 三元运算符，将逻辑压缩至极简。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        // 只要没相遇（或者没同时走到尽头），就一直走
        while (p1 != p2) {
            // p1 走完了吗？走完了去对方的世界(headB)看看，没走完继续走
            p1 = (p1 == nullptr) ? headB : p1->next;
            
            // p2 走完了吗？走完了去对方的世界(headA)看看，没走完继续走
            p2 = (p2 == nullptr) ? headA : p2->next;
        }
        
        // 最终 p1 要么是交点，要么是 nullptr (无缘)
        return p1;
    }
};

🥚 彩蛋：关于 nullptr 的一点碎碎念 (Easter Egg)


如果把 p1 比作我，把 p2 比作她。 我们起跑线不同，人生轨迹也长短不一。

算法让我们做了一次尝试： “我走过我走过的路，也试着去走一遍你走过的路。”

如果我们在某个节点相遇了，那是幸运，那是 Intersection。 但更多的时候，现实是 Case 2: No Intersection。

这时候，算法给出的结局并不是报错（Error），也不是死循环（Loop）。 而是：

我走完了我的路，也读完了你的路。

你走完了你的路，也读完了我的路。

最后，我们在 nullptr 处相遇。

while (p1 != p2) 循环结束了，返回 null。 没有交集，但也没有遗憾。 我们都在生命的边界处，殊途同归，体面地退出了循环。

"Even if we don't intersect, we meet at the end."