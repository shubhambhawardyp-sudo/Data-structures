// Design a hash table for a product inventory system where keys are
// product IDs, and values are stock details. Implement separate
// chaining and linear probing for collision handling. Analyze time
// complexity.
#include<iostream>
using namespace std;

class Node{
public:
    int id, qty;
    string name;
    float price;
    Node *next;

    Node(int i,string n,int q,float p){
        id=i;
        name=n;
        qty=q;
        price=p;
        next=NULL;
    }
};

class HashTable{

    Node* chain[10];

    int lid[10], lqty[10];
    string lname[10];
    float lprice[10];

public:

    HashTable(){

        for(int i=0;i<10;i++){

            chain[i]=NULL;

            lid[i]=-1;
            lname[i]="";
            lqty[i]=0;
            lprice[i]=0;
        }
    }

    // ===== SEPARATE CHAINING =====

    void insertChain(int id,string name,int qty,float price){

        int index=id%10;

        Node* temp=new Node(id,name,qty,price);

        temp->next=chain[index];
        chain[index]=temp;

        cout<<"Product Inserted\n";
    }

    void searchChain(int id){

        int index=id%10;

        Node* temp=chain[index];

        while(temp!=NULL){

            if(temp->id==id){

                cout<<"\nProduct Found\n";
                cout<<"ID: "<<temp->id<<endl;
                cout<<"Name: "<<temp->name<<endl;
                cout<<"Quantity: "<<temp->qty<<endl;
                cout<<"Price: "<<temp->price<<endl;

                return;
            }

            temp=temp->next;
        }

        cout<<"Product Not Found\n";
    }

    void displayChain(){

        cout<<"\n------------- HASH TABLE -------------\n";
        cout<<"Index\tData\n";
        cout<<"--------------------------------------\n";

        for(int i=0;i<10;i++){

            cout<<i<<"\t";

            Node* temp=chain[i];

            if(temp==NULL)
                cout<<"NULL";

            while(temp!=NULL){

                cout<<"["<<temp->id
                    <<","<<temp->name
                    <<","<<temp->qty
                    <<","<<temp->price<<"]";

                if(temp->next!=NULL)
                    cout<<" -> ";

                temp=temp->next;
            }

            cout<<endl;
        }
    }

    // ===== LINEAR PROBING =====

    void insertLinear(int id,string name,int qty,float price){

        int index=id%10;
        int start=index;

        while(lid[index]!=-1){

            index=(index+1)%10;

            if(index==start){

                cout<<"Hash Table Full\n";
                return;
            }
        }

        lid[index]=id;
        lname[index]=name;
        lqty[index]=qty;
        lprice[index]=price;

        cout<<"Product Inserted\n";
    }

    void searchLinear(int id){

        int index=id%10;
        int start=index;

        while(lid[index]!=-1){

            if(lid[index]==id){

                cout<<"\nProduct Found\n";
                cout<<"ID: "<<lid[index]<<endl;
                cout<<"Name: "<<lname[index]<<endl;
                cout<<"Quantity: "<<lqty[index]<<endl;
                cout<<"Price: "<<lprice[index]<<endl;

                return;
            }

            index=(index+1)%10;

            if(index==start)
                break;
        }

        cout<<"Product Not Found\n";
    }

    void displayLinear(){

        cout<<"\n-------- HASH TABLE --------\n";

        cout<<"Index\tID\n";
        cout<<"----------------------------\n";

        for(int i=0;i<10;i++){

            cout<<i<<"\t";

            if(lid[i]==-1){
                cout<<"EMPTY";
            }
            else{
                cout<<lid[i];
            }

            cout<<endl;
        }
    }
};

int main(){

    HashTable h;

    int method, choice;
    int id, qty;
    string name;
    float price;

    cout<<"1. Linear Probing\n";
    cout<<"2. Separate Chaining\n";
    cout<<"Choose Method: ";
    cin>>method;

    while(true){

        cout<<"\n========== MENU ==========\n";
        cout<<"1. Insert Product\n";
        cout<<"2. Search Product\n";
        cout<<"3. Display Hash Table\n";
        cout<<"4. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

        case 1:

            cout<<"Enter Product ID: ";
            cin>>id;

            cout<<"Enter Product Name: ";
            cin>>name;

            cout<<"Enter Quantity: ";
            cin>>qty;

            cout<<"Enter Price: ";
            cin>>price;

            if(method==1)
                h.insertLinear(id,name,qty,price);
            else
                h.insertChain(id,name,qty,price);

            break;

        case 2:

            cout<<"Enter Product ID to Search: ";
            cin>>id;

            if(method==1)
                h.searchLinear(id);
            else
                h.searchChain(id);

            break;

        case 3:

            if(method==1)
                h.displayLinear();
            else
                h.displayChain();

            break;

        case 4:

            cout<<"Program Ended\n";
            return 0;

        default:

            cout<<"Invalid Choice\n";
        }
    }
}