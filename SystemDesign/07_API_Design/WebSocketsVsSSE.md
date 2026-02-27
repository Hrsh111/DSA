# WebSockets vs SSE vs Polling

## Comparison
| Feature | Polling | Long Polling | SSE | WebSocket |
|---------|---------|-------------|-----|-----------|
| Direction | Client → Server | Client → Server | Server → Client | Bidirectional |
| Connection | New per request | Held open | Persistent | Persistent |
| Overhead | High (repeated requests) | Medium | Low | Lowest |
| Complexity | Simple | Medium | Simple | Complex |
| Protocol | HTTP | HTTP | HTTP | WS (upgrade from HTTP) |

## Key Points
- **Polling**: Client repeatedly asks "any updates?" every N seconds. Simple but wasteful.
- **Long Polling**: Client sends request, server holds it until data is available. Better but still one-directional.
- **SSE (Server-Sent Events)**: Server pushes updates over a persistent HTTP connection. Unidirectional (server → client only). Auto-reconnect built in.
- **WebSocket**: Full-duplex, persistent connection. Both sides can send at any time. Best for interactive real-time apps.

## When to Use
| Technology | Use Case |
|-----------|---------|
| Polling | Simple dashboards, low-frequency updates |
| Long Polling | Notifications when WebSocket isn't available |
| SSE | Live feeds, stock tickers, notifications (server → client) |
| WebSocket | Chat apps, gaming, collaborative editing, trading |

## Interview Tips
- Chat/messaging: "WebSocket for bidirectional real-time communication"
- Notifications/feeds: "SSE is simpler and sufficient since data only flows server → client"
- "We'd fall back to long polling for clients that don't support WebSocket"

## Best Articles
- [WebSockets vs SSE - ByteByteGo](https://blog.bytebytego.com/p/websocket-vs-sse)
- [MDN: Server-Sent Events](https://developer.mozilla.org/en-US/docs/Web/API/Server-sent_events)
- [MDN: WebSocket API](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API)
