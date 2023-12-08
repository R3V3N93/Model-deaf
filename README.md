# Model-deaf

## Easy `Frameindex` generator for `MODELDEF`
### What is this?
This is a tool for [ZDOOM](https://zdoom.org/) modders who utilize 3d models, especially if they are dealing with tedious amount of animation frames.
### How to use?
You need to either make a ``shortcut`` to this program, run it from `CMD`, or write a simple `batch/powershell program` to give it `command parameters`. Then, you can get the result from ``modeldeaf.output`` file (You should be able to open the file with notepad) generated in the folder where the program was run. Following are supported command parameters.
#### 1. -framename [3~4 digits text] (default `R3V`)
##### Frameindex `XXXX` A 0 0 


This sets the sprite names where the animations are allocated.
###### 
When you pass _3 digits_, possible ``-framenumber`` range becomes ``0 ~ 935``, however, if _4 digits_ are passed, the range is only ``0 ~ 25``.

#### 2. -framenumber [0 ~ 935] (default `0`)
##### Frameindex XXXX A 0 `0`
This sets the maximum amount of animation frames. Keep in mind that the frame number starts from `0 to the given value`, so if you want to generate `n` frames, the value you must pass to the parameter is `n-1`.

#### 3. -modelnumber [... > 0] (default `1`)
##### Frameindex XXXX A `0` 0
This tells the program how many copies of each frameindex lines per model. For example, if you pass _2_ to this parameter, you get this:
```
Frameindex XXXX A 0 0
Frameindex XXXX A 1 0
```
#### 4. Example
``
modeldeaf.exe -framename R3V -framenumber 69 -modelnumber 1``
you'll get these from the command:
[](https://hatebin.com/dffrayurrh)https://hatebin.com/dffrayurrh
### How to compile this program?
idk




