# Reverse Proxy

## What is it?
A server that sits in front of your backend servers and forwards client requests to them. The client only talks to the proxy, not directly to backend servers.

```
Client → [Reverse Proxy (Nginx)] → Server A
                                  → Server B
                                  → Server C
```

## Forward Proxy vs Reverse Proxy
| Forward Proxy | Reverse Proxy |
|--------------|--------------|
| Sits in front of **clients** | Sits in front of **servers** |
| Hides client identity | Hides server identity |
| Client knows it's using proxy | Client doesn't know about backends |
| Example: VPN, corporate proxy | Example: Nginx, AWS ALB |

## What it Does
- **Load balancing**: Distribute traffic across servers
- **SSL termination**: Handle HTTPS, forward HTTP to backends
- **Caching**: Cache responses, reduce backend load
- **Compression**: gzip responses before sending to client
- **Security**: Hide backend IPs, rate limiting, DDoS protection
- **Static file serving**: Serve images/CSS/JS without hitting backend

## Key Points
- Nginx and HAProxy are the most popular reverse proxies
- Almost every production web app uses a reverse proxy
- Single point of failure → run multiple instances with failover
- Can also do: A/B testing, canary deployments, request routing

## When to Use
- Always. Every production web application should have one.

## Interview Tips
- "Nginx as a reverse proxy in front of our app servers for SSL termination, load balancing, and static file serving"
- Mention it provides a single entry point for the system

## Best Articles
- [What is a Reverse Proxy? - Cloudflare](https://www.cloudflare.com/learning/cdn/glossary/reverse-proxy/)
- [Nginx Reverse Proxy Guide](https://docs.nginx.com/nginx/admin-guide/web-server/reverse-proxy/)
