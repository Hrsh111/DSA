# Design Parking Lot System

**Difficulty**: Medium | **Time Target**: 30-35 min

## 1. Requirements
Functional: Track available spots, assign spots to vehicles, calculate fee on exit. Vehicle types: motorcycle, car, bus. Non-Functional: Real-time availability, concurrent entry/exit.

## 2. Design Overview
This is more OOP design than distributed systems. Classes: ParkingLot, Level, ParkingSpot (types), Vehicle (types), Ticket, PaymentProcessor. Key patterns: Strategy pattern for pricing, Factory for vehicle/spot matching. Concurrency: mutex on spot assignment. Database: spots table with status enum.

## Best Articles
- [Design Parking Lot - Educative](https://www.educative.io/courses/grokking-the-object-oriented-design-interview/system-design-parking-lot)
