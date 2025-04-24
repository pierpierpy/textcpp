<p align="center">
  <strong>
    <h1>TEXTCPP</h1>  </strong>
    Python package for high-performance textual analysis,  
     Python's simplicity with C++ speed and efficiency.

</p>

<p align="center">
  <img src="logo.png" alt="TextCpp Logo" width="360"/>
</p>

## USAGE
install using:
```bash
>> pip install textcpp
```
usage in ***Python***:
```python
import textcpp as tcpp
help(tcpp.text_utils.frequency_count)
text_count = tcpp.text_utils.frequency_count("shakespeare.txt")
regex = tcpp.preprocessing.RegexTokenizer(r"\W+")
regex.tokenize("ciao ciao")
n_grams_regex = tcpp.preprocessing.extract_ngrams("shakespeare.txt",100,regex, is_file = True )
```
## BUILD & PUSH
to build and push on PiPy just create a new tag
```bash
>> git tag -d vX.X.X [to delete tags]
>> git tag vX.X.X
>> git push origin vX.X.X
```
with the same version as the version in setup.py
the pipeline will automatically create the tag, release and push it on PiPy.

**remember to allign the version of the release on github with the version in the setup.py file.**
```bash
>> git show-ref
```

## Local Testing
remember to set the version to **vX.X.X-dev** in the **setup.py**
```bash
>> rm -r build/
>> rm -r src/textcpp.egg-info
>> pip install . --force-reinstall
```


## COLAB

### create a new *MODULE*:
- create the folder in **src/textcpp**, call it XXX
- create inside the module a ***bindings_XXX.cpp***
- create the .cpp files with the functions and add the functions inside the ***bindings_XXX.cpp***
- place the function typings in the operations.h
- add the Extension to the **setup.py**
- add the new module to **__ init__.py** to make it visible to IntelliSense

### create a new *FUNCTION*:
- create the .cpp files with the functions and add the functions inside the ***bindings_XXX.cpp***
- place the function typings in the operations.h
- add new .cpp files to Extension to the **setup.py**
- add the new module to **__ init__.py** to make it visible to IntelliSense
