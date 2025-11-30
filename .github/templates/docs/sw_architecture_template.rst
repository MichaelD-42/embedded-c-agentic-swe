=====================================
<SW SYSTEM / COMPONENT> - Architecture
=====================================

.. need:: ARC_<ID_PLACEHOLDER>
   :type: arch
   :id: ARC_<ID_PLACEHOLDER>
   :status: draft
   :links: REQ_<REQ_ID_PLACEHOLDER>
   :safety_relevance: ASIL-?

   Architecture specification for <SW SYSTEM / COMPONENT>.

1. Introduction and Goals
=========================

- Business context and purpose.
- Main stakeholders and users.
- High-level quality goals (safety, reliability, performance, maintainability).

2. Constraints
==============

- Hardware platform (MCU, peripherals, memory)
- OS/RTOS or bare-metal
- Timing constraints (cycle times, deadlines)
- Safety / regulatory constraints (e.g. ISO 26262)
- Tooling and technology constraints

3. System Context and Scope
===========================

3.1 Context Diagram
-------------------

.. uml::

   @startuml
   title <SW SYSTEM / COMPONENT> - Context

   actor ExternalSystem
   node ECU

   ExternalSystem --> ECU : Signals/messages

   @enduml

3.2 External Interfaces
-----------------------

.. list-table:: External Interfaces
   :header-rows: 1

   * - Interface
     - Direction
     - Partner
     - Description
   * - IF_<NAME>
     - in/out
     - <Partner>
     - <Short description>

4. Solution Strategy
====================

- Overall approach (layering, separation of concerns).
- Main patterns (e.g. state machine, cyclic executive, event-driven).
- Safety and robustness concepts (fault detection, safe states, diagnostics).

5. Building Block View
======================

5.1 Top-Level Structure
-----------------------

.. uml::

   @startuml
   title Top-level building blocks

   package "Application" {
     [AppLogic]
   }

   package "Services" {
     [DiagService]
     [ConfigService]
   }

   package "Drivers" {
     [AdcDriver]
     [GpioDriver]
   }

   AppLogic --> DiagService
   AppLogic --> ConfigService
   AppLogic --> AdcDriver

   @enduml

5.2 Key Components
------------------

For each important component:

- Name:
- Responsibilities:
- Public interfaces:
- Dependencies:
- Safety relevance:

6. Runtime View
===============

Describe important scenarios (normal and error).

6.1 Scenario: <Scenario Name>
-----------------------------

.. uml::

   @startuml
   title Scenario: <Scenario Name>

   participant "App" as App
   participant "Service" as Srv
   participant "Driver" as Drv

   App -> Srv : Request(...)
   Srv -> Drv : Read(...)
   Drv --> Srv : Value
   Srv --> App : Result

   @enduml

- Preconditions:
- Main flow:
- Error/alternative flows:

7. Deployment View (Optional)
=============================

- Mapping of software parts to cores/MCUs.
- Resource-relevant aspects (memory, CPU load).

8. Cross-cutting Concepts
=========================

- Error handling
- Diagnostics
- Logging / trace
- Configuration and variability
- Security (if applicable)

9. Risks and Technical Debt
===========================

- Known architectural limitations.
- Planned refactorings or improvements.

10. Traceability
================

- Related requirements: REQ_<...>
- Detailed design: DES_<...>
- Unit tests: UT_<...>
- Integration tests: IT_<...>
