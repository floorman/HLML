# HLML

(High Level Maths Library).

HLML is a C++ maths library (focused for game development) which is styled on HLSL syntax where all vector/matrix types are generated by a tool.  This means that no HLML types are templated, which gives the following advantages:
* (Theoretically) Shorter compile times.
* Easier to read and debug.
* Ability to forward declare types.

As well as the above, HLML also offers the following:
* SIMD helper maths functions.
* Non-uniform matrix types.
* Boolean vectors to aid equality checking of vector types.

Currently HLML is written to produce optimised assembly for clang, if you use another compiler then YMMV.

HLML is distributed under the GNU GPL v3 license.  See "LICENSE.md" for details.


Usage
=====

A few quick notes on usage:
* All matrix types are row-major.  So a ```float3x4``` is a ```float4``` array of size 3.
* All vector types are union of ```struct```/fixed-size array.

To use HLML in your project, simply download the ```out``` folder listed in the project's root directory and drop it in your project.  Then you can begin to include all the headers you need and just start using the library.  HLML is a header-only library, so there's no linking required to make it work.


Motivation
==========

I've always primarily used GLM as my maths library of choice, but there were a few things that always bugged me about it:
* No default initialization of types.
* Sometimes had trouble reading past all of the templates.
* Often have trouble debugging templates.
* Typing the namespace all the time got annoying.

(This isn't an attack on GLM, just some of my personal gripes with it).

One day I stumbled upon the [Unity.Mathematics](https://github.com/Unity-Technologies/Unity.Mathematics) library where I saw that all the maths types were being generated via a tool.  I decided to try the same but for C++: Write a tool that generated maths types for me to see if there were any benefits of doing it that way, and I found that there were:
* Compile time differences between the "generated" code and a templated equivalent were so minimal they weren't worth worrying about.
* Being able to "Peek Definition" on a type in Visual Studio and see just the header with that type in it.  No templates to read past, just very simple, minimal, and straightforward code.
* Maintaining changes across multiple (if not all) types was a lot easier than imagined.  Write the changes into the generator and watch it reflect the change across all the desired generated types automatically.