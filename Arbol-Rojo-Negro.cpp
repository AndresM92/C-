/**
 * This is an implementation of the Red-Black Tree data structure.
 *
 * Huge amounts of code has been taken from:
 * - http://www.sanfoundry.com/cpp-program-implement-red-black-tree/
 * - http://en.wikipedia.org/wiki/Red%E2%80%93black_tree
 * - https://gist.github.com/upsuper/6332576
 *
 * The only purpose of this implementation should be academic.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#define INDENT_STEP 4

using namespace std;

/*
 * Class RBTree Declaration
 */
template <typename Key, typename Value>
class RBTree {
private:
  enum class Color { RED, BLACK };

  /*
   * Node in a red black tree
   */
  class Node {
  private:
    Key key;
    Value value;
    Color color;
    Node* parent, *left, *right;

  public:
    Node(Key k, Value v, Color n_color, Node* l, Node* r) {
      key = k;
      value = v;
      color = n_color;
      left = l;
      right = r;
      if (left != NULL) left->parent = this;
      if (right != NULL) right->parent = this;
      parent = NULL;
    }

    Node* getParent(void) { return parent; }
    void setParent(Node* newParent) { parent = newParent; }

    Node* getLeft(void) { return left; }
    void setLeft(Node* newLeft) { left = newLeft; }

    Node* getRight(void) { return right; }
    void setRight(Node* newRight) { right = newRight; }

    Color getColor(void) { return color; }
    void setColor(Color newColor) { color = newColor; }

    Key getKey(void) { return key; }
    Value getValue(void) { return value; }
    void setValue(Value newValue) { value = newValue; }

    bool hasRightChild(void) const { return right != NULL; }
    bool hasLeftChild(void) const { return left != NULL; }
  };

private:
  Node* root_;
  int size_;

public:
  /**
   * @brief Creates an empty tree
   */
  RBTree(void) {
    root_ = NULL;
    size_ = 0;
    verifyProperties();
  }

  /**
   * @brief Returns the number of elements in the tree
   */
  int size(void) const { return size_; }

private:
  /*
   * Return Grandparent of Node
   */
  Node* grandparent(Node* n) {
    assert(n != NULL);
    assert(n->getParent() != NULL);
    assert(n->getParent()->getParent() != NULL);
    return n->getParent()->getParent();
  }
  /*
   * Return Sibling of Node
   */
  Node* sibling(Node* n) {
    assert(n != NULL);
    assert(n->getParent() != NULL);
    if (n == n->getParent()->getLeft())
      return n->getParent()->getRight();
    else
      return n->getParent()->getLeft();
  }

  /*
   * Return Uncle of Node
   */
  Node* uncle(Node* n) {
    assert(n != NULL);
    assert(n->getParent() != NULL);
    assert(n->getParent()->getParent() != NULL);
    return sibling(n->getParent());
  }

  /*
   * Verifying Properties of Red black Tree
   */
  void verifyProperties(void) {
    verifyProperty1(root_);
    verifyProperty2(root_);
    verifyProperty4(root_);
    verifyProperty5(root_);
  }
  /*
   * Verifying Property 1
   */
  void verifyProperty1(Node* n) {
    assert(node_color(n) == Color::RED || node_color(n) == Color::BLACK);
    if (n == NULL) return;
    verifyProperty1(n->getLeft());
    verifyProperty1(n->getRight());
  }
  /*
   * Verifying Property 2
   */
  void verifyProperty2(Node* root) { assert(node_color(root) == Color::BLACK); }

  /*
   * Returns color of a node
   */
  Color node_color(Node* n) { return n == NULL ? Color::BLACK : n->getColor(); }
  /*
   * Verifying Property 4
   */
  void verifyProperty4(Node* n) {
    if (node_color(n) == Color::RED) {
      assert(node_color(n->getLeft()) == Color::BLACK);
      assert(node_color(n->getRight()) == Color::BLACK);
      assert(node_color(n->getParent()) == Color::BLACK);
    }
    if (n == NULL) return;
    verifyProperty4(n->getLeft());
    verifyProperty4(n->getRight());
  }

  /*
   * Verifying Property 5
   */
  void verifyProperty5(Node* root) {
    int black_count_path = -1;
    verifyProperty5(root, 0, &black_count_path);
  }

