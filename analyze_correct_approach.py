"""
The claim is FALSE. Now let's understand why and what the correct approach should be.

Key insight from counterexamples:
The simplest counterexample is when r has ONE child c1, and c1 has two branches.
If r has only one child c1, then D(c1) = 0 (removing c1 leaves only r, max depth 0).
So gain(c1) = 0 * S[c1] = 0.

But detaching a grandchild u at depth 2: if there's a deep chain parallel to u,
D(u) can be large, giving positive gain.

The critical failure case: r has a child c such that c is the ONLY path to depth,
and c's subtree has "parallel" branches -- one branch is deep, another has high weight.
Detaching the high-weight branch at depth 2 and reattaching to the deep branch is
better than detaching c (which removes everything).

So what IS the correct structure of the optimal detachment?

Let's think about what nodes we should consider. For fixed r, for each node u in subtree(r),
gain(u) = (D(u) + 1 - depth_r(u)) * S[u]

where D(u) = max depth in subtree(r) \ subtree(u).

This requires computing D(u) and S[u] for every u in subtree(r), for every r.
That's O(n^2) total work if done naively.

Let me think about what structure D(u) has.

For a fixed root r, let's think about the "max depth" information.
Let M be the max depth in subtree(r).
For each node u in subtree(r):
  D(u) = max depth among nodes in subtree(r) \ subtree(u).

If the node achieving max depth M is NOT in subtree(u), then D(u) = M.
If it IS in subtree(u), then D(u) = second max depth considering paths not through u.

Actually, D(u) relates to the "virtual tree" concept. Let me think differently.

For a fixed root r, consider any node u in subtree(r). The max depth path from r goes
through some sequence of nodes. If we remove subtree(u), we remove that path only if
u is on it.

More precisely: D(u) = max over all leaves l in subtree(r) but NOT in subtree(u) of depth(l).

This is related to the concept of "max depth excluding a subtree" which can be computed
using the standard trick: for each node, keep track of the top-2 deepest paths through
different children.

For the ORIGINAL tree (rooted at 1), we can precompute for each node v:
- max_depth[v] = max depth in subtree of v (in the original tree)
- S[v] = sum of weights in subtree of v

For a query root r, the subtree of r in the original tree is just the subtree rooted at r.
Wait, actually the problem says "tree rooted at 1" and "for each r, consider subtree of r."
So the tree structure is fixed, rooted at node 1, and for each node r we look at its subtree.

So depth_r(u) = depth(u) - depth(r) for u in subtree(r) in the original tree.

Now for each r, we want:
max over u in subtree(r), u != r, of:
  (D_r(u) + 1 - (depth(u) - depth(r))) * S[u]

where D_r(u) = max over v in subtree(r) \ subtree(u) of (depth(v) - depth(r)).

Let me define:
  maxdep(v) = max depth of a leaf in subtree(v) = max over l in subtree(v) of depth(l) - depth(v)

So the max depth in subtree(r) is maxdep(r) + depth(r)... no wait.
maxdep(r) = max over l in subtree(r) of (depth(l) - depth(r)).
This is the max depth relative to r.

For D_r(u): the max depth relative to r among nodes not in subtree(u).

If u is a node in subtree(r), then subtree(r) \ subtree(u) consists of:
- All nodes on the path from r to parent(u)
- All subtrees hanging off this path (except the one containing u)
- Nothing else below u.

For the standard approach, for each node v in subtree(r), we need the max depth in
subtree(r) that does NOT go through v's subtree. This is a well-known problem:
keep top-2 max depths among children.

For a node v with children c1, c2, ..., ck:
  maxdep(v) = 1 + max over ci of maxdep(ci)

For each child ci:
  max_depth_excluding_ci = max over cj, j != i, of (1 + maxdep(cj))
  This equals 1 + second_max if ci achieves the max, or 1 + first_max otherwise.

Then D_r(u):
  Consider the path from r to u: r = v0, v1, ..., vd = u where d = depth(u) - depth(r).

  D_r(u) = max over i=0..d-1 of (depth(vi) - depth(r) + max_depth_excluding_{v_{i+1}}(vi))

  Plus we also include depth(vi) - depth(r) for each vi on the path (the vi themselves).
  But max_depth_excluding already accounts for paths not going through v_{i+1}.

  Actually more precisely:
  D_r(u) = max over all nodes w in subtree(r) \ subtree(u) of (depth(w) - depth(r)).

  Any such w is either:
  - On the path from r to parent(u), or
  - In a subtree hanging off this path (but not through the path toward u).

  So D_r(u) = max over i=0..d-1 of:
    max(depth(vi) - depth(r),  max over cj of vi where cj != v_{i+1} of (maxdep(cj) + depth(vi) + 1 - depth(r)))

  = max over i=0..d-1 of max(depth(vi) - depth(r), depth(vi) - depth(r) + max_depth_excl_{v_{i+1}}(vi))

  = max over i=0..d-1 of (depth(vi) - depth(r) + max(0, max_depth_excl_{v_{i+1}}(vi)))

  where max_depth_excl_c(v) = max over children c' of v, c' != c, of (1 + maxdep(c')).
  If v has no other children, this is 0 (just v itself, relative depth 0 from v).

  Wait, let me reconsider. max_depth_excl_c(v) should be the max depth in subtree(v)
  excluding the subtree through child c. This includes v itself (relative depth 0) and
  all other children's subtrees. So it's max(0, max over c' != c of (1 + maxdep(c'))).

  So D_r(u) = max over i=0..d-1 of (depth(vi) - depth(r) + max(0, max_depth_excl_{v_{i+1}}(vi)))

This is computable but requires traversing the path from r to u for each u.

For the optimization problem for fixed r:
  answer(r) = base_cost(r) + max(0, max over u != r in subtree(r) of gain(u))
  gain(u) = (D_r(u) + 1 - depth_r(u)) * S[u]

For an O(n) or O(n log n) per node solution, we'd need to be clever.

But actually, the problem likely expects O(n log n) or O(n) total, not per node.
Let me reconsider.

Actually wait: the problem asks for the answer for EACH r. That's n answers.
Each answer requires examining all nodes in subtree(r) and finding the one that
maximizes gain. This is O(n^2) naively.

Let me think about what efficient approach works.

For the overall problem, I think the key observations are:

1. base_cost(r) can be computed for all r in O(n) total using the relation:
   When we move from a node to its child as root, the base cost changes predictably.

2. For the optimal operation, we need to efficiently find for each r the best u in subtree(r).

This is a hard optimization problem. Let me think about what competitive programming
techniques apply...

Actually, let me re-examine the structure. Let me focus on verifying the counterexample
and understanding the simplest counterexample.
"""

