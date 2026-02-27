# Latency vs Throughput

## What is it?
- **Latency**: Time to complete a single request (ms). "How fast?"
- **Throughput**: Number of requests handled per unit time (req/sec). "How much?"

They are often in tension — optimizing one can hurt the other.

## Key Points
- **Low latency** matters for: real-time apps, gaming, trading, search autocomplete
- **High throughput** matters for: batch processing, data pipelines, video encoding
- Batching improves throughput but increases latency (wait to fill the batch)
- Caching reduces latency but doesn't directly increase throughput
- Parallelism increases throughput but may not help latency

## Latency Numbers Every Programmer Should Know
```
L1 cache reference                    0.5 ns
Branch mispredict                     5   ns
L2 cache reference                    7   ns
Main memory reference                100   ns
SSD random read                      150   μs
Read 1 MB from memory                250   μs
Read 1 MB from SSD                     1   ms
Disk seek                             10   ms
Read 1 MB from disk                   20   ms
Send packet CA → Netherlands → CA    150   ms
```

## When to Optimize For
- **Latency**: User-facing APIs, real-time systems, search, gaming
- **Throughput**: Data pipelines, batch jobs, log processing, video transcoding

## Trade-offs
| Optimize Latency | Optimize Throughput |
|-----------------|-------------------|
| Cache aggressively | Batch requests |
| Reduce network hops | Parallelize processing |
| Use CDN for static content | Use message queues |
| Async where possible | Increase worker count |

## Interview Tips
- Quote the latency numbers — interviewers are impressed
- Say: "For user-facing features we optimize for latency, for backend processing we optimize throughput"
- P99 latency matters more than average — tail latencies kill user experience

## Best Articles
- [Latency Numbers Every Programmer Should Know](https://gist.github.com/jboner/2841832)
- [System Design Primer - Latency vs Throughput](https://github.com/donnemartin/system-design-primer#latency-vs-throughput)
- [Gil Tene: How NOT to Measure Latency](https://www.youtube.com/watch?v=lJ8ydIuPFeU)
