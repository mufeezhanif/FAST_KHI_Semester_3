#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>

using namespace std;
class Card
{
public:
    char rank;
    char suit;

    Card(int Rank, char suit)
    {
        if (Rank > 10)
        {
            switch (Rank)
            {
            case 11:
            {
                rank = 'J';
                break;
            }
            case 12:
            {
                rank = 'Q';
                break;
            }
            case 13:
            {
                rank = 'K';
                break;
            }
            case 14:
            {
                rank = 'A';
                break;
            }
            }
        }
        else
        {
            rank = Rank;
        }
        this->suit = suit;
    }
};

class Node
{
public:
    Card *card;
    Node *next;
    Node(int Rank, char suit)
    {
        card = new Card(Rank, suit);
        next = nullptr;
    }
};

class LL
{
public:
    Node *head;
    Node *tail;
    int size;
    LL()
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
    }
    void addNewCard(int Rank, char suit)
    {
        ++size;
        if (!head)
        {
            Node *newNode = new Node(Rank, suit);
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *newNode = new Node(Rank, suit);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    Node *throughCard(int Rank, char suit)
    {
        Node *temp = head;
        Node *found = nullptr;
        if (temp->card->rank == Rank && temp->card->suit == suit)
        {
            found = temp;
            head = head->next;
        }
        while (temp->next)
        {
            if (temp->next->card->rank == Rank && temp->next->card->suit == suit)
            {
                found = temp;
                cout << "\nCard found\n"
                     << endl;
                --size;
                return found;
            }
        }
        cout << "Card Not Found, please enter correct card";
        return nullptr;
    }
    void DisplayCards()
    {
        Node *temp = head;
        cout << "Displaying Cards: " << endl;
        while (temp)
        {
            cout << temp->card->rank << " " << temp->card->suit << endl;
            ;
        }
    }
};

class Player
{
public:
    int points;
    LL *cards;
    Player()
    {
        cards = new LL();
        points = 0;
    }

    Node *PlayCard(int Rank, char suit)
    {
        return cards->throughCard(Rank, suit);
    }

    void assignCard(int Rank, char suit)
    {
        cards->addNewCard(Rank, suit);
        cout << "Cards added successfullty" << endl;
    }
};

int generateRandomRank()
{
    int rank = rand(2, 14);
}
char generateRandomSuit()
{
    int temp = rand(1, 4);
    char ch;
    switch (temp)
    {
    case 1:
        ch = 'h';
        break;
    case 2:
        ch = 'd';
        break;
    case 3:
        ch = 's';
        break;
    case 4:
        ch = 'c';
        break;

    default:
        break;
    }
    return ch;
}
class Game
{
    Player *p1;
    Player *p2;

    Game()
    {
        p1 = new Player();
        p2 = new Player();
        cout << "Assigning cards to both player" << endl;
        for (int i = 0; i < 7 ++i)
        {
            int Rank = generateRandomRank();
            char suit = generateRandomSuit();
            p1->assignCard(Rank, suit);
            Rank = generateRandomRank();
            suit = generateRandomSuit();
            p2->assignCard(Rank, suit);
        }
        cout << "Cards Assigned" << endl;
    }

    void startGame()
    {
        for (int i = 0; i < 7; ++i)
        {
            int Rank;
            char suit;
            cout << "player 1 turn: " << endl;
            p1->cards->DisplayCards();
            cout << "Enter rank: ";
            ci >> Rank;
            cout << "Enter suit: ";
            ci >> suit;
            Node *p1Card = p1->cards->throughCard(Rank, suit);
            if (checkAce(p1Card))
            {
                p1->points += 5;
                continue;
            }
            cout << "player 2 turn: " << endl;
            p2->cards->DisplayCards();
            cout << "Enter rank: ";
            ci >> Rank;
            cout << "Enter suit: ";
            ci >> suit;
            Node *p2Card = p2->cards->throughCard(Rank, suit);
            if (checkAce(p2Card))
            {
                p2->points += 5;
                p1->assignCard(p1Card->card->rank, p1Card->card->suit);
                continue;
            }
            if (p1Card->card->suit == p2Card->card->suit)
            {
                if (p1Card->card->rank > p2Card->card->rank)
                {
                    p1->points += 2;
                }
                else
                {
                    p2->points += 2;
                }
            }
            else
            {
                if (returnPrecedence(p1Card->card->suit) > returnPrecedence(p2Card->card->suit))
                {
                    p1->assignCard(p1Card->card->rank, p1Card->card->suit);
                    p1->assignCard(p2Card->card->rank, p2Card->card->suit);
                    p1->points -= 2;
                }
            }
        }
        if (p1->cards->size > p2->cards->size)
        {
            p1->points -= 3;
        }
        else
        {
            p2->points -= 3;
        }
        if (p1->points > p2->points)
        {
            cout << "PLayer 1 wins";
        }
        else if (p1->points < p2->points)
        {
            cout << "PLayer 2 wins";
        }
        else
        {
            cout << "Draw";
        }
    }
    int returnPrecedence(char ch)
    {
        switch (char)
        {
        case 'c':
            return 3;
        case 's':
            return 2;
        case 'h':
            return 1;
        case 'd':
            return 0;
        }
    }
    bool checkAce(Node *card)
    {
        if (card->card->rank == 'A')
        {
            return true;
        }
        return false;
    }
};
int main()
{
    srand(time(0));
    cout << "23k0800" << endl;
    return 0;
}