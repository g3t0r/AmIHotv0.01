#include <iostream>
#include <vector>
#include <sensors/sensors.h>
#include "SensorChip.hpp"
#include "ChipGetter.hpp"
#include <ncurses.h>
#include "Graph.hpp"
#include "TempFeatureWin.hpp"
SensorChip * sensorChip;

void test() {

  std::vector < SensorChip >  chips;
  chips = ChipGetter::getChips();

  
  sensorChip = &chips[1];
  SensorChip a = *sensorChip;
  

  /*  for(auto a : chips) {
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "Adapter Name: " << a.getAdapterName() << std::endl;
    for(auto b : a.temperatureFeatures) {
      std::cout <<  "    Name: " << b.getName() << std::endl;
      std::cout <<  "    Value: " << b.getValue() << std::endl;
    }

  }*/
}


int main() {
  sensors_init(NULL);
  //test();
  // std::cout << sensorChip->getName() << "     " << &sensorChip  << std::endl;
  initscr();
  /*wborder(stdscr, 0,0,0,0,0,0,0,0);
  mvprintw(getmaxy(stdscr) -2,0, "!");
  refresh();
  getch();*/

  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  //attron(COLOR_PAIR(1));


  /*Graph graph(stdscr, 5,5);
  refresh();
  getch(); 
  graph.setHeightOfGraphFill(7);
  graph.fillGraph();
  getch();
  graph.setHeightOfGraphFill(14);
  graph.fillGraph();
  getch();
  graph.setHeightOfGraphFill(7);
  graph.fillGraph();
  getch();*/


   std::vector <SensorChip> sensorChips;
  sensorChips = ChipGetter::getChips();
  TempFeature tempFeature = sensorChips[1].temperatureFeatures[1];
  int width = strlen(tempFeature.getName()) + 4;
  getch();
  TempFeatureWin tfw(stdscr, tempFeature, 2, width);
  tfw.refresh();
  getch();





  endwin();

  return 0;
}
