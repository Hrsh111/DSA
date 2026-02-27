"""
Deep analysis of the gain formula and efficient computation.

For each root r, answer = base_cost(r) + max(0, max over u in subtree(r), u!=r, of gain(u,r))

gain(u, r) = (F(u,r) + 1 - depth(u)) * S[u]

where F(u, r) = max over edges (v -> child_toward_u) on path from r to u
                of f(v, child_toward_u)
      f(v, c) = depth(v) + maxdep_excl(v, c)

Key insight: F(u, r) = max(f(r, c_r), F(u, c_r)) where c_r = child of r toward u.

Since f(r, c_r) = depth(r) + maxdep_excl(r, c_r), and maxdep_excl(r, c_r) is the
max depth in subtree(r) not going through c_r...

For each node u, let's define:
  h(u) = f(parent(u), u) = depth(parent(u)) + maxdep_excl(parent(u), u)

  This is the "branching value" at the edge from parent(u) to u.
  It measures how deep we can go in parent(u)'s subtree without going through u.

Then F(u, r) = max of h(v) for all v on the path from (first child of r toward u) to u.

Wait, let me be more precise.

Path from r to u: r = v0, v1, ..., vd = u.
Edges: (v0, v1), (v1, v2), ..., (v_{d-1}, vd).
f values: f(v0, v1), f(v1, v2), ..., f(v_{d-1}, vd).

f(vi, v_{i+1}) = depth(vi) + maxdep_excl(vi, v_{i+1}) = h(v_{i+1}) [by definition of h]

Wait: h(v_{i+1}) = f(parent(v_{i+1}), v_{i+1}) = f(vi, v_{i+1}). Yes!

So F(u, r) = max(h(v1), h(v2), ..., h(vd)) = max of h(v) for v on path from
             first-child-of-r-toward-u down to u.

More precisely: F(u, r) = max of h(v) for all v that are strict descendants of r
                          AND ancestors-or-equal-to u.

i.e., F(u, r) = max{h(v) : v is on path from r to u, v != r}

Now gain(u, r) = (F(u,r) + 1 - depth(u)) * S[u]
               = (max{h(v) : r < v <= u on path} + 1 - depth(u)) * S[u]

where r < v means v is a strict descendant of r.

For this to be positive, we need F(u,r) + 1 > depth(u), i.e.,
the max branching value on the path from r to u must exceed depth(u) - 1.

CRUCIAL INSIGHT:
For fixed u, as r varies over ancestors of u, F(u, r) only DECREASES
(we take max over a SUBSET of edges as r moves DOWN toward u).
But depth(u) stays fixed, and S[u] stays fixed.
So gain(u, r) decreases as r moves down toward u.

This means: for each u, the BEST r (giving largest gain(u,r)) is the root of the
entire tree! But we need the answer for EACH r, maximizing over u in that subtree.

For the answer at root r:
  ans(r) = max over u in subtree(r), u!=r, of (max{h(v) : r < v <= u} + 1 - depth(u)) * S[u]

Let me define for each u:
  H(u) = max of h(v) for v on path from root (node 1) down to u, v != root.

  This is a running max that can be computed in a single DFS.

Then F(u, r) = max of h(v) for v between r and u (exclusive of r).

If r is an ancestor of u, and let c be the child of r toward u:
  F(u, r) = max(h(c), max of h(v) for v between c and u)
           = max(h(c), F(u, c))

Now, let's think about the problem differently.

For each u, define:
  gain_full(u) = (H(u) + 1 - depth(u)) * S[u]

where H(u) = max h(v) for all proper ancestors' edges on path from global root to u.

This is the gain when r = global root.

For other roots r (ancestors of u), gain(u, r) <= gain_full(u) because
F(u, r) <= H(u).

But gain(u, r) could equal gain_full(u) if the max h value is achieved
at or below r.

Let M(u) = the node v achieving the max h(v) on the path from root to u.
(i.e., h(M(u)) = H(u), and M(u) is on the path from root to u.)

Then gain(u, r) = gain_full(u) if and only if r is an ancestor of M(u) or r = M(u)...
wait, r must be a proper ancestor of M(u) since M(u) != root and we need
M(u) to be strictly between r and u.

Actually: gain(u, r) = gain_full(u) iff M(u) is in the subtree of r AND M(u) is on
the path from r to u (which it is, since M(u) is an ancestor of u, so if M(u) is
in subtree(r), then M(u) is between r and u).

So gain(u, r) = gain_full(u) iff r is an ancestor of M(u) (or r = parent of M(u), etc.)
Actually: iff M(u) is in subtree(r), which means r is an ancestor-or-equal to M(u).
But M(u) != r is needed for h(M(u)) to count. h(M(u)) is the edge from parent(M(u)) to M(u).
For this edge to be counted in F(u, r), we need parent(M(u)) >= r (meaning parent(M(u)) is
r or a descendant of r). Since M(u) is in subtree(r), parent(M(u)) is either r or also
in subtree(r). If M(u) is a child of r, then parent(M(u)) = r, and the edge (r, M(u))
is included in F(u,r). If M(u) is deeper, the edge is also included.

So: gain(u, r) = gain_full(u) iff M(u) is in subtree(r) [and u is in subtree(r), which
is given].

Since M(u) is an ancestor of u, and u is in subtree(r), we have:
- If r is an ancestor-or-equal to M(u): then M(u) is in subtree(r). gain(u,r) = gain_full(u).
- If r is a strict descendant of M(u): then M(u) is NOT in subtree(r).
  gain(u, r) < gain_full(u) (the max is achieved by a different, smaller value).

This is getting complex. Let me verify the formulas numerically and think about
what approach works for the competitive programming problem.
"""

