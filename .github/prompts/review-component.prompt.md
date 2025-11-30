---
name: review-component
description: Perform a structured review of changes to an embedded C component or set of components.
argument-hint: "Provide the diff, PR description, or list of changed files."
agent: review-agent
tools: [search/codebase, githubRepo]
---

You will perform a **structured code review** of a change set in an embedded C codebase.

Changes may involve **legacy**, **greenfield**, or mixed code. Note which case you see.

Tasks:

1. Understand the intent
   - Summarize the purpose of the change in 2–3 sentences from the diff/description.
   - Identify whether the change:
     - Adds new behavior.
     - Fixes defects.
     - Refactors existing code.
     - Touches safety-critical or timing-sensitive paths.

2. Apply the review checklist
   - **Correctness & behavior**
     - Does the change implement the intended behavior?
     - Are edge cases and error paths handled?
   - **Safety & robustness**
     - Any obvious undefined behavior or MISRA-style violations?
     - Any removal of checks, guards, or diagnostics?
   - **Architecture & design**
     - Are module boundaries respected?
     - Any new unwanted coupling?
   - **Readability & maintainability**
     - Naming, structure, function size, clarity.
   - **Tests**
     - Are tests updated/added where needed?
     - Do tests cover both normal and edge cases?
   - **Documentation**
     - Should architecture/design docs or specs be updated?
     - Any mismatch between code and existing templates?

3. Legacy-specific considerations
   - Are behavioral changes to legacy code clearly intentional and documented?
   - Has characterization or regression testing been considered for risky changes?
   - Any signs of removing “mysterious” behavior without proof it is unused?

4. Output a Markdown review
   - Use the structure:

     ```md
     ## Summary

     <short summary>

     ## Strengths

     - ...

     ## Risks / Issues

     - [ ] ISSUE-1: <short title>
       Details: ...

     ## Suggestions

     - ...

     ## Tests

     - Reported tests: ...
     - Missing tests: ...
     ```

5. Recommendation
   - Conclude with a clear recommendation:
     - Merge as-is / merge after nits / do not merge until issues are resolved.
