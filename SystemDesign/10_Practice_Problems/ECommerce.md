# Design E-Commerce System

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
Functional: Product catalog, shopping cart, checkout, order management, payments. Non-Functional: Cart never loses items, payment consistency (ACID), 10M DAU.

## 2. Design Overview
Product Service (catalog + search via Elasticsearch), Cart Service (Redis for session-based cart), Order Service (Saga pattern: create order → charge payment → reserve inventory → confirm), Payment Service (idempotent with payment gateway). Database: PostgreSQL for orders (ACID), Redis for cart, Elasticsearch for search. Key challenge: inventory management — prevent overselling with distributed locks or optimistic locking.

## Best Articles
- [Design Amazon - ByteByteGo](https://blog.bytebytego.com/p/design-amazon)
