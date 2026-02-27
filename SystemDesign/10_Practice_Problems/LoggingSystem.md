# Design Distributed Logging System

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
Functional: Collect logs from all services, search/filter logs, alerting on patterns. Non-Functional: Handle 100K log events/sec, searchable within 5 seconds, retain 30 days.

## 2. Design Overview
ELK Stack: Elasticsearch (search/index) + Logstash/Fluentd (collection/parsing) + Kibana (visualization). Pipeline: Services → Log Agent (Fluentd) → Kafka (buffer) → Log Processor → Elasticsearch → Kibana. Alternatively: Loki + Grafana (cheaper, label-based). Key: structured logging (JSON), log levels, correlation IDs for distributed tracing.

## Best Articles
- [Logging Architecture - Elastic](https://www.elastic.co/guide/en/elasticsearch/reference/current/index.html)
