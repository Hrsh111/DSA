# Idempotency

## What is it?
An operation is **idempotent** if performing it multiple times has the same effect as performing it once. Critical for reliable distributed systems.

## HTTP Methods
| Method | Idempotent? | Safe? |
|--------|------------|-------|
| GET | Yes | Yes |
| PUT | Yes | No |
| DELETE | Yes | No |
| POST | **No** | No |
| PATCH | **No** | No |

## Making POST Idempotent (Idempotency Key)
```
POST /api/payments
Header: Idempotency-Key: uuid-abc-123
Body: { amount: 100, to: "user_456" }

Server:
1. Check if Idempotency-Key exists in store
2. If yes → return cached response (don't process again)
3. If no → process request, store key + response
```

## Key Points
- **Why it matters**: Network retries, duplicate messages, client timeouts + retries
- Without idempotency: user gets charged twice, duplicate orders created
- Store idempotency keys in Redis with TTL (24 hours typical)
- Stripe, PayPal, and all payment APIs require idempotency keys
- Database: use UPSERT or unique constraints to prevent duplicates

## When to Use
- Payment processing (MUST be idempotent)
- Order creation
- Any mutation that could be retried
- Message queue consumers (at-least-once delivery means duplicates)

## Interview Tips
- "All payment endpoints accept an idempotency key to prevent duplicate charges on retry"
- "Message consumers are idempotent — processing the same event twice has no additional effect"
- Mention Redis for storing idempotency keys with TTL

## Best Articles
- [Stripe Idempotent Requests](https://stripe.com/docs/api/idempotent_requests)
- [Idempotency Patterns](https://blog.bytebytego.com/p/idempotency)