# Let's look at the simplest counterexample more carefully
# n=4, parents=[0, 0, 1, 1], weights=[0, 1, 1, 1]
#
# Tree:
#   0 (root)
#   └── 1 (child of 0, a=1)
#       ├── 2 (child of 1, a=1)
#       └── 3 (child of 1, a=1)
#
# r = 0. Subtree of r = {0, 1, 2, 3}.
# depths from r: d(0)=0, d(1)=1, d(2)=2, d(3)=2.
# base_cost = 0*0 + 1*1 + 1*2 + 1*2 = 5.
#
# Detach node 1 (child of r, depth 1):
#   Remove subtree(1) = {1,2,3}. Remaining: {0}. D(1) = 0.
#   gain = (0 + 1 - 1) * S[1] = 0 * 3 = 0.
#
# Detach node 2 (grandchild, depth 2):
#   Remove subtree(2) = {2}. Remaining: {0, 1, 3}. D(2) = max(0,1,2) = 2.
#   gain = (2 + 1 - 2) * 1 = 1.
#   New arrangement: reattach 2 to node 3 (the deepest remaining node).
#   New depth of 2 = 3. New cost = 0 + 1 + 3 + 2 = 6. Gain = 1. Correct!
#
# So when r has only ONE child, detaching that child gives gain 0 (you can only reattach
# to r, depth doesn't change). But detaching a grandchild can give positive gain.

print("Simplest counterexample analysis:")
print("Tree: r=0 -> 1 -> {2, 3}, all weights 1")
print("Detach child 1: gain = 0 (only r remains, reattach to r, no depth change)")
print("Detach grandchild 2: gain = 1 (reattach to node 3, depth increases from 2 to 3)")
print()

# Now let's think about what structure the optimal solution actually needs
# to handle. The claim fails primarily when:
# 1. r has a child c that is the only path to deep nodes
# 2. Detaching c leaves nothing deep (gain ~= 0)
# 3. But detaching a descendant of c preserves the deep path and gains something

# Let me verify: is it true that we only need to consider children of r
# AND grandchildren of r (depth 1 and 2)?

# Or even: children of r and children of children of r?

# Let me check with deeper counterexamples.

from collections import deque

