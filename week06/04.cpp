/*
    [+] Create a singly linked list to manage the playlist
        a. Define a singly linked list for songs (title, artist, duration)
        b. Implement:
            i.   add a song to the beginning of the list
            ii.  display all book info in the list
            iii. search a song based on title from the list
            iv.  reverse the order of songs in the list
            v.   sort the songs based on duration using bubble sort algorithm. (swap data, not
            nodes)
*/
#include <iostream>
struct Song
{
    std::string title, artist;
    float duration;
    Song *next;
};
struct List
{
    Song *head, *tail;
    int n;
};
void stack(Song _s, List *ls)
{
    Song *s = new Song{_s.title, _s.artist, _s.duration, ls->head};
    ls->head = s;
    if (ls->n == 0)
        ls->tail = s;
    ls->n++;
}
void reverse(List *ls)
{
    Song *prev = nullptr;
    Song *current = ls->head;
    Song *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ls->head = prev;
}
void show(List *ls)
{
    Song *s = ls->head;
    while (s != nullptr)
    {
        std::cout << '[' << s->title << "] by " << s->artist << " : " << s->duration << " mn\n";
        s = s->next;
    }
}
void sort(List *ls)
{
    if (ls->n < 2)
        return;
    Song *_fP, *_lP = nullptr;
    bool swapped;
    do
    {
        _fP = ls->head;
        swapped = false;
        while (_fP->next != _lP)
        {
            if (_fP->duration > _fP->next->duration)
            {
                float tmp = _fP->duration;
                _fP->duration = _fP->next->duration;
                _fP->next->duration = tmp;
                swapped = true;
            }
            _fP = _fP->next;
        }
        _lP = _fP;
    } while (swapped);
}
int main()
{
    List *ls = new List{nullptr, nullptr, 0};
    Song _s[] = {{"See you again Orchestral", "Samuel Kim", 3.05}, {"Dear Professor Morgan", "autumn", 2.03}, {"Breathe", "Makenzie Ziegler", 3.8}};
    for (Song s : _s)
        stack(s, ls);
    for (Song s : _s)
        stack(s, ls);
    std::cout << "[+] List:\n";
    show(ls);
    std::cout << "[+] Rev List:\n";
    reverse(ls); show(ls);
    std::cout << "[+] Sorted:\n";
    sort(ls); show(ls);
}