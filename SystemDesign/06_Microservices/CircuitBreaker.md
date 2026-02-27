# Circuit Breaker Pattern

## What is it?
Prevents cascading failures in distributed systems. Like an electrical circuit breaker — if a downstream service is failing, stop sending requests to it temporarily.

## States
```
[CLOSED] → failures exceed threshold → [OPEN] → timeout → [HALF-OPEN] → success → [CLOSED]
                                                          → failure → [OPEN]
```

1. **Closed**: Normal operation. Requests pass through. Track failure count.
2. **Open**: Service is failing. Requests immediately fail (fast-fail) without calling the service. Return fallback response.
3. **Half-Open**: After timeout, allow a few test requests. If they succeed → close. If they fail → open again.

## Key Points
- Prevents one failing service from taking down the entire system
- Provides fast failure instead of slow timeouts
- Fallback: return cached data, default value, or graceful error
- Configure: failure threshold, timeout duration, number of test requests in half-open
- Implementations: Hystrix (Netflix, deprecated), Resilience4j (Java), Polly (.NET)

## When to Use
- Any service-to-service call in microservices
- External API calls (payment gateways, third-party APIs)
- Database connections that might timeout

## Trade-offs
| Pros | Cons |
|------|------|
| Prevents cascading failures | Added complexity |
| Fast failure response | May reject valid requests during recovery |
| Self-healing (half-open state) | Need meaningful fallbacks |

## Interview Tips
- "Circuit breaker on all inter-service calls to prevent cascading failures"
- "If payment service is down, circuit opens and we return 'try again later' instead of timing out for 30 seconds"
- Pair with: retries (with backoff), timeouts, bulkhead pattern

## Best Articles
- [Circuit Breaker - Martin Fowler](https://martinfowler.com/bliki/CircuitBreaker.html)
- [Resilience4j Documentation](https://resilience4j.readme.io/docs/circuitbreaker)
