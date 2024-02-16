#include <iostream>
using namespace std;

struct Node
{
    char data;
    struct Node* prev;
    struct Node* next;
};

int main()
{
    int choice = 0;
    char d;
    Node* Start = NULL, * End = NULL, * x;

    do
    {
        cout << "Enter 1 to Insert At Beginning" << endl;
        cout << "Enter 2 to Insert At End" << endl;
        cout << "Enter 3 to Delete from Beginning" << endl;
        cout << "Enter 4 to Delete from End" << endl;
        cout << "Enter 5 to Traverse The Linked List" << endl;
        cout << "Enter 6 to Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Data to Add at Beginning:";
            cin >> d;
            Node* q = Start;
            Start = new Node;
            Start->data = d;
            Start->prev = NULL;
            Start->next = q;

            if (q != NULL)
            {
                q->prev = Start;
            }
            if (q == NULL)
            {
                End = Start;
            }

            break;
        }

        case 2:
        {
            cout << "Enter Data to Add at End:";
            cin >> d;
            Node* q = End;
            End = new Node;
            End->data = d;
            End->prev = q;
            End->next = NULL;

            if (q != NULL)
            {
                q->next = End;
            }
            if (q == NULL)
            {
                Start = End;
            }

            break;
        }

        case 3:
        {
            if (Start != NULL)
            {
                Node* q = Start;
                Start = Start->next;
                if (Start != NULL)
                {
                    Start->prev = NULL;
                }
                else
                {
                    End = NULL;
                }
                cout << "Deleting Element: " << q->data << endl;
                delete q;
            }
            else
            {
                cout << "List Empty. Deletion Not Possible." << endl;
            }
            break;
        }

        case 4:
        {
            if (End != NULL)
            {
                Node* q = End;
                End = End->prev;

                if (End != NULL)
                {
                    End->next = NULL;
                }
                else
                {
                    Start = NULL;
                }

                cout << "Deleting Element from End: " << q->data << endl;
                delete q;
            }
            else
            {
                cout << "List Empty. Deletion Not Possible." << endl;
            }
            break;
        }

        case 5:
        {
            cout << "First to Last Order: ";
            x = Start;
            while (x != NULL)
            {
                cout << x->data << " ";
                x = x->next;
            }
            cout << endl;

            cout << "Last to First Order: ";
            x = End;
            while (x != NULL)
            {
                cout << x->data << " ";
                x = x->prev;
            }
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "Exiting the Program." << endl;
            break;
        }

        default:
        {
            cout << "Wrong Input" << endl;
            break;
        }
        }
    } while (choice != 6);

}