from collections import deque
import random

def verify_h_formula(n, parents, a):
    """Verify the h-based formula."""
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

    maxdep = [0] * n
    for v in reversed(order):
        if children[v]:
            maxdep[v] = 1 + max(maxdep[c] for c in children[v])

    # top-2 for maxdep_excl
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
        if top1[v][1] == c:
            return max(0, top2[v][0])
        else:
            return max(0, top1[v][0])

    # h(v) = depth(parent(v)) + maxdep_excl(parent(v), v) for v != root
    h = [0] * n
    for v in range(1, n):
        h[v] = depth[parents[v]] + maxdep_excl(parents[v], v)

    # H(u) = max of h(v) for v on path from root to u, v != root
    # Compute via DFS
    H = [0] * n  # H[root] = 0 (no edges)

    def dfs_H(v, current_max):
        H[v] = current_max
        for c in children[v]:
            dfs_H(c, max(current_max, h[c]))

    dfs_H(0, 0)

    # gain_full(u) = (H(u) + 1 - depth(u)) * S[u]
    # This should equal gain(u, root=0) for the global root

    # Verify against brute force
    def get_subtree(v):
        result = set()
        stack = [v]
        while stack:
            x = stack.pop()
            result.add(x)
            stack.extend(children[x])
        return result

    # Check for root = 0
    sub_r = get_subtree(0)
    for u in range(1, n):
        # Brute force gain
        sub_u = get_subtree(u)
        outside = sub_r - sub_u
        D_u = max(depth[v] for v in outside)
        bf_gain = (D_u + 1 - depth[u]) * S[u]

        # Formula gain
        fm_gain = (H[u] + 1 - depth[u]) * S[u]

        if bf_gain != fm_gain:
            return False, f"Mismatch at u={u}: bf={bf_gain}, fm={fm_gain}"

    return True, "OK"

random.seed(999)
print("Verifying H-based formula for root=0:")
all_ok = True
for trial in range(5000):
    n = random.randint(2, 12)
    parents = [0]
    for i in range(1, n):
        parents.append(random.randint(0, i-1))
    a = [random.randint(0, 10) for _ in range(n)]
    ok, msg = verify_h_formula(n, parents, a)
    if not ok:
        print(f"Trial {trial}: {msg}")
        print(f"  n={n}, parents={parents}, a={a}")
        all_ok = False
        break
if all_ok:
    print("All 5000 tests passed!")

