# Development Log
### Started genetic algorithm implementation

(Wed Apr 25 10:53:52 2018)

Refactored DNA. DNA::Gene now stores its fields as integers. Implemented rule of five for DNA.

Wrote basic genetic algorithm. It seems to not give good results though. Ill have to test this more to make sure it is really working.


### Mock up gui finished

(Wed Apr 25 00:29:25 2018)

Gui now displays original, best, and evolving with scaling on resize.

Added function to randomize initial dna.

Still need to implemenent the algorithm. DNA class will need to be modified to take into account bounds of each field (ex. r must be between 0 - 255 or cx must be between 0 and img_width)


### Started gui with buttons

(Mon Apr 23 13:11:56 2018)

There is now a gui to open png files.

Added EvolveImage class.

Still need to figure out how to draw shapes to an image.

When an image is selected with the file chooser it shows up discolored when drawn to the window. Still need to fix this issue.


### Added file dialog.

(Fri Apr 20 09:34:24 2018)

Now images can be chosen using a file dialog.


### Wrote DNA and Gene class.

(Fri Apr 20 07:51:59 2018)

Gene stores data of circles color and position as well as a blank section (this simulates garbage mutations). Members of both are accessed with [] to make randomly choosing a field easier.

Scratched model, view, controller in favor of a more openFrameworks-ey style.
(main + ofApp) The view and controller will both be in evolve_app.cpp.

Upadated gen_log.sh. Now it stashes changes before updating DEVELOPMENT.md


### Wrote script to generate dev log.

(Thu Apr 19 11:08:59 2018)

Created src/evolve/ for files relating to the genetic algorithm.


### Tested image loading.

(Thu Apr 19 10:40:29 2018)



### Got OF gui working

(Wed Apr 18 23:09:57 2018)



### Setup project structure

(Wed Apr 18 20:13:57 2018)

Made OF project.
Model, View, Controller model
added development log DEVELOPMENT.md


### Wrote project proposal (PROPOSAL.md)

(Tue Apr 10 20:57:12 2018)



### Update PROPOSAL.md

(Wed Apr 4 18:08:21 2018)



### Create PROPOSAL.md

(Wed Apr 4 18:07:54 2018)



### Create README.md

(Wed Apr 4 18:07:35 2018)


