# TraversalMaykr-Cpp-GUI
A C++ GUI tool to generate demon traversal related entities for Doom Eternal. This program is a rewrite and revamp of [TraversalMaykr-Py-GUI](https://github.com/elizabethany/TraversalMaykr-Py-GUI), which was based on Powerball253's [TraversalMaykr](https://github.com/PowerBall253/TraversalMaykr).

## Overview

Please see the wiki for more detailed documentation on each tab.

### General
Coordinates are meant to be input by using `where`, and then pasting it into the coordinates field. You can still manually enter them, in the format `x y z yaw`, ex. `12 34 56 90` or `13.12 509.2 87.1123 271.2`. The first two tabs don't require yaw values.

All tabs have a button for you to clear their respective output files. Otherwise, every newly generated entity will always be appended to the output file.

Output files are in the "Output" folder. If these txt files are missing, new ones should be created.

Templates are in the "Templates" folder. The program will crash if these are missing. These templates can edited, ex. changing indent, editing parameters, adding new lines, replacing `{{{VARIABLE}}}`s with a fixed name or removing them entirely.

### Traversal Info
The "Traversal Info" tab creates `idInfoTraversal` entities, which have a start & end point, and an animation that the demon will use to go from the start to the end. Used for jumping up/down ledges, crossing gaps, etc. Supports creating entities for most* demon types at once.

### Traversal Chain (General)
The "Traversal Chain (General)" tab creates `idInfo_TraversalChain` and `idInfo_TraversalPoint` entities. These function like `idInfoTraversal` entities, except that you can chain multiple points together. Supports creating entities for most* demon types at once.

### Traversal Chain (Dedicated)
The "Traversal Chain (Dedicated)" tab functions like the former, except that it creates entities specifically for the Imp and Arachnotron. This allows for the use of specialized animations, such as wall climbing, that are not possible with most other demons. Additionally, this also gives you the option to use each `idInfo_TraversalChain` entity as a hangout point, ex. Arachnotron climbs on wall and shoots from there, which are behaviours also not possible with most other demons. Note that at the time of writing, only Arachnotron hangouts work out of the box, and some of the Arachnotron animations require the use of a modified animWeb decl.

### Path Info
The "Path Info" tab creates `idInfoPath` entities, which function as goal markers for demons. The demon will try to path from it's current spot to where the `idInfoPath` is placed. Multiple entities can be chained together, though the initial `idInfoPath` must be assigned to the demon, ex. via `additionalTargets` in an `idTarget_Spawn`. The given `idInfoPath` template should be demon agnostic.

## A not comprehensive list of changes vs TraversalMaykr-Py-GUI
* Addition of Traversal Chain (Dedicated) and Path Info tabs
* Reworked UI that's somewhat scalable
* Added verification for inputs, so you can't generate an entity with missing inputs
* Added Misc. Monster type category for the first two tabs
* Added toggle to clear inputs when generating entities for the first two tabs
* Traversal Chain (General) tab no longer requires a midpoint to create a traversal chain, simplifying inputs
* Removed the config file. Most formerly configurable items are now hardcoded or are fixed paths. 😔

## Known Issues
* There are some edge cases where the program will still accept bad inputs and crash, though they shouldn't happen unless you're manually entering coordinates
* Wolf and Gladiator traversals don't work properly outside of ledge up/down & jump forward animations, since they have such a limited pool of animations. I'm still working on a way around that.
    * (Gladiator doesn't even use traversals out of the box)

## Credits
* Me
    * 😎
* Powerball253
	* Writing better function for gathering selected monster types
	* Writing function for verifying inputs
    * Various syntax/formatting improvements
	* Providing tips to help me improve my cpp in general
	* Linux compatibility
	* Writing the original TraversalMaykr, which inspired this project