print()
print("=" * 60)
print("COMPLETE REFORMULATION")
print("=" * 60)
print("""
For each node u != root, define:
  h(u) = depth(parent(u)) + maxdep_excl(parent(u), u)

h(u) represents: "if I branch off at parent(u) away from u, the deepest I can reach
(in absolute depth terms) is h(u)."

For each node u, define:
  H(u) = max of h(v) for all v on the path from the global root to u (v != root).

H(u) = running maximum of h values along the root-to-u path.

For root r and node u in subtree(r) (u != r):
  gain(u, r) = (F(u,r) + 1 - depth(u)) * S[u]

where F(u, r) = max of h(v) for v on path from r to u (v != r, v can be u).

ANSWER for root r = base_cost(r) + max(0, max over u in subtree(r) of gain(u,r)).

Now, for an efficient solution:

OBSERVATION: F(u, r) = max of h(v) for v such that v is a descendant of r AND
v is an ancestor-or-equal-to u.

For each u, define P(u) = path from root to u = [root, v1, v2, ..., u].
h values on this path: [h(v1), h(v2), ..., h(u)].

For root r at depth d_r on this path (r = P(u)[d_r]):
  F(u, r) = max of h(P(u)[d_r+1]), ..., h(P(u)[depth(u)])
           = suffix max of h values on the path from position d_r+1 to depth(u).

So gain(u, r) = (suffix_max(d_r+1, depth(u)) + 1 - depth(u)) * S[u].

For each root r, we want:
  max over u in subtree(r) of (suffix_max on u's root-path from d_r+1 + 1 - depth(u)) * S[u]

This is tricky because different nodes u in subtree(r) have different paths.

BUT: for nodes u that are in subtree(c) where c is a child of r, the path from r to u
goes through c, and F(u, r) = max(h(c), F(u, c)).

So: gain(u, r) = max(h(c), F(u,c)) + 1 - depth(u)) * S[u]

For each child c of r, the best gain among nodes in subtree(c):
  max over u in subtree(c) of (max(h(c), F(u,c)) + 1 - depth(u)) * S[u]

= max over u in subtree(c) of max(
    (h(c) + 1 - depth(u)) * S[u],     ... when h(c) >= F(u,c)
    (F(u,c) + 1 - depth(u)) * S[u]    ... when F(u,c) > h(c)
  )

>= max over u in subtree(c) of (F(u,c) + 1 - depth(u)) * S[u]
   (this is the answer for root c)

So: answer(r) >= max over children c of r of answer(c)  (excluding base_cost differences).

Wait, not quite. Let me be more careful.

best_gain(r) = max over u in subtree(r), u!=r, of gain(u,r)
             = max over children c of r of max over u in subtree(c) of gain(u,r)

For u = c: gain(c, r) = (h(c) + 1 - depth(c)) * S[c] = (h(c) - depth(r)) * S[c]
  [since depth(c) = depth(r) + 1]

For u deeper in subtree(c):
  gain(u, r) = (max(h(c), F(u,c)) + 1 - depth(u)) * S[u]

Case A: h(c) >= F(u,c):
  gain(u, r) = (h(c) + 1 - depth(u)) * S[u]

Case B: F(u,c) > h(c):
  gain(u, r) = (F(u,c) + 1 - depth(u)) * S[u] = gain(u, c)

So gain(u, r) = max(gain(u, c), (h(c) + 1 - depth(u)) * S[u])

And best_gain(r, through c) = max(
    gain(c, r),
    max over u in subtree(c), u!=c, of max(gain(u, c), (h(c) + 1 - depth(u)) * S[u])
)

= max(
    (h(c) - depth(r)) * S[c],
    best_gain(c),   ... from gain(u,c) terms
    max over u in subtree(c), u!=c, of (h(c) + 1 - depth(u)) * S[u]   ... from h(c) terms
)

The third term: (h(c) + 1) * S[u] - depth(u) * S[u], maximized over u in subtree(c), u!=c.
Since h(c) + 1 is a constant (for fixed c), this is:
  (h(c) + 1) * S[u_best] - depth(u_best) * S[u_best]
  = S[u_best] * (h(c) + 1 - depth(u_best))

where u_best maximizes (h(c) + 1 - depth(u)) * S[u] = (constant - depth(u)) * S[u].

Hmm wait, h(c) + 1 could be positive or negative relative to depth(u).
If h(c) + 1 > depth(u), this is positive. We want to maximize it.

This is: maximize S[u] * (K - depth(u)) over u in subtree(c), u != c, where K = h(c) + 1.

This requires knowing for each subtree, the node u maximizing S[u] * (K - depth(u)).
Since K varies per query, this isn't a simple precomputable quantity.

Hmm, but K = h(c) + 1, and c is the child of r, so for each edge (r, c), K is fixed.

This is getting complicated. Let me think about whether there's a simpler characterization.
""")