  void verifyProperty5(Node* n, int black_count, int* path_black_count) {
    if (node_color(n) == Color::BLACK) {
      black_count++;
    }
    if (n == NULL) {
      if (*path_black_count == -1) {
        *path_black_count = black_count;
      } else {
        assert(black_count == *path_black_count);
      }
      return;
    }
    verifyProperty5(n->getLeft(), black_count, path_black_count);
    verifyProperty5(n->getRight(), black_count, path_black_count);
  }

  /*
   * Look Up through Node
   */
  Node* lookup_node(Key key) {
    Node* n = root_;
    while (n != NULL) {
      if (key == n->getKey()) {
        return n;
      } else if (key < n->getKey()) {
        n = n->getLeft();
      } else {
        assert(key > n->getKey());
        n = n->getRight();
      }
    }
    return n;
  }

public:
  /*
   * RbTree Look Up
   */
  pair<bool, Value> find(Key key) {
    Node* n = lookup_node(key);
    if (n == NULL) return make_pair(false, Value());
    return make_pair(true, n->getValue());
  }

  /*
   * Rotate left
   */
  void rotateLeft(Node* n) {
    Node* r = n->getRight();
    replaceNode(n, r);
    n->setRight(r->getLeft());
    if (r->getLeft() != NULL) {
      r->getLeft()->setParent(n);
    }
    r->setLeft(n);
    n->setParent(r);
  }
  /*
   * Rotate right
   */
  void rotateRight(Node* n) {
    Node* L = n->getLeft();
    replaceNode(n, L);
    n->setLeft(L->getRight());
    if (L->getRight() != NULL) {
      L->getRight()->setParent(n);
    }
    L->setRight(n);
    n->setParent(L);
  }
  /*
   * Replace a node
   */
  void replaceNode(Node* oldn, Node* newn) {
    if (oldn->getParent() == NULL) {
      root_ = newn;
    } else {
      if (oldn == oldn->getParent()->getLeft())
        oldn->getParent()->setLeft(newn);
      else
        oldn->getParent()->setRight(newn);
    }
    if (newn != NULL) {
      newn->setParent(oldn->getParent());
    }
  }

public:
  /*
   * Insert node into RBTree
   */
  void insert(Key key, Value value) {
    Node* inserted_node = new Node(key, value, Color::RED, NULL, NULL);
    if (root_ == NULL) {
      root_ = inserted_node;
      size_++;
    } else {
      Node* n = root_;
      while (1) {
        if (key == n->getKey()) {
          // This tree does not stores duplcated key, in this case it only
          // updates the value associated to the key.
          n->setValue(value);
          return;
        } else if (key < n->getKey()) {
          if (n->getLeft() == NULL) {
            n->setLeft(inserted_node);
            size_++;
            break;
          } else {
            n = n->getLeft();
          }
        } else {
          assert(key > n->getKey());
          if (n->getRight() == NULL) {
            n->setRight(inserted_node);
            size_++;
            break;
          } else {
            n = n->getRight();
          }
        }
      }
      inserted_node->setParent(n);
    }
    insertCase1(inserted_node);
    verifyProperties();
  }

private:
  /*
   * Inserting Case 1
   */
  void insertCase1(Node* n) {
    if (n->getParent() == NULL)
      n->setColor(Color::BLACK);
    else
      insertCase2(n);
  }

  /*
   * Inserting Case 2
   */
  void insertCase2(Node* n) {
    if (node_color(n->getParent()) == Color::BLACK)
      return;
    else
      insertCase3(n);
  }

  /*
   * Inserting Case 3
   */
  void insertCase3(Node* n) {
    if (node_color(uncle(n)) == Color::RED) {
      n->getParent()->setColor(Color::BLACK);
      uncle(n)->setColor(Color::BLACK);
      grandparent(n)->setColor(Color::RED);
      insertCase1(grandparent(n));
    } else {
      insertCase4(n);
    }
  }

  /*
   * Inserting Case 4
   */
  void insertCase4(Node* n) {
    if (n == n->getParent()->getRight() &&
        n->getParent() == grandparent(n)->getLeft()) {
      rotateLeft(n->getParent());
      n = n->getLeft();
    } else if (n == n->getParent()->getLeft() &&
               n->getParent() == grandparent(n)->getRight()) {
      rotateRight(n->getParent());
      n = n->getRight();
    }
    insertCase5(n);
  }

