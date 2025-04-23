# Python package with utils in C++ for textual analysis

## BUILD & TAG
to build and push on PiPy just create a new tag
- git tag -d vX.X.X [to delete tags]
- git tag vX.X.X
- git push origin vX.X.X

with the same version as the version in setup.py
the pipeline will automatically create the tag, release and push it on PiPy.

**remember to allign the version of the release on github with the version in the setup.py file.**

- git show-ref


## For local testing

pip install . --force-reinstall



## how to create a new function or module

module:
- create the folder in **src/textcpp**, call it XXX
- create inside the module a ***bindings_XXX.cpp***
- create the .cpp files with the functions and add the functions inside the ***bindings_XXX.cpp***
- place the function typings in the operations.h
- add the Extension to the **setup.py**
- add the new module to **__ init__.py** to make it visible to IntelliSense