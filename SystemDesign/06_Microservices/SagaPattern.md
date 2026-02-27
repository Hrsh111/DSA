# Saga Pattern

## What is it?
A way to manage distributed transactions across multiple microservices. Instead of one big ACID transaction, break it into a sequence of local transactions with compensating actions for rollback.

## Types

### 1. Choreography (Event-Driven)
```
Order Service → "OrderCreated" → Payment Service → "PaymentCompleted" → Inventory Service
                                 If fails → "PaymentFailed" → Order Service (cancel order)
```
- Each service listens for events and acts independently
- No central coordinator
- Simple for few services, messy for many

### 2. Orchestration (Central Coordinator)
```
[Saga Orchestrator]
  1. Tell Order Service: create order
  2. Tell Payment Service: charge payment
  3. Tell Inventory Service: reserve items
  If step 2 fails: Tell Order Service: cancel order (compensating action)
```
- Central orchestrator manages the flow
- Easier to understand and debug
- Single point of failure (the orchestrator)

## Key Points
- Each step has a **compensating transaction** (undo action) for rollback
- NOT ACID — provides eventual consistency
- Compensating actions must be **idempotent**
- Example: CreateOrder → ChargePayment → ReserveInventory → ShipOrder. If ReserveInventory fails → RefundPayment → CancelOrder

## When to Use
- Any operation spanning multiple microservices that need to be consistent
- E-commerce: order → payment → inventory → shipping
- Travel booking: flight → hotel → car rental

## Trade-offs
| Choreography | Orchestration |
|-------------|---------------|
| Decoupled | Central control |
| No SPOF | Orchestrator is SPOF |
| Hard to debug | Easy to follow flow |
| Good for simple flows | Good for complex flows |

## Interview Tips
- "For our order flow spanning 3 services, we'd use the saga pattern with an orchestrator"
- "Each step has a compensating action — if payment fails after order creation, we cancel the order"
- Mention eventual consistency: "The system is eventually consistent, not immediately"

## Best Articles
- [Saga Pattern - Microsoft](https://learn.microsoft.com/en-us/azure/architecture/reference-architectures/saga/saga)
- [Microservices Patterns: Sagas](https://microservices.io/patterns/data/saga.html)
- [ByteByteGo: Distributed Transactions](https://blog.bytebytego.com/p/distributed-transactions)
