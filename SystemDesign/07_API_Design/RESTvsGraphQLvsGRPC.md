# REST vs GraphQL vs gRPC

## Comparison
| Feature | REST | GraphQL | gRPC |
|---------|------|---------|------|
| Protocol | HTTP | HTTP | HTTP/2 |
| Data Format | JSON | JSON | Protobuf (binary) |
| Schema | OpenAPI/Swagger | SDL (strongly typed) | .proto files |
| Over/Under-fetching | Common problem | Solved (client picks fields) | Fixed by proto definition |
| Real-time | Polling/WebSocket | Subscriptions | Bidirectional streaming |
| Caching | Easy (HTTP caching) | Hard (POST requests) | Hard |
| Best For | Public APIs, CRUD | Mobile apps, flexible queries | Internal microservice comms |

## Key Points
- **REST**: Standard for public APIs. Simple, well-understood, cacheable. Problem: over/under-fetching.
- **GraphQL**: Client requests exactly the fields it needs. Great for mobile (bandwidth). One endpoint. Complex server-side.
- **gRPC**: Binary protocol, very fast. Strongly typed with protobuf. Best for internal service-to-service. Not browser-friendly.
- Most large systems use **REST for external** + **gRPC for internal** communication

## When to Use
- **REST**: Public APIs, simple CRUD, when HTTP caching matters
- **GraphQL**: Mobile apps, dashboard UIs needing flexible data from multiple sources
- **gRPC**: Microservice communication, low-latency internal APIs, streaming

## Interview Tips
- "REST API for external clients (simple, cacheable), gRPC between internal microservices (fast, typed)"
- If mobile is important: "GraphQL to let mobile clients request only needed fields, reducing bandwidth"

## Best Articles
- [ByteByteGo: REST vs GraphQL vs gRPC](https://blog.bytebytego.com/p/rest-vs-graphql-vs-grpc)
- [gRPC Documentation](https://grpc.io/docs/)
- [GraphQL Official](https://graphql.org/learn/)
