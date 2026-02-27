"""
Now let's understand the correct formulation and think about efficient computation.

For a fixed root r, gain(u) = (D(u) + 1 - depth_r(u)) * S[u] where:
  - depth_r(u) = depth(u) - depth(r) in the original tree
  - S[u] = sum of a[w] for w in subtree(u) in original tree
  - D(u) = max depth (relative to r) among nodes in subtree(r) \ subtree(u)

Key insight: D(u) depends on u's position on the heavy path.

For u on the path from r to the deepest leaf:
  D(u) = max of:
    (a) max depth among nodes NOT in subtree of r's child containing u
        (i.e., the second-max depth among r's children, plus other subtrees)
    (b) max depth among nodes in subtree(r_child) but not in subtree(u)
        (using top-2 depths at each node along the path)

For u NOT on the path from r to the deepest leaf:
  D(u) = max_depth_in_subtree(r)  (the deepest leaf is not in subtree(u))

So for most nodes u, D(u) = maxdep(r). The formula simplifies to:
  gain(u) = (maxdep(r) + 1 - depth_r(u)) * S[u]  when u is not an ancestor of the deepest leaf.

For nodes u that ARE on the path from r to the deepest leaf, D(u) is harder to compute.

Let me verify this understanding and think about what information we need per root r.
"""

from collections import deque

def solve_brute_force(n, parents, a):
    """Brute force solution: for each root r, compute base cost + max gain."""
    children = [[] for _ in range(n)]
    for i in range(1, n):
        children[parents[i]].append(i)

    # Compute depths in original tree (rooted at node 0 or 1, depending on indexing)
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

    results = []
    for r in range(n):
        sub_r = get_subtree(r)

        # Base cost
        base_cost = sum(a[v] * (depth[v] - depth[r]) for v in sub_r)

        # Find best gain
        best_gain = 0
        for u in sub_r:
            if u == r:
                continue
            sub_u = get_subtree(u)
            outside = sub_r - sub_u
            if not outside:
                continue
            D_u = max(depth[v] - depth[r] for v in outside)
            gain = (D_u + 1 - (depth[u] - depth[r])) * S[u]
            if gain > best_gain:
                best_gain = gain

        results.append(base_cost + best_gain)

    return results

# Test on the problem's examples if available, or on our own examples
print("Test case 1: Simple chain")
# 0 -> 1 -> 2 -> 3, all weights 1
n = 4
parents = [0, 0, 1, 2]
a = [1, 1, 1, 1]
print(f"Results: {solve_brute_force(n, parents, a)}")

print("\nTest case 2: Star graph")
# 0 has children 1, 2, 3
n = 4
parents = [0, 0, 0, 0]
a = [1, 1, 1, 1]
print(f"Results: {solve_brute_force(n, parents, a)}")

print("\nTest case 3: Our counterexample")
# 0 -> 1 -> {2, 3}, all weights 1
n = 4
parents = [0, 0, 1, 1]
a = [0, 1, 1, 1]
print(f"Results: {solve_brute_force(n, parents, a)}")

print("\n" + "=" * 60)
print("ANALYSIS: What information is needed per root r?")
print("=" * 60)

# For each root r, we need to find:
# max over u in subtree(r), u != r, of (D(u) + 1 - depth_r(u)) * S[u]
#
# Let's categorize nodes by whether they're on the "max-depth path" from r.
#
# For each node v in the original tree, define:
#   maxdep(v) = max depth of a leaf in subtree(v) (relative to v)
#   For each child c of v:
#     maxdep_excl(v, c) = max depth in subtree(v) excluding subtree(c), relative to v
#                       = max(0, max over c' != c of (1 + maxdep(c')))
#
# These can be computed with the standard top-2 trick.

# For a fixed root r, and a node u in subtree(r):
# Path from r to u: r = v0, v1, ..., vd = u (where vi+1 is the child of vi toward u)
#
# D(u) = max over i=0..d-1 of ((depth(vi) - depth(r)) + maxdep_excl(vi, v_{i+1}))
#
# This is correct because after removing subtree(u), the reachable nodes are exactly
# those not in subtree(u), and the deepest such node is found by branching off the
# path from r to u at each node along the way.

# So: gain(u) = (D(u) + 1 - d) * S[u]
#             = (max_{i=0..d-1} (i + maxdep_excl(vi, v_{i+1})) + 1 - d) * S[u]
# where i = depth(vi) - depth(r) and d = depth(u) - depth(r).

# Note: for i=0, vi = r, v1 is the child of r toward u.
# maxdep_excl(r, v1) = max depth in subtree(r) not going through v1's subtree.

