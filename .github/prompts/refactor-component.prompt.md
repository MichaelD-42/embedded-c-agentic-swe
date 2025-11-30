---
name: refactor-component-safe
description: Safely refactor a legacy embedded C component in small, reversible steps with tests.
argument-hint: "Specify the legacy component file(s) and relevant tests, if any."
agent: embedded-dev
tools: [search/codebase, githubRepo, terminal]
---

You will **safely refactor a legacy embedded C component**.

Assumptions:

- This is **legacy (brownfield)** code.
- Maintaining behavior is critical unless bugs are explicitly identified.
- Characterization tests should exist or will be created.

Tasks:

1. Quick assessment
   - Summarize:
     - Main responsibilities of the component.
     - Key problems (very long functions, deep nesting, global state, duplication).
     - Any obvious safety or robustness risks.

2. Check for tests
   - Identify existing unit/integration tests.
   - If there are none or they are weak, recommend creating or extending tests via the `create-characterization-tests` prompt before deep refactoring.
   - Do not proceed with risky structural changes if there is no test safety net; say so explicitly.

3. Propose a stepwise refactoring plan
   - Provide a numbered list (3–10 steps) of **small, reversible steps**, for example:
     - Extract helper functions.
     - Separate pure logic from I/O and hardware access.
     - Break down large state machines into smaller units.
   - For each step, specify:
     - Goal.
     - Impacted functions/files.
     - Tests that must stay green.

4. Show minimal code changes
   - For one or more steps (as requested), show minimal diffs / code snippets that:
     - Reduce complexity.
     - Improve readability or testability.
     - Keep external behavior and public API unchanged.
   - Highlight any safety-relevant changes.

5. Output:
   - The refactoring plan.
   - Concrete code changes for the requested steps.
   - A short list of risks and recommended follow-up checks (tests, reviews).
