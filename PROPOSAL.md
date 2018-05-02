# Project Proposal

### Plan
I'm planning to do genetic algorithm image evolution, shown [here](https://rogerjohansson.blog/2008/12/07/genetic-programming-evolution-of-mona-lisa/) and [here](http://alteredqualia.com/visualization/evolve/).
[Genetic algorithms](https://en.wikipedia.org/wiki/Genetic_algorithm) are used to solve optimization problems, in this case, drawing a picture. There are two parts to a genetic algorithm. First there needs to be a [genetic representation](https://en.wikipedia.org/wiki/Genetic_representation) of the data. I want to generate my images using simple shapes (probably circles, not sure yet though) so my genetic representation will be the coordinates and colors of those shapes. Second there has to be a fitness function to evaluate the members of each generation. I will probably compare raw pixel data between the source image and the generated images but other fitness functions are possible.

The program will first load a source image. Then it will generate a random set of "dna" (data representing the position and color of many drawn shapes). From this "dna" a "parent" image will be produced. Next it will "mutate" this "dna" (change values by some small, probably random, delta) a few times to produce a few different "child" images. The "child" image that most closely matches the source (has the highest fitness) will become the new parent. Reating this process over many "generations" can produce fairly acurate results.


Here is a picture of me I generated with hexagons using [this website](http://alteredqualia.com/visualization/evolve/) (92% accurate)

| ***Original***   | ***Evolution***  |
| -------------    | ------------- |
| <img src="/img/proposal_source.png" alt="source" width="150" height="150"/>     | <img src="/img/proposal_evolution.png" alt="evolution" width="150" height="150"/>  |



### Required Libraries
I will use OF for the windowing and image processing. We haven't done any image processing with OF so that will be my library not discussed in class. This project would benefit greatly from parallel computation so I might use a parallel computing library such as [OpenMP](http://www.openmp.org/).

### Relevant Background
I have some background in OpenGL so instead of using OpenMP I might just write shaders to do parallel processing. (This I don't have background though. I've written shaders solely to display graphics) I've also tried to do this project before in C# a few years ago. It didn't work out so well because many of my methods were very inefficient (tripley nested for loops, etc)
