# Repository-wide Copilot Instructions

This repository defines how we want GitHub Copilot and other coding agents to behave
for **embedded C development in automotive context** and how to use our specialized
agents.

These guidelines are intentionally generic. Detailed behavior for specific roles
(architecture, design, refactoring, tests, reviews) lives in `.github/agents/`.

---

## 1. General Development Style

- Domain: Embedded C (C18) for resource-constrained MCUs in automotive.
- Assume:
  - Deterministic execution, bounded loops.
  - No dynamic memory allocation in production code unless explicitly allowed.
  - No recursion.
  - Comply with MISRA C:2023 (including amendments), ISO 26262, and SEI CERT C
    recommendations.
- Prefer:
  - Small, composable functions with explicit interfaces.
  - Clear separation between hardware access and pure logic.
  - Fixed-width integer types where appropriate (`uint8_t`, `uint16_t`, etc.).

When in doubt, **do not invent domain behavior** (e.g. safety, hardware).
Instead, ask for clarification or point out assumptions explicitly.

---

## 2. Commit Messages

We use **conventional commits with scopes**, semantic-release compatible:

### Format

```text
<type>(<scope>): <short subject>
```

- `type` (lowercase): for example:
  - `feat:` new feature or behavior
  - `fix:` bug fix
  - `refactor:` code changes without behavior change
  - `docs:` documentation only
  - `test:` tests only
  - `chore:` tooling, config, non-code changes
  - `build:` build system or dependencies
  - `ci:` CI configuration
- `scope` (lowercase, optional but preferred):
  - A module, component, or area, e.g. adc, pwm, docs, build, tests.

### Examples

- feat(adc): add saturation logic for readings
- fix(pwm): correct boundary handling for duty cycle
- refactor(controller): split main step into helpers
- test(adc): add characterization tests for overflow
- chore(docs): cleanup architecture template
- chore(build): update toolchain version
- ci(tests): run unit tests on pull requests

### Guidelines

- Keep the **subject line short and concise** (aim ≤ 72 chars).
- Use the body only when helpful (what/why, not line-by-line diffs).
- Group related changes into a single commit rather than mixing unrelated topics.

If asked to generate commits or commit messages, follow this convention strictly.

---

## 3. Working with Code

When generating or modifying code:

- Prefer minimal, focused changes instead of large rewrites.
- Keep existing behavior intact unless explicitly told to change it.
- Make error handling explicit; do not silently remove checks.
- When touching critical or safety-related code paths, call this out in your explanation
  and suggest additional tests or reviews.

When code is hard to test, you may suggest small refactorings to improve testability,
but do not apply them automatically unless requested.

---

## 4. Tests

- Prefer **Google Test (gtest)** for unit tests in C/C++ code.
- Structure tests around behavior:
  - Use GIVEN/WHEN/THEN in comments and test naming where practical.
- Aim for high coverage on important paths.
Avoid meaningless tests just to increase coverage.

When asked to add or modify tests:

- Keep them deterministic and independent.
- Avoid tests that depend on real hardware unless explicitly requested.
- Prefer host-based tests using mocks or abstractions.
- Prefer good module design that allows for testing without mocks.

---

## 5. Documentation & Templates

This repository contains **templates** under `.github/templates/`:

- `.github/templates/docs/` – RST templates for:

  - Software architecture
  - Detailed design
  - Unit test specification
  - Integration test specification
  - Test reports

- `.github/templates/code/` – Example patterns for:

  - Embedded C modules (`.h` / `.c`)
  - Google Test unit tests

When generating docs or code use these templates as references for:

 - Section headings
 - Typical tables / diagrams
 - API and data structure layout

---

## 6. Using Specialized Agents

This repository defines **specialized Copilot agents** in `.github/agents/`:

- `embedded-architect` – software architecture (arc42, C4, high-level views)
- `component-designer` – detailed design documentation
- `embedded-dev` – implementation and refactoring of embedded C
- `gtest-bdd-test-dev` – Google Test unit tests in BDD style
- `unit-test-executor` – running tests and summarizing results
- `review-agent` – structured code reviews

When the task clearly falls into one of these areas, prefer using the matching agent
instead of a generic assistant. For example:

- Architecture/doc tasks → `embedded-architect`
- Detailed design docs → `component-designer`
- Refactoring/implementation → `embedded-dev`
- New or improved tests → `gtest-bdd-test-dev`
- Running/summarizing tests → `unit-test-executor`
- Reviewing changes → `review-agent`

This keeps behavior consistent and aligns with our playbook.

---

## 7. Assumptions and Safety

If an instruction conflicts with:

- Safety requirements,
- MISRA-style restrictions,
- Or obvious embedded constraints (timing, memory, hardware access),

you should:

1. Point out the potential conflict.
2. Propose a safer or more appropriate alternative.
3. Ask for confirmation before applying risky changes.

When information is missing, prefer being explicit about assumptions rather than
guessing silently.
