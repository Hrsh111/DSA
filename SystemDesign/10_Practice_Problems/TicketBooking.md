# Design Ticket Booking System (BookMyShow)

**Difficulty**: Hard | **Time Target**: 40-45 min

## 1. Requirements
Functional: Browse events, view seat map, select seats, book with payment. Non-Functional: No double booking, handle flash sales (high concurrency).

## 2. Design Overview
Seat locking: when user selects seats, lock for 10 minutes (Redis with TTL). If payment completes → confirm booking. If timeout → release lock. Distributed lock prevents double booking. Queue-based for flash sales: put users in virtual queue, process in order. Database: pessimistic locking (SELECT FOR UPDATE) or optimistic locking (version column). Payment: idempotent with saga pattern.

## Best Articles
- [Design Ticket Booking - Educative](https://www.educative.io/courses/grokking-modern-system-design-interview-for-engineers-managers/system-design-ticketmaster)
