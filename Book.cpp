#include<iostream>
using namespace std;

struct node
{
    char label[50];
    int ch_count;
    node *child[10];
};

class GT
{
    node *root;

public:
    GT()
    {
        root = NULL;
    }

    void create_tree()
    {
        int tchapters, i, j;

        root = new node;

        cout<<"\nEnter name of book:\n";
        cin>>root->label;

        cout<<"\nEnter no. of chapters:\n";
        cin>>tchapters;

        root->ch_count = tchapters;

        for(i=0;i<tchapters;i++)
        {
            root->child[i]=new node;

            cout<<"\nEnter Chapter name:\n";
            cin>>root->child[i]->label;

            cout<<"\nEnter no. of sections in "
                <<root->child[i]->label<<endl;

            cin>>root->child[i]->ch_count;

            for(j=0;j<root->child[i]->ch_count;j++)
            {
                root->child[i]->child[j]=new node;

                cout<<"Enter Section "<<j+1<<" name\n";
                cin>>root->child[i]->child[j]->label;
            }
        }
    }

    void display()
    {
        int i,j,tchapters;

        if(root!=NULL)
        {
            cout<<"\n-----Book Hierarchy-----\n";
            cout<<"\nBook title: "<<root->label;

            tchapters=root->ch_count;

            for(i=0;i<tchapters;i++)
            {
                cout<<"\n\tChapter "<<i+1<<" : "
                    <<root->child[i]->label;

                cout<<"\n\t\tSections:";

                for(j=0;j<root->child[i]->ch_count;j++)
                {
                    cout<<" --> "
                        <<root->child[i]->child[j]->label;
                }
            }
        }
    }
};

int main()
{
    int choice;
    GT gt;

    while(1)
    {
        cout<<"\n1.Create";
        cout<<"\n2.Display";
        cout<<"\n3.Quit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
            gt.create_tree();

        else if(choice==2)
            gt.display();

        else if(choice==3)
            break;
    }

    return 0;
}