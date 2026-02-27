# API Gateway

## What is it?
A single entry point for all client requests. Routes requests to appropriate microservices, handles cross-cutting concerns.

```
Client → [API Gateway] → /users   → User Service
                       → /orders  → Order Service
                       → /search  → Search Service
```

## Responsibilities
- **Request routing**: Route to correct microservice based on URL/path
- **Authentication/Authorization**: Verify JWT tokens, API keys
- **Rate limiting**: Throttle requests per client
- **Load balancing**: Distribute across service instances
- **SSL termination**: Handle HTTPS
- **Request/Response transformation**: Aggregate responses from multiple services
- **Caching**: Cache common responses
- **Logging/Monitoring**: Centralized request logging

## Key Points
- Single point of failure → must be highly available (multiple instances)
- BFF pattern (Backend for Frontend): different gateways for mobile/web/third-party
- Don't put business logic in the gateway — keep it thin
- Popular: Kong, AWS API Gateway, Nginx, Zuul, Envoy

## When to Use
- Any microservices architecture
- When clients shouldn't know about internal service topology
- When you need centralized auth, rate limiting, logging

## Trade-offs
| Pros | Cons |
|------|------|
| Single entry point | Single point of failure |
| Centralized cross-cutting concerns | Added latency (extra hop) |
| Hides internal architecture | Can become bottleneck |
| Protocol translation | Must be updated for new services |

## Interview Tips
- "API Gateway as the single entry point — handles auth, rate limiting, and routes to microservices"
- Mention BFF if designing for multiple clients: "Separate gateway for mobile (less data) and web (more data)"

## Best Articles
- [API Gateway Pattern](https://microservices.io/patterns/apigateway.html)
- [Kong API Gateway](https://konghq.com/learning-center/api-gateway/what-is-an-api-gateway)
- [ByteByteGo: API Gateway](https://blog.bytebytego.com/p/ep47-api-gateway)
