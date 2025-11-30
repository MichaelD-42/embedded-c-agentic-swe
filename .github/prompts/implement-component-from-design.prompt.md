---
name: implement-component-from-design
description: Implement a new embedded C component based on detailed design and templates.
argument-hint: "Provide component name and link or snippet of the detailed design."
agent: embedded-dev
tools: [search/codebase, githubRepo, terminal]
---

You will **implement a new embedded C component** (greenfield or major rewrite) based on its design.

Assume:

- C17, MISRA-style, no dynamic allocation in production code.
- Implementation should follow the shapes shown in `templates/code/module_template.h` and `.c`.

Tasks:

1. Understand the detailed design
   - Read the provided design description (or summarize it from context).
   - Identify:
     - Public API (functions, parameters, return values).
     - Internal state and configuration.
     - Error handling and timing requirements.

2. Propose the module structure
   - Suggest:
     - `<component>.h` with public types and APIs.
     - `<component>.c` with implementation and static helpers.
   - Align with `templates/code/module_template.h` / `.c` naming and layout.

3. Implement
   - Generate header and source code with:
     - Clear comments for API functions.
     - Proper use of `const`, fixed-width types, and error enums.
     - Static internal helpers where appropriate.
   - Keep behavior purely as specified (do not invent extra features).

4. Testing hooks
   - Point out where unit tests should hook into the API.
   - If helpful, suggest a starter Google Test fixture using `templates/code/gtest_unit_test_template.cpp`.

5. Output:
   - Complete `*.h` and `*.c` file contents (ready to drop into a project).
   - Optional starter test file or skeleton.
   - Any assumptions you made when the design/spec was incomplete.
