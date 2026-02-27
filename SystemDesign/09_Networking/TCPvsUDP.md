# TCP vs UDP

## Comparison
| Feature | TCP | UDP |
|---------|-----|-----|
| Connection | Connection-oriented (3-way handshake) | Connectionless |
| Reliability | Guaranteed delivery, ordering | No guarantees |
| Speed | Slower (overhead) | Faster (no overhead) |
| Flow Control | Yes | No |
| Congestion Control | Yes | No |
| Header Size | 20+ bytes | 8 bytes |
| Use Case | Web, email, file transfer | Gaming, streaming, DNS |

## Key Points
- **TCP**: Reliable, ordered, connection-oriented. Use when data integrity matters.
- **UDP**: Fast, unreliable, connectionless. Use when speed matters more than reliability.
- HTTP/1.1 and HTTP/2 use TCP; HTTP/3 uses QUIC (built on UDP)
- Most system design answers involve TCP (HTTP-based services)
- WebSocket starts as HTTP (TCP) then upgrades to persistent connection

## When to Use
- **TCP**: APIs, web apps, file uploads, database connections, email
- **UDP**: Video streaming, online gaming, VoIP, DNS queries, IoT sensors

## Interview Tips
- Most system design: TCP (everything is HTTP-based)
- "For real-time video, UDP to minimize latency — dropped frames are better than delayed ones"
- Know that HTTP/3 uses QUIC (UDP-based) for better performance

## Best Articles
- [TCP vs UDP - Cloudflare](https://www.cloudflare.com/learning/ddos/glossary/tcp-ip/)
- [QUIC Protocol Explained](https://blog.bytebytego.com/p/http3-quic)
