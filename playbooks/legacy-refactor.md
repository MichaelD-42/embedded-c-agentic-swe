# Legacy Component Refactor Playbook (Example: ADC Driver)

This playbook shows how to use our **agents** and **prompts** on the
`examples/legacy-adc-module` ADC driver.

## 1. Understand and Document

1. Open `examples/legacy-adc-module/` in VS Code.
2. Use **agent** `embedded-architect` with prompt `doc-architecture`:
   - Scope: "ADC Input subsystem (example)".
   - Mode: legacy/as-is.
   - Goal: update or refine `docs/adc_architecture_example.rst`.

3. Use **agent** `component-designer` with prompt `doc-component-design`:
   - Component: `adc_driver`.
   - Mode: legacy/as-is.
   - Goal: refine `docs/adc_design_example.rst` to match the code exactly.

## 2. Build a Safety Net (Characterization Tests)

4. Use **agent** `gtest-bdd-test-dev` with prompt `create-characterization-tests`:
   - Target: `adc_driver.c/.h`.
   - Task: extend `tests/adc_driver_test.cpp` to cover:
     - Startup behavior.
     - Nominal scaling at different raw values.
     - Error cases (`max_raw == 0`, not initialized).
   - Keep tests deterministic and host-runnable.

5. Run tests with **agent** `unit-test-executor` (or manually):
   - Ensure the test suite passes and captures current behavior.

## 3. Refactor Safely

6. Use **agent** `embedded-dev` with prompt `refactor-component-safe`:
   - Target: `adc_driver.c`.
   - Goal: reduce complexity and improve readability without changing behavior.
   - Expect:
     - A small, stepwise refactor plan.
     - Minimal code changes per step.
     - Emphasis on keeping existing tests green.

7. After each refactor step:
   - Re-run tests using `unit-test-executor`.
   - Only proceed if the suite stays green.

## 4. Review and Finalize

8. Use **agent** `review-agent` with prompt `review-component-change`:
   - Provide the diff or changed file(s).
   - Request a structured review including:
     - Correctness & behavior.
     - Safety/robustness.
     - Readability/maintainability.
     - Tests & docs.

9. Apply fixes based on the review and re-run tests.

This flow is the **reference example** for legacy refactoring in our GenAI playbook.
Use it as a template when onboarding others or when applying the same approach to
real legacy components in production codebases.
