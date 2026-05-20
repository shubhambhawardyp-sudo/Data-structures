#include<iostream>
#include<queue>
using namespace std;

struct Request{
    string issue;
    int priority, time;

    bool operator<(const Request& r) const{
        if(priority == r.priority)
            return time > r.time;      // earlier request first
        return priority > r.priority;  // smaller number = higher priority
    }
};

int main(){

    priority_queue<Request> pq;
    int ch, p, timer = 0;
    string issue;

    do{
        cout<<"\n1.Insert Request";
        cout<<"\n2.Process Request";
        cout<<"\n3.Display Next Request";
        cout<<"\n4.Exit";
        cout<<"\nEnter Choice: ";
        cin>>ch;

        switch(ch){

        case 1:
            cin.ignore();

            cout<<"Enter Issue: ";
            getline(cin,issue);

            cout<<"Priority (1-Urgent 2-Moderate 3-Routine): ";
            cin>>p;

            pq.push({issue,p,timer++});
            break;

        case 2:
            if(pq.empty())
                cout<<"No Requests\n";
            else{
                cout<<"Processing: "
                    <<pq.top().issue
                    <<" (Priority "<<pq.top().priority<<")\n";
                pq.pop();
            }
            break;

        case 3:
            if(pq.empty())
                cout<<"Queue Empty\n";
            else{
                cout<<"Next Request: "
                    <<pq.top().issue
                    <<" (Priority "<<pq.top().priority<<")\n";
            }
            break;

        case 4:
            cout<<"Exit\n";
            break;

        default:
            cout<<"Invalid Choice\n";
        }

    }while(ch!=4);

    return 0;
}