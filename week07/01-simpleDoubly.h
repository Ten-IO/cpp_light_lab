struct Element
{
    int num;
    Element *next, *prev;
};
struct ListLinked
{
    int n;
    Element *head, *tail;
};

void showFront(ListLinked *ls);
void addPos(ListLinked *ls, int num, int pos);
void addEnd(ListLinked *ls, int num);
void addBeg(ListLinked *ls, int num);
ListLinked *initList();