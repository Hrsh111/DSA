# Service Discovery

## What is it?
How services find each other in a microservices architecture where instances are dynamic (scaling, restarting, new deployments).

## Types
### 1. Client-Side Discovery
- Client queries a **service registry** to get available instances
- Client picks one (with load balancing logic)
- Example: Netflix Eureka + Ribbon

### 2. Server-Side Discovery
- Client sends request to a **load balancer/router**
- Router queries registry and forwards request
- Example: AWS ALB, Kubernetes Services

## Service Registry
- Database of available service instances and their locations
- Services register on startup, deregister on shutdown
- Health checks remove dead instances
- Examples: Consul, etcd, ZooKeeper, Eureka

## Key Points
- In Kubernetes: built-in service discovery via DNS (service-name.namespace.svc.cluster.local)
- Without K8s: use Consul or Eureka
- DNS-based: simple but slow to update (TTL caching)
- Registry-based: faster but more infrastructure

## Interview Tips
- "In a Kubernetes environment, we'd use the built-in service discovery via kube-dns"
- "For non-K8s: Consul for service registry with health checks"
- Most interviewers are happy with: "API Gateway + service registry"

## Best Articles
- [Service Discovery Pattern](https://microservices.io/patterns/server-side-discovery.html)
- [Consul Service Discovery](https://developer.hashicorp.com/consul/docs/concepts/service-discovery)