def check_optimal_depth(n_trials=100000):
    """Check what depth the optimal detachment node tends to be at."""
    import random
    random.seed(123)

    max_optimal_depth = 0
    depth_counts = {}

    for trial in range(n_trials):
        n = random.randint(3, 12)
        parents = [0]  # parent of root (unused)
        for i in range(1, n):
            parents.append(random.randint(0, i-1))

        a = [0] + [random.randint(1, 100) for _ in range(n-1)]

        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parents[i]].append(i)

        # Compute depths
        depth = [0] * n
        order = []
        q = deque([0])
        while q:
            v = q.popleft()
            order.append(v)
            for c in children[v]:
                depth[c] = depth[v] + 1
                q.append(c)

        # Subtree sums
        S = [0] * n
        for v in reversed(order):
            S[v] = a[v] + sum(S[c] for c in children[v])

        def get_subtree(v):
            result = set()
            stack = [v]
            while stack:
                x = stack.pop()
                result.add(x)
                stack.extend(children[x])
            return result

        best_gain = 0
        best_depth = 0

        for u_det in range(1, n):
            sub_u = get_subtree(u_det)
            outside = [v for v in range(n) if v not in sub_u]
            if not outside:
                continue
            D_u = max(depth[v] for v in outside)
            gain = (D_u + 1 - depth[u_det]) * S[u_det]
            if gain > best_gain:
                best_gain = gain
                best_depth = depth[u_det]

        if best_gain > 0:
            depth_counts[best_depth] = depth_counts.get(best_depth, 0) + 1
            max_optimal_depth = max(max_optimal_depth, best_depth)

    print("Distribution of optimal detachment depths:")
    for d in sorted(depth_counts.keys()):
        print(f"  Depth {d}: {depth_counts[d]} times ({depth_counts[d]/sum(depth_counts.values())*100:.1f}%)")
    print(f"Max optimal depth seen: {max_optimal_depth}")

check_optimal_depth()

print()
print("=" * 60)
print("Can the optimal detach node be at depth >= 3?")
print("=" * 60)

def find_deep_counterexample():
    """Try to find cases where optimal detach is at depth >= 3."""
    import random
    random.seed(456)

    found = 0
    for trial in range(500000):
        n = random.randint(5, 15)
        parents = [0]
        for i in range(1, n):
            parents.append(random.randint(0, i-1))

        a = [0] + [random.randint(1, 1000) for _ in range(n-1)]

        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parents[i]].append(i)

        depth = [0] * n
        order = []
        q = deque([0])
        while q:
            v = q.popleft()
            order.append(v)
            for c in children[v]:
                depth[c] = depth[v] + 1
                q.append(c)

        S = [0] * n
        for v in reversed(order):
            S[v] = a[v] + sum(S[c] for c in children[v])

        def get_subtree(v):
            result = set()
            stack = [v]
            while stack:
                x = stack.pop()
                result.add(x)
                stack.extend(children[x])
            return result

        best_gain = 0
        best_node = -1
        best_at_depth_le2 = 0

        for u_det in range(1, n):
            sub_u = get_subtree(u_det)
            outside = [v for v in range(n) if v not in sub_u]
            if not outside:
                continue
            D_u = max(depth[v] for v in outside)
            gain = (D_u + 1 - depth[u_det]) * S[u_det]
            if gain > best_gain:
                best_gain = gain
                best_node = u_det
            if depth[u_det] <= 2 and gain > best_at_depth_le2:
                best_at_depth_le2 = gain

        if best_node != -1 and depth[best_node] >= 3 and best_gain > best_at_depth_le2:
            found += 1
            if found <= 3:
                print(f"\nDeep counterexample #{found}:")
                print(f"  n={n}, parents={parents}, weights={a}")
                print(f"  Best node: {best_node}, depth={depth[best_node]}, gain={best_gain}")
                print(f"  Best at depth<=2: gain={best_at_depth_le2}")
                # Print all gains
                for u_det in range(1, n):
                    sub_u = get_subtree(u_det)
                    outside = [v for v in range(n) if v not in sub_u]
                    if not outside:
                        continue
                    D_u = max(depth[v] for v in outside)
                    gain = (D_u + 1 - depth[u_det]) * S[u_det]
                    marker = " <-- BEST" if u_det == best_node else ""
                    print(f"    Node {u_det}: depth={depth[u_det]}, parent={parents[u_det]}, S={S[u_det]}, D={D_u}, gain={gain}{marker}")

    print(f"\nTotal deep (depth>=3) counterexamples found: {found} out of 500000 trials")

find_deep_counterexample()
