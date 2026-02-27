"""
Verify whether detaching a child of r is always optimal.

Tree structure (rooted at r=0):
  r has children c1, c2.
  c1 has children: branch_deep (a long chain) and u (a single node with huge value).
  c2 is a leaf (shallow).

Goal: make detaching u (grandchild of r, depth 2) better than detaching any child of r.

Construction:
  r (node 0)
  ├── c1 (node 1), a[c1] = 1
  │   ├── chain: node 3 -> node 4 -> ... -> node (3+L-1), all a=1  (depth from r: 2,3,...,L+1)
  │   └── u (node 2), a[u] = W  (depth from r: 2)
  └── c2 (node 3+L), a[c2] = 1  (depth from r: 1)

Parameters: L = chain length (making M1 = L+1 large), W = weight of u (making S[u] large).

Let's compute:
  M1 = L + 1  (max depth under c1)
  M2 = 1      (max depth under c2, just c2 itself)
  S[c1] = 1 + L + W = L + W + 1
  S[c2] = 1
  S[u]  = W

Detach c1: gain = D(c1) * S[c1] = M2 * S[c1] = 1 * (L + W + 1) = L + W + 1
Detach c2: gain = D(c2) * S[c2] = M1 * S[c2] = (L+1) * 1 = L + 1
Detach u (depth 2):
  After removing subtree(u) = {u}, reachable = {r, c1, chain nodes, c2}.
  Max depth in reachable = M1 = L+1 (chain is still there!).
  D(u) = L + 1
  gain = (D(u) + 1 - 2) * S[u] = L * W

Compare:
  gain(c1) = L + W + 1
  gain(c2) = L + 1
  gain(u)  = L * W

For L=100, W=1000:
  gain(c1) = 100 + 1000 + 1 = 1101
  gain(c2) = 101
  gain(u)  = 100 * 1000 = 100000

gain(u) >> gain(c1)!  COUNTEREXAMPLE FOUND!
"""

def compute_gains(L, W):
    """
    Tree structure:
    - r (node 0), a=0 (doesn't matter, depth 0)
    - c1 (node 1), a=1, child of r, depth 1
    - u (node 2), a=W, child of c1, depth 2
    - chain: nodes 3..3+L-1, a=1 each, children forming chain under c1
      node 3 is child of c1 (depth 2), node 4 is child of node 3 (depth 3), etc.
      node 3+L-1 is at depth L+1 from r
    - c2 (node 3+L), a=1, child of r, depth 1
    """

    n = 3 + L + 1  # total nodes: r, c1, u, L chain nodes, c2
    parent = [0] * n
    a = [0] * n
    depth = [0] * n
    children = [[] for _ in range(n)]

    # r = 0
    a[0] = 0
    depth[0] = 0

    # c1 = 1, child of r
    parent[1] = 0
    a[1] = 1
    depth[1] = 1
    children[0].append(1)

    # u = 2, child of c1
    parent[2] = 1
    a[2] = W
    depth[2] = 2
    children[1].append(2)

    # chain: node 3 is child of c1, node 4 is child of node 3, etc.
    if L > 0:
        parent[3] = 1
        a[3] = 1
        depth[3] = 2
        children[1].append(3)
        for i in range(1, L):
            node = 3 + i
            parent[node] = 3 + i - 1
            a[node] = 1
            depth[node] = 2 + i
            children[3 + i - 1].append(node)

    # c2 = 3+L, child of r
    c2 = 3 + L
    parent[c2] = 0
    a[c2] = 1
    depth[c2] = 1
    children[0].append(c2)

    # Compute subtree sums
    # BFS order (reverse for bottom-up)
    from collections import deque
    order = []
    q = deque([0])
    while q:
        v = q.popleft()
        order.append(v)
        for c in children[v]:
            q.append(c)

    S = [0] * n
    for v in reversed(order):
        S[v] = a[v] + sum(S[c] for c in children[v])

    # Base cost C[r] = sum(a[v] * depth[v])
    base_cost = sum(a[v] * depth[v] for v in range(n))

    # For each possible detach node u_det (u_det != r=0), compute gain
    # gain = (D(u_det) + 1 - depth[u_det]) * S[u_det]
    # where D(u_det) = max depth among nodes NOT in subtree(u_det)

    # First, compute subtree membership
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
    results = {}

    for u_det in range(1, n):
        sub_u = get_subtree(u_det)
        outside = [v for v in range(n) if v not in sub_u]
        D_u = max(depth[v] for v in outside)
        gain = (D_u + 1 - depth[u_det]) * S[u_det]
        results[u_det] = {
            'depth': depth[u_det],
            'S': S[u_det],
            'D': D_u,
            'gain': gain,
            'is_child_of_r': (parent[u_det] == 0)
        }
        if gain > best_gain:
            best_gain = gain
            best_node = u_det

    return base_cost, results, best_gain, best_node

