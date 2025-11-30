---
name: create-testsuite-for-legacy
description: Create a Google Test characterization suite that captures current behavior of a legacy component.
argument-hint: "Specify the legacy component or functions to characterize."
agent: gtest-bdd-test-dev
tools: [search/codebase, githubRepo, terminal]
---

You will create **characterization tests** for a **legacy (brownfield)** embedded C component using Google Test.

Goals:

- Capture current behavior **exactly as it is today**, including quirks that must remain for compatibility.
- Provide a safety net before refactoring.

Tasks:

1. Analyze current behavior
   - Inspect the specified component’s header and source files.
   - Identify:
     - Public API (functions, parameters, return values, error codes).
     - Important global state / configuration.
     - Typical and boundary input ranges.

2. Propose a test plan
   - Group scenarios into:
     - Normal / nominal behavior
     - Boundary conditions
     - Error / exceptional cases
     - Known quirks or bug-compatible behavior
   - For each scenario, describe GIVEN / WHEN / THEN in one or two lines.

3. Implement tests in gtest
   - Create or extend a `*_test.cpp` file for this component.
   - Use BDD-style comments and descriptive test names, for example:

     ```cpp
     // GIVEN: initialized module with default config
     // WHEN:  processing input within normal range
     // THEN:  output matches expected scaling and status is OK
     ```

   - Keep tests deterministic and host-runnable (no direct hardware access:
     use stubs/mocks/abstractions as needed).

4. Handle legacy quirks
   - If you detect behavior that looks like a bug but is **likely relied on**:
     - Write tests that capture this behavior.
     - Mark such tests clearly in comments (e.g. `// BUG_COMPAT: historical behavior`).

5. Output:
   - The full content of the proposed test file(s).
   - The command(s) that should be used to build and run these tests (based on common conventions in the codebase if visible).
   - A summary mapping test cases to behaviors covered (and pointing out any gaps).
