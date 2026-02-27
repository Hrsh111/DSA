# Health Checks and Failover

## What is it?
Mechanisms to detect when a server is unhealthy and automatically route traffic away from it.

## Types of Health Checks
### 1. Active Health Checks
- Load balancer periodically pings servers (e.g., GET /health every 10s)
- If server fails N consecutive checks → marked unhealthy, removed from pool
- When it starts passing again → added back

### 2. Passive Health Checks
- Monitor real traffic — if a server returns errors/timeouts, mark unhealthy
- No extra requests needed
- Faster detection but can affect real users

## Health Check Endpoint
```
GET /health → 200 OK
{
  "status": "healthy",
  "db": "connected",
  "cache": "connected",
  "uptime": "5d 3h"
}
```

## Failover Patterns
- **Active-Passive**: Standby server takes over when primary fails
- **Active-Active**: Multiple servers handle traffic; failed one is removed from pool
- **DNS Failover**: Update DNS to point to healthy servers (slow — DNS TTL)
- **Database Failover**: Promote replica to primary on leader failure

## Key Points
- Health checks should be **lightweight** (don't query DB on every check)
- Deep health check: verify dependencies (DB, cache, external APIs)
- Shallow health check: just verify the process is running
- Grace period: don't mark server unhealthy for one failed check
- Circuit breaker pattern: stop sending requests to a failing service

## Interview Tips
- "Load balancer does active health checks every 10 seconds. Three consecutive failures marks a server unhealthy"
- "Each service exposes a /health endpoint that checks DB connectivity"
- Mention automatic recovery: "When the server recovers, health checks pass and it's added back"

## Best Articles
- [Health Check Pattern - Microsoft](https://learn.microsoft.com/en-us/azure/architecture/patterns/health-endpoint-monitoring)
- [AWS ELB Health Checks](https://docs.aws.amazon.com/elasticloadbalancing/latest/application/target-group-health-checks.html)
