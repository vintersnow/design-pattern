#include <iostream>
#include <cassert>

template<typename Item>
class ItemList;

template<typename Item>
class ItemIterator {
  using List = ItemList<Item>;

  protected:
    List* pList;
    unsigned int Elem;

  public:
    ItemIterator(List* list) {
      pList = list;
    }

    virtual void First() {
      Elem = 0;
    }

    virtual void Next() {
      if(!IsDone()) {
        Elem = 0;
      } else {
        Elem++;
      }
    }

    bool IsDone() {
      return Elem + 1 < pList->GetSize();
    }

    Item GetItem() {
      return pList->Get(Elem);
    }

};

template<typename Item>
class ItemList {
  using Iterator = ItemIterator<Item>;

  protected:
    Item* pItemAry;
    unsigned int Size;
    // Iterator* pIterator;

  public:
    unsigned int Capacity;

    ItemList(unsigned int capacity) {
      Capacity = capacity;
      pItemAry = new Item[capacity];
      // pIterator = new Iterator;
    }
    // TODO: 参照渡しかmoveするべき
    void Add(Item it) {
      assert(Size < Capacity - 1);
      pItemAry[Size++] = it;
    }

    Item pop() {
      assert(Size > 0);
      Size--;
      return pItemAry[Size];
    }

    unsigned int GetSize() {
      return Size;
    }

    Item Get(unsigned int idx) {
      assert(idx >= 0 && idx < Capacity);
      return pItemAry[idx];
    }

    Iterator* CreateIterator() {
      Iterator* tmp = new Iterator(this);
      // AddIterator(tmp);
      return tmp;
    }

  protected:
    void AddIterator(Iterator*);
};

struct item {
  int hoge;

  item(int i) {
    hoge = i;
  }
  item() : item(0) {};
};


int main(int argc, char const* argv[]) {
  ItemList<item> itemList(10);
  for (int i = 0; i < 5; i++) {
    itemList.Add(*(new item(i)));
  }

  ItemIterator<item>* itr = itemList.CreateIterator();

  std::cout << "list size: " << itemList.GetSize() << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << i << " itr.get" << itr->GetItem().hoge << std::endl;
    itr->Next();
  }
  return 0;
}
