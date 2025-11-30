---
name: doc-component-design
description: Create or update detailed design documentation for a single embedded C component.
argument-hint: "Specify component name and whether it is legacy or new (greenfield)."
agent: component-designer
tools: [search/codebase, githubRepo]
---

You will create a **detailed design** document for a single embedded C component.

Determine the **mode**:

- **Legacy**: there is existing code; you must describe **what it actually does**.
- **Greenfield**: there is no or minimal code; you draft the design based on requirements and architecture.

Tasks:

1. Identify component boundaries
   - Name the component clearly.
   - List public interfaces (functions in headers, public data structures).
   - List key dependencies (other modules, hardware, RTOS, configuration).

2. Produce rst content for `<Component Name> - Detailed Design`:
   - Match the structure of `templates/docs/sw_detailed_design_template.rst`:
     - Responsibilities
     - Interfaces (public + important internal ones)
     - Data structures and state
     - Control flow and algorithms
     - Error handling and diagnostics
     - Timing and performance aspects (if relevant)
   - For legacy: base everything on **observed implementation** and mark guesses explicitly.
   - For greenfield: base on requirements/architecture and mark open questions.

3. Diagrams (optional but recommended when behavior is non-trivial):
   - Provide at least one **state or flow diagram** (Mermaid/PlantUML) if the component has non-trivial state or behavior.
   - Keep diagrams Sphinx-compatible.

4. Traceability and IDs:
   - Add a `.. need::` block of type `des` with a placeholder ID (e.g. `DES_<COMPONENT>_OVERVIEW`).
   - Include placeholders for related requirement IDs and architecture IDs where available.

5. Output:
   - A self-contained rst snippet that could be saved as `docs/design/<component>.rst` in a real project.
   - A short list of assumptions and open issues.
