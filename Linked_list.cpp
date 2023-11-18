#include <iostream>
using namespace std;

struct node{
float var;
node* right = nullptr;
};
static node* root = new node();
static int nodeCount(0);

void deleteAll(node *link);
void addNode(float value);


int main()
{
    float var;

    cout<< "enter numbers to add to list or -1 to exit : ";
    cin>>var;

    while(var != -1)
    {
        addNode(var);
        cout<< "enter numbers to add to list or -1 to exit : ";
        cin>> var;
    }

    //Displaying the output
    cout<< endl << "Displaying before deleting all items"<<endl;
    cout<<"-------------------------------------"<<endl;
    node *temp = root;
    while(temp!= nullptr)
    {
        cout<< "My value = " << temp->var << endl;
        cout<< "My own adress = "<< temp <<endl;
        cout<< "My neighbour address = " << temp->right <<endl<<endl;
        temp = temp->right;
    }

    //Displaying the output
    cout << endl << "Displaying after deleting all items" << endl;
    deleteAll(root);
    delete temp;

    return 1;
}

void addNode(float value)
{
    //Add child to root
    if (root->right == nullptr)
    {
        node *temp = new node();
        root->right = temp;
        temp->var = value;
        temp->right = nullptr;
        //Increment nodeCount
        nodeCount++;

    }else
    {
        node *link = root->right;
        //Traverse until reach the end of the list
        while(link->right!=nullptr)
        {
            link = link->right;
        }
        //We reached an end
        node *temp = new node();
        temp->var = value;
        temp->right = nullptr;
        link->right = temp;
        //Increment nodeCount
        nodeCount++;
    }
}

void deleteAll(node *link)
{

    node* temp = link;
    link = temp->right;
    cout<< "Current Total Nodes: " << nodeCount << endl;

    delete temp;
    //Decrement nodeCount
    nodeCount--;
    deleteAll(link);
}