  /*
   * Inserting Case 5
   */
  void insertCase5(Node* n) {
    n->getParent()->setColor(Color::BLACK);
    grandparent(n)->setColor(Color::RED);
    if (n == n->getParent()->getLeft() &&
        n->getParent() == grandparent(n)->getLeft()) {
      rotateRight(grandparent(n));
    } else {
      assert(n == n->getParent()->getRight() &&
             n->getParent() == grandparent(n)->getRight());
      rotateLeft(grandparent(n));
    }
  }

private:
  /**
   * @brief finds the smallest key in the tree rooted at @a n.
   */
  Node* findMin(Node* n) {
    if (n->hasLeftChild()) return findMin(n->getLeft());
    return n;
  }

  /**
   * @brief Returns the successor of node @a x in the tree.
   *
   * The successor of node @a x is the node with the smallest key greater than
   * @a x.
   */
  Node* successor(Node* x) {
    if (x->hasRightChild()) return findMin(x->getRight());
    Node* y = x->getParent();
    while (y != NULL && x == y->getRight()) {
      x = y;
      y = y->getParent();
    }
    return y;
  }

  /**
   * @brief Finds the smallest node in the tree that greater than or equal to @a
   * key
   */
  Node* findLowerBound(Key key) {
    Node* n = root_;
    Node* last = NULL;
    while (n != NULL && key != n->getKey()) {
      last = n;
      if (key < n->getKey()) {
        n = n->getLeft();
      } else {
        assert(key > n->getKey());
        n = n->getRight();
      }
    }
    /** At this point n has either two values:
     * - n == NULL: key was not found in the tree. In this case last has the
     *   element of the tree that is greater than key.
     *
     * - n != NULL: key is in the tree and n points to it.
     */
    if (n == NULL) {
      assert(last != NULL);
      return last;
    } else {
      return n;
    }
  }

public:
  vector<Value> findInterval(Key lb, Key ub) {
    Node* first = findLowerBound(lb);
    assert(first != NULL);
    vector<Value> result;
    while (first->getKey() <= ub) {
      result.push_back(first->getValue());
      first = successor(first);
    }
    return result;
  }

public:
  /*
   * Print
   */
  void print_tree() {
    print_tree_helper(root_, 0);
    puts("");
  }

private:
  void print_tree_helper(Node* n, int indent) {
    int i;
    if (n == NULL) {
      fputs("<empty tree>", stdout);
      return;
    }
    if (n->getRight() != NULL) {
      print_tree_helper(n->getRight(), indent + INDENT_STEP);
    }
    for (i = 0; i < indent; i++) fputs(" ", stdout);
    if (n->getColor() == Color::BLACK)
      cout << n->getKey() << endl;
    else
      cout << "<" << n->getKey() << ">" << endl;
    if (n->getLeft() != NULL) {
      print_tree_helper(n->getLeft(), indent + INDENT_STEP);
    }
  }
};

/**
 * @brief Example for findInterval
 */
