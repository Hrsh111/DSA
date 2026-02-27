# Load Balancer Types - L4 vs L7

## What is it?
A load balancer distributes incoming traffic across multiple servers. Named by the OSI layer they operate at.

### Layer 4 (Transport Layer)
- Routes based on **IP address and port** (TCP/UDP level)
- Doesn't inspect packet content — just forwards connections
- Faster, less CPU-intensive
- Example: AWS NLB, HAProxy (TCP mode)

### Layer 7 (Application Layer)
- Routes based on **HTTP content**: URL path, headers, cookies, body
- Can do: path-based routing, A/B testing, SSL termination
- Slower but much more flexible
- Example: AWS ALB, Nginx, HAProxy (HTTP mode)

## Comparison
| Feature | L4 | L7 |
|---------|----|----|
| Speed | Faster | Slower |
| Intelligence | Dumb (IP+port) | Smart (URL, headers, cookies) |
| SSL Termination | No (pass-through) | Yes |
| WebSocket Support | Yes (pass-through) | Yes (with inspection) |
| Cost | Cheaper | More expensive |
| Use Case | TCP/UDP services, gaming | HTTP APIs, web apps |

## When to Use
- **L4**: High-performance TCP services, database proxying, gaming servers, simple round-robin
- **L7**: REST APIs, microservices (route /api/users to user service), A/B testing, rate limiting

## Interview Tips
- "We'd use an L7 load balancer (ALB) for our API to route based on URL paths to different microservices"
- "For raw TCP performance, an L4 NLB in front of the L7 layer"
- Most system design answers = L7 load balancer

## Best Articles
- [L4 vs L7 Load Balancing](https://www.nginx.com/resources/glossary/layer-4-load-balancing/)
- [AWS ALB vs NLB](https://docs.aws.amazon.com/elasticloadbalancing/latest/userguide/how-elastic-load-balancing-works.html)
