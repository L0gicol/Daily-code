# 【LeetCode 242】Valid Anagram：从 Set 的“去重”坑到数组优化

> **日期**：2026-01-20  
> **标签**：#HashTable #String #C++ #Array

## 1. 题目描述
**题目**：[242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)  
**要求**：给定两个字符串 `s` 和 `t`，编写一个函数来判断 `t` 是否是 `s` 的字母异位词（即字母完全相同，只是顺序不同）。

**示例**：
- 输入: `s = "anagram"`, `t = "nagaram"` -> 输出: `true`
- 输入: `s = "rat"`, `t = "car"` -> 输出: `false`

---

## 2. 初次尝试：掉进 Set 的陷阱

刚开始做这道题时，我的直觉是：**“只要两个字符串里包含的字符种类一样，不就是异位词吗？”**
于是我使用了 `std::set`，因为它能自动排序且去重，看起来很方便。

### ❌ 错误代码 (Wrong Answer)
```cpp
bool isAnagram(string s, string t) {
    set<char> s1, t1;
    for(char c : s) s1.insert(c);
    for(char c : t) t1.insert(c);
    return s1 == t1; // 比较两个集合是否相等
}