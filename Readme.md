# Python package with utils in C++ for textual analysis

## BUILD
to build and push on PiPy just create a new tag
- git tag -d vX.X.X [to delete tags]
- git tag vX.X.X
- git push origin vX.X.X

with the same version as the version in setup.py
the pipeline will automatically create the tag, release and push it on PiPy.

remember to allign the version of the release on github with the version in the setup.py file.

- git show-ref


## for local testing

pip install . --force-reinstall
