# Greedy algorithms

---

## What is a greedy algorithm?

"A greedy algorithm is an optimization technique that solves problems step by step, always selecting the best possible
choice at each moment. It follows a straightforward strategy: at every stage, it picks the option that looks most
favorable right now without considering the long-term impact of that decision."

A greedy algorithm is an algorithm that does not attempt to produce the best solution possible. Instead, it tries to
solve the problem as optimally as possible at each step, until it end up stuck at a local or absolute maximum.

![greedy example](../assets/Greedy-search-path-example.gif)

## Realistic use cases

The main goal of a greedy algorithm is to **optimize solutions** through iterative decisions.
Some typical use cases:

1) Dijkstra’s algorithm
   - Finding the shortest path in a weighted graph.
2) Knapsack problem
   - Selecting items with given weights and values to maximize value within a weight limit
3) Huffman coding
   - Creates an optimal prefix code for a set of symbols based on their frequencies.
   - Data compression.