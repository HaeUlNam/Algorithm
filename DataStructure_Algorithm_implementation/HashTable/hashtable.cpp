#include<iostream>
using namespace std;

#define MAX_TABLE 10
#define PN 23

struct info{
    char name[64];
    char number[64];
};

class Node{
public:
    Node * next;
    char number[64];

    Node(char number[64])
    {
        next = 0;

        for(int i = 0; i < 64; i++)
            this->number[i] = number[i];
        
    }
};

Node * table[MAX_TABLE];

//init
void init()
{
    for(int i = 0; i < MAX_TABLE; i++)
        table[i] = 0;
}

//string to integer
//소수를 통해, 충돌이 덜 나도록 한다.
int getHashcode(char * str)
{
    /* unsigned로 해서, overflow나도 양수가 되도록 한다.*/
    unsigned long key = 0;
    unsigned long hash = 1;
    int c;

    for(int i = 0; str[i]!= 0; i++){
        key += (str[i] * hash);
        hash *= PN;
    }

    return (key % MAX_TABLE);
}

//추가
void add(info input)
{
    int key = getHashcode(input.name);

    if(table[key] == 0)
    {
        table[key] = new Node(input.number);
    }
    else
    {
        Node * cur = table[key];

        while(cur->next != 0)
            cur = cur->next;

        cur->next = new Node(input.number);
    }
}

/* 0이면 동일, 음수면 사전순으로 a가 앞, 양수면 사전순으로 b가 앞 */
int strcamp(char * a, char * b)
{
    int i = 0, j = 0;

    while(a[i] != 0)
    {
        if(a[i++] != b[j++]){
            --i; --j;
            break;
        }
    }
    return a[i] - b[j];
}

//삭제
void erase(info input)
{
    int key = getHashcode(input.name);

    Node * prev = table[key];
    Node * cur  = table[key];

    while(cur != 0)
    {
        if(strcamp(input.number, cur->number) == 0)
        {
            if(cur == prev)
            {
                table[key]->next = cur->next;
                delete cur;
            }
            else
            {
                prev->next = cur->next;
                delete cur;
            }
            return;
        }

        prev = cur;
        cur  = cur->next;
    }
    
    if(cur == 0)
        cout << "There is no data : " << input.name << '\n';
}

void print()
{
    cout << "-----------------------------------------------" << '\n';
    for(int i = 0; i < MAX_TABLE; i++)
    {
        cout <<"key : " <<  i << "||";
        Node * cur = table[i];

        while(cur != 0)
        {
            for(int j = 0; cur->number[j] != 0; j++)
                cout << cur->number[j];
            cout << " | ";
            cur = cur->next;
        }
        cout << "\n";
    }
    cout << "-----------------------------------------------" << '\n';
}

int main()
{
    init();

    add({"남해울", "010-8791-2439"});
    add({"남해울", "010-8811-2488"});
    add({"남해울", "010-8111-2487"});
    add({"남해울", "010-8411-2485"});

    add({"문의성", "010-1234-1241"});

    print();

    erase({"문의숭", "010-1234-1240"});
    
    print();

    erase({"남해울", "010-8711-2488"});

    print();

    return 0;
}