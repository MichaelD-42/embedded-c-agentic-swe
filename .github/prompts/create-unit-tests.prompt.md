---
name: create-unit-tests
description: Create Google Test unit tests from requirements or design specs for a greenfield component.
argument-hint: "Provide the component name and the relevant requirements or design sections."
agent: gtest-bdd-test-dev
tools: [search/codebase, githubRepo, terminal]
---

You will create **spec-based unit tests** for a **greenfield or newly designed** embedded C component using Google Test.

Goals:

- Derive tests from requirements/design, not from existing implementation.
- Provide a clear behavior specification in GIVEN/WHEN/THEN form.

Tasks:

1. Understand the specification
   - Read the provided requirements and/or detailed design.
   - Identify:
     - Main responsibilities.
     - Inputs, outputs, and error conditions.
     - Important boundary conditions and invariants.

2. Draft or refine a unit test specification (optional but recommended)
   - Use the structure of `templates/docs/sw_unit_test_spec_template.rst` as a mental model.
   - List test cases as:
     - ID
     - Title
     - GIVEN
     - WHEN
     - THEN

3. Implement tests in gtest
   - Create or extend a `*_test.cpp` file for the component.
   - Use BDD-style comments in each test (GIVEN/WHEN/THEN).
   - Make test names descriptive, focusing on behavior.
   - Prefer small, focused tests over large scenario tests.

4. Coverage and safety
   - Aim to cover:
     - All main functional paths.
     - Boundary and error conditions.
     - Safety-relevant behavior (if indicated).
   - Note any behaviors that remain untested and why.

5. Output:
   - The complete test file content.
   - Suggested build/run commands or references.
   - A short summary mapping test cases to requirement/design IDs (if provided).
