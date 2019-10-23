# HLML

(High Level Maths Library).

[![Build Status](https://travis-ci.com/floorman/HLML.svg?branch=master)](https://travis-ci.com/floorman/HLML)

HLML is a maths library for C++ (with C99 support planned) focused on games/graphics programming which is loosely styled on HLSL syntax where all vector/matrix types are generated by a tool.  This means that there are zero templates in the generated code, which gives the following advantages:
* Shorter compile times.
* Easier to read and debug.
* Ability to forward declare types.

As well as the above, HLML also offers the following:
* SIMD helper maths functions (experimental: in progress).
* Non-uniform matrix types.
* Boolean vectors to aid equality checking of vector types.

Currently HLML is written to produce optimised assembly for clang.  If you use another compiler then YMMV.

HLML doesn't override any maths functions that are a part of C99.

See the "Licenses" section below for details about what licenses HLML uses.


Installation
============

1. Go to the [releases](https://github.com/floorman/HLML/releases) page and download the latest version.
2. Unzip the header files into your project.
3. **OPTIONAL:** Run ```hlm-gen-tests.exe``` (you shouldn't need to have a reason to run this and everything 'should just work', but you never know...).
4. Done!


Usage
=====
Include ```hlml.h```.

For more detailed documentation on how to use HLML's experimental SSE functionality, please refer to [the SSE document](https://github.com/floorman/HLML/blob/simd/doc/SSE.md).


Code Examples
=============

Adding 2 vectors:
```C
float3 a = { 1.0f, 2.0f, 3.0f }; // you can initialise math types like this
float3 b = float3( 4.0f, 5.0f, 6.0f ); // or like this

float3 c = a + b;

printf( "c is: (%f, %f, %f)", c.x, c.y, c.z );
```

Creating a Model-View-Projection matrix:
```C
float4x4 model = translate( player_transform, position );

// lh = left handed, zo = zero-to-one depth
// there also exists rh (right-handed) and no (negative-one-to-one) combinations
float4x4 view = lookat_lh_zo( eye, forward, world_up );

float4x4 projection = perspective_lh_zo( fov, aspect, znear, zfar );

// performs matrix multiplication, not per-component multiplication
float4x4 mvp = model * view * projection;
```

Vector Swizzling:
```C
float4 a = { 1.0f, 2.0f, 3.0f, 4.0f };
float4 b = a.xxyy(); // all possible combinations are automatically generated and available
```


Common Pitfalls
===============

**READ THIS BEFORE USING HLML:**

* All library functions and tests using floating point were written to be as respective to the IEEE-754 standard as possible.
* All matrix types are row-major, so a ```float3x4``` is a matrix that holds 3 ```float4```s (or, in other words: a ```float4``` array of size 3).
* All vector types are union of ```struct```/fixed-size array.
* HLML is focused on mathemetical expressive power where possible, therefore:
	* All matrices have the ```*``` operator overloaded to do matrix multiplication, **NOT** a component-wise multiplication.
	* All square matrices with floating point types have the ```/``` operator overloaded to multiply the light-hand matrix by the inverse of the right-hand matrix, it does **NOT** do a component-wise divide.
		* If you want to do a component-wise multiply or divide with matrices, you will need the functions `comp_mul` and `comp_div`, respectively.
* To avoid conflicts with Windows ```min```/```max``` macros, you can define ```NOMINMAX``` before including HLML.


Contributing
============

If this is a project you'd like to contribute to, I'm open to pull requests.  The GitHub issue tracker is being used.

Performance and usability are the two primary goals of the API.  If at any time those two goals are in confliction with each other, default to common sense.  =)


Motivation
==========

I've always primarily used GLM as my maths library of choice, but there were a few things that always bugged me about it:
* Types don't get initialised to default values by design.
* Sometimes had trouble reading past all of the templates.
* Often have trouble debugging the templates.
* Typing the namespace all the time got annoying.

(This isn't an attack on GLM, just some of my personal gripes with it).

One day I stumbled upon the [Unity.Mathematics](https://github.com/Unity-Technologies/Unity.Mathematics) library where I saw that all the maths types were being generated via a tool.  I decided to try the same but for C++: Write a tool that generated maths types for me to see if there were any benefits of doing it that way, and I found that there were:
* Compile times were shorter due to lack of templates.
* Being able to "Peek Definition" on a type in Visual Studio and see just the header with that type in it.  No templates to read past, just very simple, minimal, and straightforward code.
* Maintaining changes across multiple (if not all) types was a lot easier than imagined.  Write the changes into the generator and watch it reflect the change across all the desired generated types automatically.


Licenses
========

All code that is part of the generator is licensed under GNU GPL v3.  All of the generated code (found in the releases) are licensed under MIT license.  Please see the respective license files (found in the root of this project) for details.

HLML's generator also makes use of the following libraries, which are under their own respective licenses:

- [Temper](https://github.com/floorman/temper) - MIT
