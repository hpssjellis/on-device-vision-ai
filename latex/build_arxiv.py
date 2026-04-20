"""
build_arxiv.py  –  Build a single-file arXiv LaTeX paper to PDF.

Usage:
    python build_arxiv.py <input_file.tex>

Example:
    python build_arxiv.py webmcu_ai_paper.tex

Requirements:
    - pdflatex must be installed and on PATH
      (TeX Live / MiKTeX on Windows; texlive on Linux/macOS)
    - The .tex file must use an inline \\begin{thebibliography} block
      (no separate .bib file needed – arXiv prefers self-contained sources)

arXiv submission notes:
    - arXiv requires a self-contained .tex file OR a .tar.gz with all assets.
    - If you have figure files (e.g. figure1.png), place them in the same
      folder and include them in the archive.
    - The 'output/' folder produced here is for local preview only;
      upload only the source .tex (and any image files) to arXiv.
    - arXiv runs pdflatex twice automatically, so the inline bibliography
      and \\tableofcontents will resolve correctly without bibtex.
"""

import subprocess
import os
import sys


def build_pdf(input_file: str) -> bool:
    """
    Compile a self-contained LaTeX file to PDF.

    Runs pdflatex three times:
      Pass 1 – initial compilation (creates .aux, .toc, etc.)
      Pass 2 – resolves \\tableofcontents and internal cross-references
      Pass 3 – picks up any remaining label/reference changes

    Outputs are written to an 'output/' sub-folder next to the script.
    """
    # ── Validate input ──────────────────────────────────────────────────────
    if not os.path.exists(input_file):
        print(f"Error: '{input_file}' not found.")
        return False
    if not input_file.endswith(".tex"):
        print(f"Error: '{input_file}' is not a .tex file.")
        return False

    base_name   = os.path.splitext(input_file)[0]
    script_dir  = os.path.dirname(os.path.abspath(__file__))
    output_dir  = os.path.join(script_dir, "output")

    os.makedirs(output_dir, exist_ok=True)

    # ── Three pdflatex passes ───────────────────────────────────────────────
    try:
        for pass_num in range(1, 4):
            label = ["initial", "cross-references", "final"][pass_num - 1]
            print(f"Pass {pass_num}/3  ({label})...")
            result = subprocess.run(
                [
                    "pdflatex",
                    "-interaction=nonstopmode",   # never pause for errors
                    "-halt-on-error",             # exit non-zero on fatal error
                    f"-output-directory={output_dir}",
                    input_file,
                ],
                capture_output=True,
                text=True,
            )
            if result.returncode != 0:
                # Print the last 30 lines of the log for diagnosis
                log_lines = result.stdout.splitlines()
                print("\n── pdflatex error output (last 30 lines) ──")
                print("\n".join(log_lines[-30:]))
                print("────────────────────────────────────────────")
                return False

        pdf_path = os.path.join(output_dir, base_name + ".pdf")
        if os.path.exists(pdf_path):
            size_kb = os.path.getsize(pdf_path) // 1024
            print(f"\nSuccess!  PDF written to:  {pdf_path}  ({size_kb} KB)")
        else:
            print(f"\nBuild finished but PDF not found at {pdf_path}")
            return False

        return True

    except FileNotFoundError:
        print(
            "Error: 'pdflatex' not found.\n"
            "  Linux/macOS: install texlive-latex-extra\n"
            "  Windows:     install MiKTeX and add it to PATH"
        )
        return False


# ── arXiv submission checklist (printed after a successful build) ───────────
ARXIV_CHECKLIST = """
─────────────────────────────────────────────────────
arXiv submission checklist
─────────────────────────────────────────────────────
 [x] Single .tex file with inline \\begin{{thebibliography}} block
     (no separate .bib file required)
 [ ] All figures included as .png/.jpg/.pdf in the same folder
     (replace \\fbox{{...}} placeholders with \\includegraphics)
 [ ] Abstract is plain text – no \\textbf, \\emph, or math in the
     first 250 characters (arXiv strips these for the listing page)
 [ ] Paper category: cs.LG  (Machine Learning)
     Cross-list suggestions: cs.AR (Hardware Architecture),
                             cs.NE (Neural and Evolutionary Computing)
 [ ] To upload: create a .tar.gz containing your .tex and all images:
       tar -czf arxiv_upload.tar.gz *.tex *.png *.jpg *.pdf
 [ ] arXiv will run pdflatex automatically; do NOT upload the output/ folder.
─────────────────────────────────────────────────────
"""


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage:  python build_arxiv.py <input_file.tex>")
        print("Example: python build_arxiv.py webmcu_ai_paper.tex")
        sys.exit(1)

    success = build_pdf(sys.argv[1])

    if success:
        print(ARXIV_CHECKLIST)
        sys.exit(0)
    else:
        sys.exit(1)
