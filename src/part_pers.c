#include <stdlib.h>

char **part_pers(int chas,int wich) {
	char **part = malloc(30);
	if (chas == 1) {
		if (wich == 1) {
		 	part[0] = "   ___  ";
           	part[1] = "  /. .\\";
           	part[2] = " (  -  )";
			return part;
		}
		if (wich == 2) {
			part[0] = "  @-=-@  ";
			part[1] = "  /. .\\  ";
			part[2] = " *\\ 3 /* ";
			return part;
		}
		if (wich == 3) {
			part[0] = "  x>x<x  ";
 			part[1] = "  { _ _ }  ";
 			part[2] = "  \\ . /  ";
			return part;
	    }
    }
	if (chas == 2) {
		if (wich == 1) {
		 	part[0] = "/\"/---\\\"\\";
           	part[1] = "'|     |' ";
            part[2] = " \\\\___//";
			return part;
		}
		if (wich == 2) {
			part[0] = "/` -V- `\\";
		 	part[1] = "| |   | |";
 			part[2] = "( /\"_\"\\ )";
			return part;
		}
		if (wich == 3) {
			part[0] = "/;|_ _|;\\";
			part[1] = "|/     \\|";
		 	part[2] = " |~~~~~| ";
			return part;
	    }
    }
	if (chas == 3) {
		if (wich == 1) {
		 	part[0] = "       ";	
         	part[1] = "  ('Y')";
         	part[2] = "       ";
			return part;
		}
		if (wich == 2) {
		 	part[0] = "       ";	
         	part[1] = "  /_v_\\";
         	part[2] = "       ";
			return part;
		}
		if (wich == 3) {
		 	part[0] = "       ";	
         	part[1] = "  <_X_>";
         	part[2] = "       ";
			return part;
		}
	}
	return part;
   } 
