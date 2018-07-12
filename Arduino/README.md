The parts in use here are:

* Arduino nano clone 
https://www.amazon.com/gp/product/B0713XK923/ref=oh_aui_search_detailpage?ie=UTF8&psc=1
* Nano Ethernet Shield 
https://www.amazon.com/gp/product/B01J5I1OYI/ref=oh_aui_search_detailpage?ie=UTF8&psc=1
* Sparkfun IR 8x8 camera 
https://www.sparkfun.com/products/14607

This folder contains some test sketches for each of these, and the main program "HeatCamOsc" we will use.

Address of the device will be 10.0.0.50

The device will read in a 8 x 8 array of values from teh IR camera and send them to the main animation computer via OSC UDP packets every x seconds.  The animation computer will use this information as a heat map input to detect when the Ray passes over 1, 2 or more people.  This will be the main input for the animation.
