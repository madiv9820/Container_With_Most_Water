"""
🧾 File Description:

This setup script is used to compile the Cython module into a Python extension.

It defines a C++ extension using `setuptools` and compiles the `.pyx` file
(using Cython) into a shared object that can be imported in Python.

🎯 Purpose:
- Build the Cython wrapper for the C++ solution
- Enable seamless integration of C++ performance with Python usage
"""

from setuptools import setup, Extension
from Cython.Build import cythonize

# ⚙️ Define the extension module
ext = Extension(
    name='solution',              # 📦 Name of the compiled module
    sources=['solution.pyx'],     # 📄 Source Cython file
    language='c++'                # 🚀 Specify C++ for compilation
)

# 🛠️ Setup configuration to build the extension
setup(
    ext_modules=cythonize(
        ext,
        language_level=3          # 🐍 Use Python 3 syntax
    )
)