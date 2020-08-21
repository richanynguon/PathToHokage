# Template Automation 

## Dependencies
- Python 3
- Pipenv

## Enviroment Variables
```
TAB   
GITHUB_URL_PREFIX
```
TAB - An integer that describes the desired amount of spaces in a tab  
GITHUB_URL_PREFIX - A URL string that points to the a specific repo have you have already created on github

## Start Up
Start your python enviroment

```python
$ pipenv shell
```
Run the template_automation file with python two arguments  
1. A filepath to a text file of the desired outline
2. New folder title to create

```python
$ python3 template_automation.py <filepath/outline.txt> <new_folder_name>
```

The new directory will be created in the same directory as the text file.

## Text File Outline Sample
```text
Title
Section Level 1
    Section Field Level 2
        Section Field Level 3
            Section Field Level 4
            Section Field Level 4
                Section Field Level 5
            Section Field Level 4
                Section Field Level 5        
Section 2
    Section Field
    Section Field
    Section Field
        Section Field
            Section Field
```
Outline automate does not support Section Field Level past 5. The text file must not have spaces after the content or in between sections. The extra spaces will create empty sections.

## Output Sample
Folder Structure
```
    ------------------------------------------
    |   test                                 |
    |       ->src                            |
    |           ->Section_2.md               |             
    |           ->Section_Level_1.md         |
    |       ->test.md                        |
    ------------------------------------------
```
Index File
```
# Title   
## [Section Level 1](https://github.com/user/repo/blob/master/test/src/Section_Level_1.md)   
- Section Field Level 2   
    - Section Field Level 3   
        - Section Field Level 4   
        - Section Field Level 4   
            - Section Field Level 5   
        - Section Field Level 4   
            - Section Field Level 5   
## [Section 2](https://github.com/user/repo/blob/master/test/src/Section_2.md)   
- Section Field   
- Section Field   
- Section Field   
    - Section Field   
        - Section Field   
```
Section 1 File
```
# Section Level 1   
- [Section Field Level 2](#Section-Field-Level-2)   
    - [Section Field Level 3](#Section-Field-Level-3)   
        - [Section Field Level 4](#Section-Field-Level-4)   
        - [Section Field Level 4](#Section-Field-Level-4)   
            - [Section Field Level 5](#Section-Field-Level-5)   
        - [Section Field Level 4](#Section-Field-Level-4)   
            - [Section Field Level 5](#Section-Field-Level-5)   
# Section Field Level 2   
## Section Field Level 3  
---   
   
#### Section Field Level 4  
---   
   
#### Section Field Level 4  
---   
   
###### Section Field Level 5  
---   
   
#### Section Field Level 4  
---   
   
###### Section Field Level 5  
---   
   

```

Section 2 File
```
# Section 2   
- [Section Field](#Section-Field)   
- [Section Field](#Section-Field)   
- [Section Field](#Section-Field)   
    - [Section Field](#Section-Field)   
        - [Section Field](#Section-Field)   
# Section Field   
# Section Field   
# Section Field   
## Section Field  
---   
   
#### Section Field  
---   
   

```