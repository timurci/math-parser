# C++ Math-Parser

## How does it work?
Shunning-yard algorithm has been used to convert input from infix to postfix expressions.\
Trigonometric functions are processed in radian as default, the setting can be changed by typing "deg" or "rad" on the console.
* shunparser file includes converting infix and operating postfix expressions
* mathprocess file includes defined variables and math functions

## Supported Variables
* pi (π) : 3.14159265359
* eu (Euler's) : 2.71828182845

## Supported Functions
* sin, cos, tan, cot
* log, ln

## Examples
__Input:__
```
67+12*4-8
```
__Output:__
```
Postfix: 67124*+8- 
Result: 107 
```
__Input:__ 
```
6*pi-2*4/45
```
__Output:__ 
```
Postfix: 6pi*24*45/- 
Result: 18.6718 
```
__Input:__ 
```
3^2+(log(100)+8)/5+sin(pi/6)
```
__Output:__ 
```
Postfix: 32^100log8+5/+pi6/sin+
Result: 11.5 
```
Please note that sin function is operated in radian by default.