void testFindInterval(void) {

  RBTree<int, string> nobels;
  {
    nobels.insert(1901, "Jean Henri Dunant");
    nobels.insert(1901, "Frédéric Passy");
    nobels.insert(1902, "Élie Ducommun");
    nobels.insert(1902, "Charles Albert Gobat");
    nobels.insert(1903, "Sir William Randal Cremer");
    nobels.insert(1904, "Institute Of International Law");
    nobels.insert(1905, "Baroness Bertha Sophie Felicita Von Suttner");
    nobels.insert(1906, "Theodore Roosevelt");
    nobels.insert(1907, "Ernesto Teodoro Moneta");
    nobels.insert(1907, "Louis Renault");
    nobels.insert(1908, "Klas Pontus Arnoldson");
    nobels.insert(1908, "Fredrik Bajer");
    nobels.insert(1909, "Auguste Marie François Beernaert");
    nobels.insert(1909,
                  "Paul Henri Benjamin Balluet d'Estournelles de Constant, "
                  "Baron de Constant de Rebecque");
    nobels.insert(1910, "Permanent International Peace Bureau");
    nobels.insert(1911, "Tobias Michael Carel Asser");
    nobels.insert(1911, "Alfred Hermann Fried");
    nobels.insert(1912, "Elihu Root");
    nobels.insert(1913, "Henri La Fontaine");
    nobels.insert(1914, "No Award");
    nobels.insert(1915, "No Award");
    nobels.insert(1916, "No Award");
    nobels.insert(1917, "International Committee Of The Red Cross");
    nobels.insert(1918, "No Award");
    nobels.insert(1919, "Thomas Woodrow Wilson");
    nobels.insert(1920, "Leon Victor Auguste Bourgeois");
    nobels.insert(1921, "Karl Hjalmar Branting");
    nobels.insert(1921, "Christian Lous Lange");
    nobels.insert(1922, "Fridtjof Nansen");
    nobels.insert(1923, "No Award");
    nobels.insert(1924, "No Award");
    nobels.insert(1925, "Sir Austen Chamberlain");
    nobels.insert(1925, "Charles Gates Dawes");
    nobels.insert(1926, "Aristide Briand");
    nobels.insert(1926, "Gustav Stresemann");
    nobels.insert(1927, "Ferdinand Buisson");
    nobels.insert(1927, "Ludwig Quidde");
    nobels.insert(1928, "No Award");
    nobels.insert(1929, "Frank Billings Kellogg");
    nobels.insert(1930, "Lars Olof Nathan (Jonathan) Soderblom");
    nobels.insert(1931, "Jane Addams");
    nobels.insert(1931, "Nicholas Murray Butler");
    nobels.insert(1932, "No Award");
    nobels.insert(1933, "Sir Norman Angell (Ralph Lane)");
    nobels.insert(1934, "Arthur Henderson");
    nobels.insert(1935, "Carl Von Ossietzky");
    nobels.insert(1936, "Carlos Saavedra Lamas");
    nobels.insert(1937, "Lord Edgar Algernon Robert Gascoyne");
    nobels.insert(1938, "Nansen International Office For Refugees");
    nobels.insert(1939, "No Award");
    nobels.insert(1940, "No Award");
    nobels.insert(1941, "No Award");
    nobels.insert(1942, "No Award");
    nobels.insert(1943, "No Award");
    nobels.insert(1944, "International Committee Of The Red Cross");
    nobels.insert(1945, "Cordell Hull");
    nobels.insert(1946, "Emily Greene Balch");
    nobels.insert(1946, "John Raleigh Mott");
    nobels.insert(1947, "Friends Service Council (Quakers)");
    nobels.insert(1947, "Amer. Friends Service Cttee (Quakers)");
    nobels.insert(1948, "No Award");
    nobels.insert(1949, "Lord John Boyd Orr Of Brechin");
    nobels.insert(1950, "Ralph Bunche");
    nobels.insert(1951, "Leon Jouhaux");
    nobels.insert(1952, "Albert Schweitzer");
    nobels.insert(1953, "George Catlett Marshall");
    nobels.insert(
        1954,
        "Office Of The United Nations High Commissioner For Refugees Geneva");
    nobels.insert(1955, "No Award");
    nobels.insert(1956, "No Award");
    nobels.insert(1957, "Lester Bowles Pearson");
    nobels.insert(1958, "Georges Henri Pire");
    nobels.insert(1959, "Philip J. Noel-Baker");
    nobels.insert(1960, "Albert John Lutuli");
    nobels.insert(1961, "Dag Hjalmar Agne Carl Hammarskjold");
    nobels.insert(1962, "Linus Carl Pauling");
    nobels.insert(1963, "International Committee Of The Red Cross");
    nobels.insert(1964, "Martin Luther King Jr.");
    nobels.insert(1964, "League Of Red Cross Societies");
    nobels.insert(1965, "United Nations Children's Fund (Unicef)");
    nobels.insert(1966, "No Award");
    nobels.insert(1967, "No Award");
    nobels.insert(1968, "Rene Cassin");
    nobels.insert(1969, "International Labour Organization (ILO)");
    nobels.insert(1970, "Norman Borlaug");
    nobels.insert(1971, "Willy Brandt");
    nobels.insert(1972, "No Award");
    nobels.insert(1973, "Henry A. Kissinger");
    nobels.insert(1973, "Le Duc Tho (Declined  prize.)");
    nobels.insert(1974, "Sean Macbride");
    nobels.insert(1974, "Eisaku Sato");
    nobels.insert(1975, "Andrei Dmitrievich Sakharov");
    nobels.insert(1976, "Betty Williams");
    nobels.insert(1976, "Mairead Corrigan");
    nobels.insert(1977, "Amnesty International");
    nobels.insert(1978, "Menachem Begin");
    nobels.insert(1978, "Mohamed Anwar Al-Sadat");
    nobels.insert(1979, "Mother Teresa");
    nobels.insert(1980, "Adolfo Perez Esquivel");
    nobels.insert(
        1981, "Office Of The United Nations High Commissioner For Refugees");
    nobels.insert(1982, "Alva Myrdal");
    nobels.insert(1982, "Alfonso Garcia Robles");
    nobels.insert(1983, "Lech Walesa");
    nobels.insert(1984, "Desmond Mpilo Tutu");
    nobels.insert(1985,
                  "International Physicians For The Prevention Of Nuclear War");
    nobels.insert(1986, "Elie Wiesel");
    nobels.insert(1987, "Oscar Arias Sánchez");
    nobels.insert(1988, "The United Nations Peace-Keeping Forces");
    nobels.insert(1989, "The 14th Dalai Lama (Tenzin Gyatso)");
    nobels.insert(1990, "Mikhail  Gorbachev");
    nobels.insert(1991, "Aung San Suu Kyi");
    nobels.insert(1992, "Rigoberta Menchú Tum");
    nobels.insert(1993, "Frederik Willem De Klerk");
    nobels.insert(1993, "Nelson Mandela");
    nobels.insert(1994, "Yasser Arafat");
    nobels.insert(1994, "Shimon Peres");
    nobels.insert(1994, "Yitzhak Rabin");
    nobels.insert(1995, "Joseph Rotblat");
    nobels.insert(1995, "The Pugwash Conferences On Science And World Affairs");
    nobels.insert(1996, "Carlos Filipe Ximenes Belo");
    nobels.insert(1996, "José Ramos-Horta");
    nobels.insert(1997, "Jody Williams");
    nobels.insert(1997, "International Campaign To Ban Landmines");
    nobels.insert(1998, "John Hume");
    nobels.insert(1998, "David Trimble");
    nobels.insert(1999, "Médecins Sans Frontières");
    nobels.insert(2000, "Kim Dae-jung");
    nobels.insert(2001, "Kofi Annan");
    nobels.insert(2001, "United Nations");
    nobels.insert(2002, "Jimmy Carter");
    nobels.insert(2003, "Shirin Ebadi");
    nobels.insert(2004, "Wangari Muta Maathai");
    nobels.insert(2005, "Mohamed Elbaradei");
    nobels.insert(2005, "International Atomic Energy Agency");
    nobels.insert(2006, "Grameen Bank");
    nobels.insert(2006, "Muhammad Yunus");
    nobels.insert(2007, "Al Gore");
    nobels.insert(2007, "Inter- govern- mental Panel On Climate Change (IPCC)");
    nobels.insert(2008, "Martti Ahtisaari");
    nobels.insert(2009, "Barack Obama");
    nobels.insert(2010, "Liu Xiaobo");
    nobels.insert(2011, "Ellen Johnson-Sirleaf");
    nobels.insert(2011, "Leymah Gbowee");
    nobels.insert(2011, "Tawakkul Kar");
    nobels.insert(2012, "European Union");
  }
  //  nobels.print_tree();
  cout << "Number of elements: " << nobels.size() << endl;
  vector<string> f1999to2010 = nobels.findInterval(1999, 2010);
  for (const auto& winner : f1999to2010) cout << winner << endl;
}

void randomTest(void) {
  RBTree<int, int> rbt;
  for (int i = 0; i < 12; i++) {
    int x = rand() % 10;
    int y = rand() % 10;
    rbt.print_tree();
    cout << "Inserting " << x << " -> " << y << endl << endl;
    rbt.insert(x, y);
    pair<bool, int> result = rbt.find(x);
    assert(result.first);
    assert(result.second == y);
  }
}

int main() {
  testFindInterval();
  return 0;
}
