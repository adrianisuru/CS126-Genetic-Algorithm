# Genetic Algorithm Image Evolution

This program approximates images using a genetic algorithm.

Ex.

| ***Original***   | ***Evolution***  |
| -------------    | ------------- |
| <img src="/img/mona.png" alt="source" width="150" height="150"/>     | <img src="/img/mona_evol_113968.png" alt="evolution" width="150" height="150"/>  |

| ***Original***   | ***Evolution***  |
| -------------    | ------------- |
| <img src="/img/evans.png" alt="source" width="150" height="150"/>     | <img src="/img/evans_evol.png" alt="evolution" width="150" height="150"/>  |

It suports loading and saving `png` files only.


### Build instructions

Make sure you have [openFrameworks](http://openframeworks.cc/) installed. Clone this repository then run the project generator on the cloned repo. After that open the config.make and add `-fopenmp` to **both** the `PROJECT_LDFLAGS` and the `PROJECT_CFLAGS`. The project needs [openmp](http://www.openmp.org/) because the fitness calculation is multithreaded. Now you should be able to run the Makefile (this may require root access depending on how your OF is setup).


### Development log

It is very easy to add to the development log thanks to the provided script `gen_log.sh`. Simply run the script and it will update `DEVELOPMENT.md` with all commit messages and times.
