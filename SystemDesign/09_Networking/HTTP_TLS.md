# HTTP/HTTPS and TLS

## HTTP Versions
| Version | Key Feature |
|---------|------------|
| HTTP/1.0 | One request per connection |
| HTTP/1.1 | Persistent connections, pipelining |
| HTTP/2 | Multiplexing (multiple requests on one connection), binary, header compression |
| HTTP/3 | QUIC (UDP-based), faster connection setup, better on lossy networks |

## TLS (Transport Layer Security)
- Encrypts data in transit (HTTPS = HTTP + TLS)
- TLS Handshake: Client Hello → Server Hello + Certificate → Key Exchange → Encrypted Communication
- TLS 1.3: Faster handshake (1-RTT vs 2-RTT in TLS 1.2)
- SSL termination at load balancer: decrypt at LB, forward plain HTTP internally

## Key Points
- Always use HTTPS in production (encrypt everything)
- HTTP/2 is standard now — multiplexing eliminates head-of-line blocking
- HTTP/3 gaining adoption (Cloudflare, Google already use it)
- SSL/TLS certificates: Let's Encrypt (free), or AWS ACM
- mTLS (mutual TLS): both client and server authenticate — used in service mesh

## Interview Tips
- "HTTPS everywhere. SSL termination at the load balancer, plain HTTP between internal services"
- "HTTP/2 between client and server for multiplexing"
- For service mesh: "mTLS between microservices for zero-trust security"

## Best Articles
- [HTTP/1 vs 2 vs 3 - ByteByteGo](https://blog.bytebytego.com/p/http1-vs-http2-vs-http3)
- [TLS Handshake Explained](https://www.cloudflare.com/learning/ssl/what-happens-in-a-tls-handshake/)
