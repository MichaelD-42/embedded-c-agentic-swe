# GenAI Embedded C Playbook

This repository collects **GitHub Copilot agents, prompts, and documentation patterns**
for embedded C projects.

It is meant to:

- Standardize how to use Copilot and other coding agents.
- Provide reusable prompts and agent roles for:
  - Architecture & detailed design (arc42, C4).
  - Legacy code characterization and refactoring.
  - Unit & integration testing (Google Test, BDD).
  - Reviews and traceability (sphinx-needs, ASPICE-style workflows).

## Structure

- `.github/copilot-instructions.md`
    Repo-wide default instructions for Copilot.

- `.github/agents/`
    Custom **Copilot agents** (roles):

  - Embedded architect
  - Component designer
  - Embedded C developer
  - Unit Test BDD test developer
  - Unit test executor
  - Review agent

- `.github/prompts/`
  Reusable **prompt commands** for typical workflows:

  - Document legacy architecture
  - Document detailed design
  - Create characterization tests
  - Refactor legacy components
  - Create integration tests
  - Review components

- `templates/docs/`
  RST templates for software architecture, detailed design,
  test specs,
  and test reports.

- `templates/code/`
  Example patterns for a well-structured embedded C module and Google Test unit tests.

- `scripts/`
  Utility scripts such as `generate_doc_id.py` for consistent doc IDs.

- `.vscode/` & `.devcontainer/`
  Shared VS Code and devcontainer configuration for a consistent workspace.

## How to use

1. Open this repo in VS Code.
2. Install recommended extensions when prompted.
3. Browse `.github/agents/` and `.github/prompts/` to see available roles and commands.
4. In Copilot Chat (VS Code or GitHub), select an agent (e.g. `embedded-architect`)
  and paste or invoke the relevant prompt.