# This is the standard "contribution from branching off at each ancestor" formula.

# Now, for an efficient algorithm, we need to compute for EACH r the max over ALL u
# in subtree(r) of this gain. This is still O(n^2) total if done naively.

# For competitive programming, likely constraints and approaches:
# - If n <= 5000: O(n^2) is fine, just iterate over all (r, u) pairs.
# - If n <= 2*10^5: Need O(n log n) or O(n) total.

# For the efficient approach, note that when we fix u and vary r over all ancestors of u:
# gain(u, r) = (D_r(u) + 1 - (depth(u) - depth(r))) * S[u]

# S[u] doesn't depend on r. D_r(u) depends on the path from r to u and the branching.

# This suggests a "rerooting" or "heavy path" approach.

# But let me first confirm the formulas are correct by testing.

def solve_with_formula(n, parents, a):
    """Solve using the D(u) path formula and verify against brute force."""
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

    # Compute maxdep(v) for each v
    maxdep = [0] * n
    for v in reversed(order):
        if children[v]:
            maxdep[v] = 1 + max(maxdep[c] for c in children[v])
        else:
            maxdep[v] = 0

    # For each v, compute top-2 max depths among children
    # top1[v] = (max_value, child achieving it)
    # top2[v] = (second max value, child achieving it)
    top1 = [(-1, -1)] * n
    top2 = [(-1, -1)] * n
    for v in order:
        best = (-1, -1)
        second = (-1, -1)
        for c in children[v]:
            val = 1 + maxdep[c]
            if val > best[0]:
                second = best
                best = (val, c)
            elif val > second[0]:
                second = (val, c)
        top1[v] = best
        top2[v] = second

    def maxdep_excl(v, c):
        """Max depth in subtree(v) excluding subtree(c), relative to v."""
        if top1[v][1] == c:
            return max(0, top2[v][0])
        else:
            return max(0, top1[v][0])

    def get_subtree(v):
        result = []
        stack = [v]
        while stack:
            x = stack.pop()
            result.append(x)
            stack.extend(children[x])
        return result

    results = []
    for r in range(n):
        sub_r = get_subtree(r)
        base_cost = sum(a[v] * (depth[v] - depth[r]) for v in sub_r)

        best_gain = 0
        for u in sub_r:
            if u == r:
                continue
            # Compute D(u) using path formula
            # Walk from u up to r
            path = []
            v = u
            while v != r:
                path.append(v)
                v = parents[v]
            path.append(r)
            path.reverse()  # path[0] = r, path[-1] = u

            d = len(path) - 1  # depth of u from r
            D_u = 0
            for i in range(d):
                vi = path[i]
                vi_next = path[i + 1]
                branch_depth = i + maxdep_excl(vi, vi_next)
                D_u = max(D_u, branch_depth)

            gain = (D_u + 1 - d) * S[u]
            best_gain = max(best_gain, gain)

        results.append(base_cost + best_gain)

    return results

# Verify formula matches brute force
import random
random.seed(789)
print("\nVerification of formula against brute force:")
all_match = True
for trial in range(1000):
    n = random.randint(2, 10)
    parents = [0]
    for i in range(1, n):
        parents.append(random.randint(0, i-1))
    a = [random.randint(0, 10) for _ in range(n)]

    bf = solve_brute_force(n, parents, a)
    fm = solve_with_formula(n, parents, a)

    if bf != fm:
        print(f"MISMATCH at trial {trial}!")
        print(f"  n={n}, parents={parents}, a={a}")
        print(f"  BF: {bf}")
        print(f"  FM: {fm}")
        all_match = False
        break

if all_match:
    print("All 1000 random tests passed! Formula is correct.")

