# Module 6 – Functions, Program Architecture & Execution

Functions are the building blocks of professional C programs. This module moves beyond `main()` and teaches you how to organise code, pass data, manage the call stack, and use function pointers to build flexible systems.

## Projects

- `project35-damage_calculation_engine` – Modular combat logic with separate functions for damage, critical hits, and printing
- `project36-dungeon_explorer_with_functions` – Refactored dungeon game using a clean function‑based architecture
- `project37-stack_frame_visualizer` – Prints addresses of parameters and locals to visualise the call stack
- `project38-player-stat-upgrade-system` – Uses pointers to upgrade player stats in-place
- `project39-priv_escalation_bug` – Demonstrates why passing by value fails for security logic, and how to fix it with pointers
- `project40-hex_dump_inspector` – Generic function to print raw bytes of any variable using `void*` and casting
- `project41-brute_force_protection` – Rate‑limiting login attempts using a `static` local variable
- `project42-system_logger` – Variadic `printf`‑style wrapper with severity tags (`[INFO]`, `[WARNING]`, `[ERROR]`)
- `project43-menu_router` – Function‑pointer dispatch table to replace `if`/`else` in a calculator menu
- `project44-request_processing_pipeline` – Middleware pipeline using a `NULL`‑terminated array of function pointers
- `project45-enemy_ai_behavior_table` – Random enemy AI decisions driven by an array of action functions
- `project46-traffic_light_fsm` – Table‑driven finite state machine for a traffic light
- `project47-universal_sorter` – Uses `qsort` with custom comparison callbacks to sort integers ascending/descending
- `project48-banking_system` – Modular banking library with separate header/source files for account logic

## Covered

- Function prototypes, definitions, and declarations
- Pass‑by‑value vs pass‑by‑reference (pointers)
- Stack frames and the call stack
- Variable scope, lifetime, and storage classes (`static`)
- `void*` and generic memory access
- Variadic functions (`stdarg.h`)
- Function pointers and callbacks
- Arrays of function pointers (dispatch tables)
- Pipelines and middleware patterns
- Modular code: header (`.h`) and source (`.c`) separation
- Include guards to prevent double inclusion
- Separate compilation and linking
- Defensive programming with invariants
- Information hiding (opaque pointers in later modules)