print("=" * 60)
print("COUNTEREXAMPLE SEARCH")
print("=" * 60)

for L, W in [(10, 100), (100, 1000), (50, 500), (5, 20)]:
    print(f"\n--- L={L}, W={W} ---")
    base_cost, results, best_gain, best_node = compute_gains(L, W)

    # Show gains for children of r and for node u (node 2)
    print(f"Base cost: {base_cost}")

    # Children of r
    children_gains = {k: v for k, v in results.items() if v['is_child_of_r']}
    best_child_gain = max(v['gain'] for v in children_gains.values())

    print("Children of r:")
    for node, info in sorted(children_gains.items()):
        print(f"  Node {node}: depth={info['depth']}, S={info['S']}, D={info['D']}, gain={info['gain']}")

    print(f"\nNode u=2 (grandchild): depth={results[2]['depth']}, S={results[2]['S']}, D={results[2]['D']}, gain={results[2]['gain']}")

    print(f"\nBest child gain: {best_child_gain}")
    print(f"Best overall gain: {best_gain} (node {best_node}, is_child={results[best_node]['is_child_of_r']})")

    if best_gain > best_child_gain:
        print(f"*** COUNTEREXAMPLE FOUND! Non-child node {best_node} beats all children! ***")
        print(f"    Improvement: {best_gain - best_child_gain} ({best_gain / best_child_gain:.2f}x)")
    else:
        print("Claim holds for this case.")

print("\n" + "=" * 60)
print("BRUTE FORCE CHECK ON SMALL TREES")
print("=" * 60)

import itertools

def brute_force_all_trees(max_n=7):
    """Check all possible trees up to max_n nodes."""
    counterexamples = 0
    trees_checked = 0

    for n in range(2, max_n + 1):
        # Generate all possible rooted trees on n nodes (root = 0)
        # Each node i>0 has parent in 0..i-1 (Prufer-like enumeration)
        # Also try different weight assignments

        # For efficiency, try random weight assignments
        import random
        random.seed(42)

        parent_choices = [range(i) for i in range(1, n)]

        for parents_tuple in itertools.product(*parent_choices):
            parents = [0] + list(parents_tuple)  # parent[0] = 0 (unused)

            children = [[] for _ in range(n)]
            for i in range(1, n):
                children[parents[i]].append(i)

            # Try several weight assignments
            weight_sets = [
                [0] + [1] * (n - 1),
                [0] + list(range(1, n)),
                [0] + [1] * (n - 1),
            ]
            # Add some random weight sets
            for _ in range(5):
                weight_sets.append([0] + [random.randint(1, 100) for _ in range(n - 1)])

            for weights in weight_sets:
                a = weights
                trees_checked += 1

                # Compute depths
                depth = [0] * n
                from collections import deque
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

                best_child_gain = 0
                best_overall_gain = 0
                best_overall_node = -1

                for u_det in range(1, n):
                    sub_u = get_subtree(u_det)
                    outside = [v for v in range(n) if v not in sub_u]
                    if not outside:
                        continue
                    D_u = max(depth[v] for v in outside)
                    gain = (D_u + 1 - depth[u_det]) * S[u_det]

                    if parents[u_det] == 0:  # child of root
                        best_child_gain = max(best_child_gain, gain)

                    if gain > best_overall_gain:
                        best_overall_gain = gain
                        best_overall_node = u_det

                if best_overall_gain > best_child_gain and best_overall_node != -1 and parents[best_overall_node] != 0:
                    counterexamples += 1
                    if counterexamples <= 5:
                        print(f"\nCounterexample #{counterexamples}:")
                        print(f"  n={n}, parents={parents}, weights={a}")
                        print(f"  Best child gain: {best_child_gain}")
                        print(f"  Best overall: gain={best_overall_gain}, node={best_overall_node} (depth {depth[best_overall_node]})")
                        # Show all gains
                        for u_det in range(1, n):
                            sub_u = get_subtree(u_det)
                            outside = [v for v in range(n) if v not in sub_u]
                            if not outside:
                                continue
                            D_u = max(depth[v] for v in outside)
                            gain = (D_u + 1 - depth[u_det]) * S[u_det]
                            marker = " <-- BEST" if u_det == best_overall_node else (" (child)" if parents[u_det] == 0 else "")
                            print(f"    Detach node {u_det}: depth={depth[u_det]}, S={S[u_det]}, D={D_u}, gain={gain}{marker}")

    print(f"\nTotal trees checked: {trees_checked}")
    print(f"Total counterexamples: {counterexamples}")

brute_force_all_trees(7)