print("\n" + "=" * 60)
print("EFFICIENT APPROACH ANALYSIS")
print("=" * 60)
print("""
For each root r, we need:
  max over u in subtree(r), u != r, of:
    (D_r(u) + 1 - depth_r(u)) * S[u]

where D_r(u) = max over ancestors v of u (between r and parent(u)) of:
    (depth_r(v) + maxdep_excl(v, child_toward_u))

Let f(v, c) = depth(v) + maxdep_excl(v, c)  [absolute depth, not relative to r]

Then D_r(u) = max over (v, c) on path from r to u of (f(v,c) - depth(r))

And gain(u) = (D_r(u) + 1 - depth(u) + depth(r)) * S[u]
            = (max_{path} f(v,c) - depth(r) + 1 - depth(u) + depth(r)) * S[u]
            = (max_{path} f(v,c) + 1 - depth(u)) * S[u]

WAIT! The depth(r) terms cancel! So gain(u) does NOT depend on r?!

Let me verify...

gain(u, r) = (D_r(u) + 1 - depth_r(u)) * S[u]

D_r(u) = max over i=0..d-1 of (i + maxdep_excl(v_i, v_{i+1}))
       where v_i is at depth depth(r) + i from original root.

= max over i of (depth(v_i) - depth(r) + maxdep_excl(v_i, v_{i+1}))

depth_r(u) = depth(u) - depth(r)

gain = (max_i(depth(v_i) + maxdep_excl(v_i, v_{i+1})) - depth(r) + 1 - depth(u) + depth(r)) * S[u]
     = (max_i(depth(v_i) + maxdep_excl(v_i, v_{i+1})) + 1 - depth(u)) * S[u]

BUT: the max is taken over i from 0 to d-1, and the set of (v_i, v_{i+1}) pairs
depends on r! When r = parent(u), we only have one pair. When r is further up, we
have more pairs.

So gain(u, r) = (max over (v,c) on path from r to u of f(v,c) + 1 - depth(u)) * S[u]

where f(v, c) = depth(v) + maxdep_excl(v, c).

Let F(u, r) = max over (v, c) on path from r to u of f(v, c).

Then gain(u, r) = (F(u, r) + 1 - depth(u)) * S[u].

Key observation: F(u, r) is the max of f(v, c) over all "edges" (v, c) on the
path from r down to u. As r moves further up (toward the root), F(u, r) can only
increase or stay the same (we're taking max over a larger set).

So F(u, r) = max(F(u, parent(r)), f(r, child_of_r_toward_u)).

Wait no, r is the root of the subtree we're considering. u is in subtree(r).

For the answer at root r, we want:
  max over u in subtree(r) of gain(u, r)
= max over u in subtree(r) of (F(u, r) + 1 - depth(u)) * S[u]

F(u, r) = max of f(v, c) for all edges (v -> c) on path from r to u.

Note that for u such that r = parent(u) (u is a child of r):
  F(u, r) = f(r, u) = depth(r) + maxdep_excl(r, u)

For u deeper: F(u, r) = max(f(r, child_toward_u), f(child_toward_u, next), ..., f(parent(u), u))
            = max(f(r, child_toward_u), F(u, child_toward_u))

This means F(u, r) = max(F(u, parent(r) step), f(r, ...)).

Actually, the simpler way to see it:
For each node u, define g(u) = max over all EDGES (v, c) on the path from root (node 0 or 1)
down to u, of f(v, c). This is a running max down the tree.

Then for root r that is an ancestor of u:
F(u, r) = max of f(v,c) for edges (v->c) where v is a descendant of r (or r itself)
         and c is on the path from r to u.

This is NOT the same as g(u) because g(u) includes edges above r too.

Hmm, but does it matter? Let's check.

gain(u, r) = (F(u, r) + 1 - depth(u)) * S[u]

If F(u, r) can be replaced by g(u) (which is potentially larger), the gain would be
at least as large. But we might include gain from edges above r that shouldn't count.

Wait: F(u, r) is the max of f(v,c) for edges ON THE PATH from r to u (so v is r or
a descendant of r). This DOES NOT include edges above r.

So we CAN'T just use g(u). We need to restrict to edges within subtree(r) on the
path from r to u.

However, there's a key insight: the answer for root r is:
  max over u in subtree(r) of (F(u,r) + 1 - depth(u)) * S[u]

And F(u,r) = max over edges (v,c) in the path from r to u, restricted to edges at or below r.

For any u in subtree(r):
  F(u, r) = max(f(r, c_r), F(u, c_r))  where c_r is the child of r on path to u.
  = max(f(r, c_r), max of f(v, c) for edges from c_r to u)
  = max(f(r, c_r), F(u, c_r))

And F(u, c_r) is the value we'd compute if the root were c_r.

This gives a recursion. But computing the answer for each r seems to still be O(subtree size).

ALTERNATIVE APPROACH: For each node u, gain(u, r) = (F(u,r) + 1 - depth(u)) * S[u].
The "best u" for root r could be any node. Can we think of this as:
for each r, maximize (F(u,r) + 1 - depth(u)) * S[u] over u in subtree(r)?

Since F(u,r) is the max over edges on the path from r to u, and this running max is
piecewise constant as u goes deeper, this is complex.

For competitive programming, the typical approach for such problems is either:
1. Euler tour + segment tree with some clever encoding
2. Small-to-large merging (DSU on tree)
3. Heavy-light decomposition
4. Centroid decomposition

Given the structure, let me think about what n is (constraints matter).

For now, the key takeaway: the claim that "detaching a child of r is always optimal" is FALSE.
""")
