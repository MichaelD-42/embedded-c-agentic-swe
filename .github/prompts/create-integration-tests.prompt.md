---
name: create-integration-tests
description: Design and implement integration tests combining multiple embedded components.
argument-hint: "Describe which components or scenarios should be integrated and whether they are legacy or new."
agent: gtest-bdd-test-dev
tools: [search/codebase, githubRepo, terminal]
---

You will design and implement **integration tests** for embedded C components.

The scope can be **legacy**, **greenfield**, or a mix. State which you assume.

Tasks:

1. Clarify integration scope
   - List components involved and their roles.
   - Describe the end-to-end behavior to verify (inputs, outputs, main scenarios).
   - Note whether components are legacy, new, or mixed.

2. Propose an integration test strategy
   - Decide:
     - Which components run as real code.
     - Which dependencies will be mocked or stubbed.
     - How to simulate external inputs and environment (timers, signals, bus messages).
   - Aim for deterministic, host-runnable tests where possible.

3. Implement tests
   - Create or extend integration-focused gtest files (e.g. `*_it_test.cpp`).
   - Use fixtures for shared setup/teardown.
   - Express major scenarios using GIVEN/WHEN/THEN comments and clear assertions.
   - For legacy:
     - Capture current cross-component behavior.
   - For greenfield:
     - Align tests with architecture/design and requirements.

4. Coverage and traceability
   - Identify:
     - Which data flows and interfaces are covered.
     - Which scenarios remain untested.
   - Optionally, reference requirement/design IDs if provided.

5. Output:
   - The integration test code.
   - Suggested build/run commands.
   - A short summary of coverage and remaining gaps.
