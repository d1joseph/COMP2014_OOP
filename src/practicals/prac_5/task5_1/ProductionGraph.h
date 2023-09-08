#ifndef PRODUCTIONGRAPH_H_
#define PRODUCTIONGRAPH_H_

class ProductionGraph {
private:
    int numOfPlants;
    int* production;
public:
    ProductionGraph(int size);
    ~ProductionGraph();
    void getTotal(int& amount);
    void display();
    void printAsterisks(int n);
    void inputData();
};

ProductionGraph::ProductionGraph(int size) {
    numOfPlants = size;
    production = new int[numOfPlants];
}

ProductionGraph::~ProductionGraph() {
    delete[] production; 
}

void ProductionGraph::getTotal(int& amount) {
    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n" << endl;
    cin >> amount;
    while (amount < 0)
    {
        cout<<"input again" << endl;
        cin >> amount;
    }
}

void ProductionGraph::inputData() {
    for (int i = 1; i <= numOfPlants; i++)
    {
        cout << endl
             << "Enter production data for plant number "
             << i << endl;
        getTotal(production[i - 1]);
    }
}

void ProductionGraph::display() {
    cout << "\nUnits produced in units:\n";
    for (int i = 1; i <= numOfPlants; i++)
    {
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void ProductionGraph::printAsterisks(int n) {
    for (int count = 1; count <= n; count++)
        cout << "*";
}

#endif // PRODUCTIONGRAPH_H_