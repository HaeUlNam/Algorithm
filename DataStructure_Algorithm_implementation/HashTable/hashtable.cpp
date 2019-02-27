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
    info data;

    Node(info aa)
    {
        next = 0;

        this-> data = aa;
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

//번호 추가
void add(info input)
{
    int key = getHashcode(input.name);

    if(table[key] == 0)
    {
        table[key] = new Node(input);
    }
    else
    {
        Node * cur = table[key];

        while(cur->next != 0)
            cur = cur->next;

        cur->next = new Node(input);
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

//사람에 해당하는 번호 삭제
void erase(info input)
{
    int key = getHashcode(input.name);

    Node * prev = table[key];
    Node * cur  = table[key];

    while(cur != 0)
    {
        if(strcamp(input.name, cur->data.name) == 0)
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

//특정 사람의 번호 찾기
void search(info input)
{
    int key = getHashcode(input.name);

    Node * prev = table[key];
    Node * cur  = table[key];

    bool check = false;
    info result;

    while(cur != 0)
    {
        if(strcamp(input.name, cur->data.name) == 0)
        {
            check = true;
            result = cur->data;
            break;
        }

        prev = cur;
        cur  = cur->next;
    }

    if(!check)
        cout << "There is no data : " << input.name << '\n';
    else
        cout << result.name << " :" << result.number << "\n";
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
            for(int j = 0; cur->data.name[j] != 0; j++)
                cout << cur->data.name[j];
            cout << ": ";
            for(int j = 0; cur->data.number[j] != 0; j++)
                cout << cur->data.number[j];
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

    add({"영등포", "010-8791-2439"});
    add({"황해해", "010-8411-2488"});
    add({"울울울", "010-8111-2487"});
    add({"유유융", "010-8411-2485"});

    add({"이의무", "010-1234-1241"});

    print();

    erase({"이의무", "010-1234-1241"});
    
    print();

    erase({"율율율", "010-8411-2488"});
    search({"유유융", "010-8411-2485"});

    print();

    return 0;
}

/* 한 사람에게 하나의 번호만 배정된다고 가정한다.*/