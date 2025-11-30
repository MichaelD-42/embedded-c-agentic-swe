#!/usr/bin/env python3
"""
Simple doc ID generator.

Usage:
    python scripts/generate_doc_id.py TYPE COMPONENT SHORT_TAG

Example:
    python scripts/generate_doc_id.py ARC AdcDriver Overview

Output:
    ARC_ADCDRIVER_OVERVIEW_20251130T102030
"""

import sys
from datetime import datetime


def sanitize(part: str) -> str:
    part = part.strip().replace(" ", "_")
    part = "".join(ch for ch in part if ch.isalnum() or ch == "_")
    return part.upper()


def main(argv: list[str]) -> None:
    if len(argv) != 4:
        print("Usage: generate_doc_id.py TYPE COMPONENT SHORT_TAG",
              file=sys.stderr)
        sys.exit(1)

    doc_type = sanitize(argv[1])
    component = sanitize(argv[2])
    short_tag = sanitize(argv[3])
    timestamp = datetime.now().strftime("%Y%m%dT%H%M%S")

    doc_id = f"{doc_type}_{component}_{short_tag}_{timestamp}"
    # Print doc_id, ensuring no line exceeds 79 chars
    if len(doc_id) > 79:
        for i in range(0, len(doc_id), 79):
            print(doc_id[i:i+79])
    else:
        print(doc_id)


if __name__ == "__main__":
    main(sys.argv)
