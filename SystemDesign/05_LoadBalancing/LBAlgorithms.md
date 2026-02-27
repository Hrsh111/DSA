# Load Balancing Algorithms

## Algorithms

### 1. Round Robin
- Rotate through servers sequentially: A → B → C → A → B → C
- Simple, works when all servers are equal
- Doesn't account for server load differences

### 2. Weighted Round Robin
- Assign weights: A(3), B(2), C(1) → A gets 3x traffic of C
- Good when servers have different capacities

### 3. Least Connections
- Route to server with fewest active connections
- Best for long-lived connections (WebSockets)
- Adapts to slow servers naturally

### 4. Least Response Time
- Route to server with fastest response + fewest connections
- Best for heterogeneous server performance

### 5. IP Hash
- Hash client IP → always routes to same server
- Provides session affinity (sticky sessions)
- Problem: one server failure remaps many clients

### 6. Consistent Hashing
- Better version of IP Hash — minimal remapping on server changes
- Used by: CDNs, distributed caches

### 7. Random
- Pick a random server
- Surprisingly effective with large server pools

## Key Points
- **Round Robin** is the default for most stateless services
- **Least Connections** for WebSocket/long-lived connections
- **IP Hash** when you need session affinity (but prefer stateless design)
- Health checks remove unhealthy servers from the pool

## When to Use
| Algorithm | Best For |
|-----------|---------|
| Round Robin | Stateless APIs, equal servers |
| Weighted | Mixed server capacities |
| Least Connections | WebSockets, long requests |
| IP Hash | Session affinity (avoid if possible) |

## Interview Tips
- Default: "Round robin with health checks for our stateless API servers"
- If sessions needed: "Prefer externalized sessions in Redis over sticky sessions"

## Best Articles
- [Load Balancing Algorithms](https://samwho.dev/load-balancing/)
- [Nginx Load Balancing Guide](https://docs.nginx.com/nginx/admin-guide/load-balancer/http-load-balancer/)