# Let me look at this from a different angle: what if we enumerate over edges?
#
# When we detach u and reattach to the deepest node, the effective operation is:
# "pick an edge (parent(u), u) in subtree(r), remove subtree(u), reattach at deepest
#  remaining node."
#
# The gain is determined by:
# 1. The subtree sum S[u] being moved
# 2. The depth change = (new depth of u) - (old depth of u)
#    = (D(u) + 1) - depth_r(u)
#    = (max depth in remaining + 1) - depth_r(u)
#
# For this to be beneficial, the "deepest remaining" must be deeper than "current depth - 1".

# Let me try to think about what the problem constraints might be and what
# complexity is needed.

# For now, let me code the O(n^2) solution cleanly and verify it, which is likely
# sufficient for n <= 5000.

def solve_clean(n, parents, a, root=0):
    """Clean O(n^2) solution for all roots."""
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

    maxdep = [0] * n
    for v in reversed(order):
        if children[v]:
            maxdep[v] = 1 + max(maxdep[c] for c in children[v])

    # h(v) for each v
    top1_val = [-1] * n
    top1_child = [-1] * n
    top2_val = [-1] * n
    for v in order:
        best_v, best_c = -1, -1
        sec_v = -1
        for c in children[v]:
            val = 1 + maxdep[c]
            if val > best_v:
                sec_v = best_v
                best_v, best_c = val, c
            elif val > sec_v:
                sec_v = val
        top1_val[v] = best_v
        top1_child[v] = best_c
        top2_val[v] = sec_v

    def maxdep_excl(v, c):
        if top1_child[v] == c:
            return max(0, top2_val[v])
        else:
            return max(0, top1_val[v])

    h = [0] * n
    for v in range(1, n):
        h[v] = depth[parents[v]] + maxdep_excl(parents[v], v)

    # For each root r, DFS its subtree, maintaining running max of h values
    results = []
    for r in range(n):
        base_cost = 0
        best_gain = 0

        # DFS through subtree of r, tracking running max of h
        stack = [(r, 0)]  # (node, current_max_h along path from r)
        while stack:
            v, max_h = stack.pop()
            base_cost += a[v] * (depth[v] - depth[r])

            if v != r:
                cur_h = max(max_h, h[v])
                gain = (cur_h + 1 - depth[v]) * S[v]
                if gain > best_gain:
                    best_gain = gain
            else:
                cur_h = 0

            for c in children[v]:
                if v == r:
                    stack.append((c, h[c]))
                else:
                    stack.append((c, max(cur_h, h[c])))

        results.append(base_cost + best_gain)

    return results

# Verify against brute force
random.seed(111)
print("\nVerifying clean O(n^2) solution:")
all_ok = True
for trial in range(2000):
    n = random.randint(2, 10)
    parents = [0]
    for i in range(1, n):
        parents.append(random.randint(0, i-1))
    a = [random.randint(0, 10) for _ in range(n)]

    bf = []
    # brute force
    children_bf = [[] for _ in range(n)]
    for i in range(1, n):
        children_bf[parents[i]].append(i)

    depth_bf = [0] * n
    q = deque([0])
    ord_bf = []
    while q:
        v = q.popleft()
        ord_bf.append(v)
        for c in children_bf[v]:
            depth_bf[c] = depth_bf[v] + 1
            q.append(c)

    S_bf = [0] * n
    for v in reversed(ord_bf):
        S_bf[v] = a[v] + sum(S_bf[c] for c in children_bf[v])

    def get_sub(v):
        res = set()
        stk = [v]
        while stk:
            x = stk.pop()
            res.add(x)
            stk.extend(children_bf[x])
        return res

    for r in range(n):
        sub_r = get_sub(r)
        bc = sum(a[v] * (depth_bf[v] - depth_bf[r]) for v in sub_r)
        bg = 0
        for u in sub_r:
            if u == r:
                continue
            sub_u = get_sub(u)
            outside = sub_r - sub_u
            D_u = max(depth_bf[v] - depth_bf[r] for v in outside)
            gain = (D_u + 1 - (depth_bf[u] - depth_bf[r])) * S_bf[u]
            bg = max(bg, gain)
        bf.append(bc + bg)

    fm = solve_clean(n, parents, a)

    if bf != fm:
        print(f"MISMATCH at trial {trial}!")
        print(f"  n={n}, parents={parents}, a={a}")
        print(f"  BF: {bf}")
        print(f"  FM: {fm}")
        all_ok = False
        break

if all_ok:
    print("All 2000 tests passed! Clean O(n^2) is correct.")
