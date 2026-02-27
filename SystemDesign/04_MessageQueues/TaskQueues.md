# Task Queues and Workers

## What is it?
A pattern where tasks (units of work) are placed in a queue and processed by worker processes asynchronously. Separates task submission from execution.

```
[Web Server] → enqueue task → [Queue: Redis/RabbitMQ] → [Worker 1]
                                                       → [Worker 2]
                                                       → [Worker 3]
```

## Key Points
- Offload heavy/slow operations from request-response cycle
- Workers process tasks at their own pace (backpressure handling)
- Tasks can be retried on failure (with exponential backoff)
- Priority queues: urgent tasks processed first
- Dead letter queue (DLQ): failed tasks after max retries go here for inspection
- Implementations: Celery (Python), Sidekiq (Ruby), Bull (Node.js), custom with Redis/RabbitMQ

## Common Use Cases
- Sending emails/notifications
- Image/video processing (resize, transcode)
- PDF generation
- Data import/export
- Scheduled jobs (cron-like)

## When to Use
- Any operation that's too slow for synchronous response (>500ms)
- Batch processing
- Rate-limited external API calls
- CPU-intensive operations

## Trade-offs
| Pros | Cons |
|------|------|
| Non-blocking user experience | Added infrastructure complexity |
| Retry/error handling built in | Monitoring/debugging harder |
| Scale workers independently | Eventual processing (not instant) |
| Handles traffic spikes | Need to handle duplicate tasks (idempotency) |

## Interview Tips
- "We'd offload email sending to a task queue so the API responds immediately"
- Mention retry strategy: "Exponential backoff with max 3 retries, then dead letter queue"
- Scaling: "We can add more workers to process tasks faster during peak"

## Best Articles
- [Task Queue Architecture](https://blog.bytebytego.com/p/message-queue-vs-task-queue)
- [Celery Documentation](https://docs.celeryq.dev/)
- [Designing Reliable Task Queues](https://slack.engineering/building-reliable-worker-processes/)
