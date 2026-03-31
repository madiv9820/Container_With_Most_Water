"""
🧾 File Description:

This setup script compiles the Cython module into a Python extension
using a C backend.

It builds the `.pyx` file and links it with the C implementation
defined in `solution.h`.

🎯 Purpose:
- Compile Cython wrapper with C support
- Enable Python ↔ C integration
- Generate importable extension module for execution
"""

from setuptools import setup, Extension
from Cython.Build import cythonize

# ⚙️ Define extension module configuration
ext = Extension(
    name='solution',              # 📦 Name of compiled module
    sources=['solution.pyx'],     # 📄 Cython source file
    language='c'                  # ⚙️ Use C for compilation
)

# 🛠️ Setup build process
setup(
    ext_modules=cythonize(
        ext,
        language_level=3          # 🐍 Use Python 3 syntax
    )
)