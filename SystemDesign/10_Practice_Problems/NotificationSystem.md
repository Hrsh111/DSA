# Design Notification System

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
### Functional: Send push notifications (iOS/Android), SMS, email. Support scheduled notifications, templates, user preferences.
### Non-Functional: Soft real-time (<1 min), at-least-once delivery, 10M notifications/day

## 2. Architecture
```
Event Source → Notification Service → Priority Queue → [Push Worker, SMS Worker, Email Worker]
                                                     → APNs / FCM / Twilio / SendGrid
```

## 3. Key Components
- **Notification Service**: Validates, checks user preferences, applies rate limiting
- **Message Queue**: Kafka with priority topics (critical > marketing)
- **Workers**: Consume from queue, call external providers (APNs, FCM, Twilio)
- **Template Engine**: Notification templates with variable substitution
- **User Preferences**: Allow users to opt out of specific notification types
- **Retry**: Exponential backoff for failed deliveries, DLQ after max retries
- **Deduplication**: Idempotency key to prevent duplicate notifications

## Best Articles
- [Design Notification System - ByteByteGo](https://blog.bytebytego.com/p/design-a-notification-system)
