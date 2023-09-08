#include<iostream>

using namespace std;

#include "ProductionGraph.h"

using namespace std;

int main() {
    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";

    int numOfPlants;
    cout << "Enter number of plants for graph:";
    cin >> numOfPlants;

    ProductionGraph *graph = new ProductionGraph(numOfPlants);
    graph->inputData();
    graph->display();

}