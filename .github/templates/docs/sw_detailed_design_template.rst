==================================
<Component Name> - Detailed Design
==================================

.. need:: DES_<ID_PLACEHOLDER>
   :type: des
   :id: DES_<ID_PLACEHOLDER>
   :status: draft
   :links: ARC_<ARCH_ID_PLACEHOLDER>, REQ_<REQ_ID_PLACEHOLDER>
   :safety_relevance: ASIL-?

   Detailed design for <Component Name>.

1. Responsibilities
===================

- Short bullet list of what this component does.
- Scope and assumptions.

2. Interfaces
=============

2.1 Public Interfaces
---------------------

.. list-table:: Public Interfaces
   :header-rows: 1

   * - Function
     - Description
     - Inputs
     - Outputs
     - Errors
     - Pre/Postconditions
   * - <func_name>
     - <short description>
     - <input params>
     - <output params>
     - <error codes>
     - <pre/postconditions>

2.2 Internal Interfaces
-----------------------

- Helper functions
- Internal callbacks
- Interaction with other modules

3. Data Structures and State
============================

- Important structs and enums.
- Persistent state (static variables, global state).
- Configuration data.

Example:

.. code-block:: c

   typedef struct
   {
     uint16_t raw_value;
     uint16_t scaled_value;
     uint8_t  status;
   } <Component>_DataType;

4. Control Flow and Algorithms
==============================

4.1 Main Control Flow
---------------------

- High-level pseudo code for the main operations.
- Explanation of loops, decisions, and key processing.

4.2 Diagrams (Optional)
-----------------------

.. uml::

   @startuml
   title <Component> - Main flow

   start
   :Initialize;
   :Read input;
   if (valid?) then (yes)
     :Process;
   else (no)
     :Set error state;
   endif
   :Store result;
   stop

   @enduml

5. Error Handling and Diagnostics
=================================

- Error detection mechanisms.
- Error codes or status values.
- Reaction to faults (safe state, retries, degraded mode).
- Diagnostic events / DTCs if applicable.

6. Timing and Performance
=========================

- Execution context (task/ISR, period).
- Worst-case execution time assumptions (if known).
- Performance-critical aspects or optimizations.

7. Traceability
===============

- Requirements: REQ_<...>
- Architecture: ARC_<...>
- Unit tests: UT_<...>
- Integration tests: IT_<...>

8. Assumptions and Open Issues
==============================

- Design assumptions that are not guaranteed by the code.
- Open questions and TODOs.
