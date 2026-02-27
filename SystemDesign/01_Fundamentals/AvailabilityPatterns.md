# Availability Patterns

## What is it?
Strategies to keep a system operational even when components fail.

### 1. Active-Passive (Failover)
- One active server handles traffic, passive server on standby
- On failure, passive takes over (automatic or manual)
- Downtime during switchover (seconds to minutes)
- Example: Traditional database HA (primary-standby)

### 2. Active-Active (Multi-Master)
- Multiple servers handle traffic simultaneously
- Load is distributed; any server can handle requests
- More complex (conflict resolution needed)
- Example: DNS round-robin, multi-region deployments

### 3. Replication
- Data is copied across multiple nodes
- **Leader-Follower**: One writes, others read
- **Multi-Leader**: Multiple nodes accept writes
- **Leaderless**: Any node reads/writes (Dynamo-style)

## Key Points
- Availability is measured in "nines": 99.9% = 8.7h downtime/year, 99.99% = 52min/year
- Higher availability = more redundancy = more cost
- Use health checks to detect failures automatically
- Circuit breakers prevent cascading failures

## Availability Table
| Level | Downtime/Year | Example |
|-------|--------------|---------|
| 99% (two 9s) | 3.65 days | Internal tools |
| 99.9% (three 9s) | 8.76 hours | Business apps |
| 99.99% (four 9s) | 52.6 minutes | E-commerce |
| 99.999% (five 9s) | 5.26 minutes | Banking, AWS |

## When to Use
- **Active-Passive**: Databases, simple failover needs
- **Active-Active**: Global apps, multi-region deployments, high-traffic systems

## Trade-offs
| Active-Passive | Active-Active |
|---------------|--------------|
| Simple setup | Complex (conflict resolution) |
| Wasted standby resources | Better resource usage |
| Some downtime on failover | Near-zero downtime |

## Interview Tips
- Always state your availability target (e.g., "We need four 9s for this system")
- Mention how you'd achieve it: replication, load balancing, health checks
- Know the math: if two services are 99.9%, combined = 99.8%

## Best Articles
- [System Design Primer - Availability](https://github.com/donnemartin/system-design-primer#availability-patterns)
- [High Availability Architecture](https://docs.aws.amazon.com/whitepapers/latest/real-time-communication-on-aws/high-availability-and-scalability-on-aws.html)
