#include <iostream>

struct BiList
{
  int value;
  BiList * prev, * next;
};

BiList * toBiList(int * array, size_t size);
void print(std::ostream & out, BiList * head);
void clearBiList(BiList * head);

int main()
{
  size_t i = 0;
  int number = 0;
  constexpr size_t size = 10;
  int *arr = nullptr;
  try
  {
    arr = new int[size];
  }
  catch(std::bad_alloc &)
  {
    return 1;
  }
  while (i < size && std::cin >> number && !std::cin.eof())
  {
    arr[i++] = number;
  }
  if (arr == nullptr)
  {
    return 1;
  }
  BiList * head = toBiList(arr, i);
  print(std::cout, head);
  std::cout << "\n";
  delete[] arr;
}

void print(std::ostream & out, BiList * head)
{
  BiList * subhead = head;
  while(subhead->next)
  {
    subhead = subhead->next;
  }
  while(subhead)
  {
    out << subhead->value;
    BiList * prev = subhead->prev;
    delete subhead;
    subhead = prev;
    if (subhead != nullptr)
    {
      out << " ";
    }
  }
}

BiList * toBiList(int * arr, size_t size)
{
  BiList * head = new BiList{arr[0], nullptr, nullptr};
  BiList * subhead = head;
  for (size_t i = 0; i < size; i++)
  {
    BiList * record = nullptr;
    try
    {
      record = new BiList{arr[i], subhead, nullptr};
    }
    catch (const std::bad_alloc &)
    {
      clearBiList(head);
      throw;
    }
    subhead->next = record;
    subhead = record;
  }
  return head;
}

void clearBiList(BiList * head)
{
  BiList * subhead = head;
  while (subhead != nullptr)
  {
    BiList * next = subhead->next;
    delete subhead;
    subhead = next;
  }
}
