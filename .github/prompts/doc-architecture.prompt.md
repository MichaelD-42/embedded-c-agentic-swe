---
name: doc-architecture
description: Document or draft the software architecture of an embedded system using arc42/C4 in rst form.
argument-hint: "Optionally specify legacy vs greenfield and the system/subsystem name."
agent: embedded-architect
tools: [search/codebase, githubRepo]
---

You will create **architecture documentation** for an embedded C system or subsystem.

First, determine the **mode**:

- If there is existing code and build config: treat as **legacy/brownfield** and document the **as-is** architecture.
- If there is only requirements / ideas / no code yet: treat as **greenfield** and propose a **to-be** architecture.
- If unclear, state your assumption (legacy vs greenfield) explicitly before proceeding.

Tasks:

1. Clarify scope
   - Identify the system or subsystem name.
   - For legacy: locate main binaries, top-level components, and HW interfaces (MCU, peripherals, buses).
   - For greenfield: use the given requirements/context as the scope.

2. Produce an arc42/C4-aligned architecture skeleton in **reStructuredText (rst)**:
   - Introduction and goals
   - Constraints (hardware, timing, safety, platform, tools)
   - Context view (system context, external actors/interfaces)
   - Building block view (modules, layers, key components)
   - Runtime view (1–3 key scenarios)
   - Cross-cutting concepts (error handling, diagnostics, safety, configuration)

3. Use diagrams where they add clarity:
   - Provide example **Mermaid or PlantUML** diagrams that will work in a Sphinx-based setup.
   - Keep diagrams small and focused (no “god diagrams”).

4. Align with the architecture template:
   - Use section headings compatible with `templates/docs/sw_architecture_template.rst`.
   - Add at least one `.. need::` block of type `arch` with a placeholder ID (e.g. `ARC_<SYSTEM>_OVERVIEW`).
   - Leave TODO markers where project-specific details are needed.

5. Output:
   - A single rst snippet that could be saved as `docs/architecture/<system>.rst` in a real project.
   - A short bullet list of assumptions and open questions (especially for legacy systems with missing information).
