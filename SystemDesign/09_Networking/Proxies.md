# Proxies - Forward vs Reverse

## Forward Proxy
- Sits in front of **clients**
- Client → Forward Proxy → Internet → Server
- Server doesn't know the real client
- Use cases: VPN, corporate firewall, anonymity, bypass geo-restrictions

## Reverse Proxy
- Sits in front of **servers**
- Client → Internet → Reverse Proxy → Server A/B/C
- Client doesn't know which server handles the request
- Use cases: Load balancing, SSL termination, caching, DDoS protection

## Comparison
| Feature | Forward Proxy | Reverse Proxy |
|---------|--------------|--------------|
| Protects | Clients | Servers |
| Client aware? | Yes | No |
| Server aware? | No | Yes |
| Example | VPN, Squid | Nginx, HAProxy, AWS ALB |

## Key Points
- In system design, you almost always mean **reverse proxy**
- Nginx is the most popular reverse proxy
- Reverse proxy = load balancer + SSL terminator + cacher + security layer

## Interview Tips
- "Nginx reverse proxy in front of our services — handles SSL, load balancing, and rate limiting"
- If someone says "proxy" in system design, they usually mean reverse proxy

## Best Articles
- [Forward vs Reverse Proxy - Cloudflare](https://www.cloudflare.com/learning/cdn/glossary/reverse-proxy/)
- [Nginx as Reverse Proxy](https://docs.nginx.com/nginx/admin-guide/web-server/reverse-proxy/)
