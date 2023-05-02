#include <iostream>
#include <cstring>
#include <tuple>

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v, Node* n) : key(k), value(v), next(n) {}
    };
    Node* head;
    Node* tail;
    int count;
public:
    Map() : head(nullptr), tail(nullptr), count(0) {}
    ~Map() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    bool includes(const Map<K, V>& other) const {
        Node* current = head;
        while (current != nullptr) {
            V other_value;
            if (other.get(current->key, other_value)) {
                if (current->value != other_value) {
                    return false;
                }
            }
            else {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool get(const K& key, V& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void set(const K& key, const V& value) {
        if (head == nullptr) {
            head = new Node(key, value, nullptr);
            tail = head;
            ++count;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* new_node = new Node(key, value, nullptr);
        current->next = new_node;
        tail = new_node;
        ++count;
    }

    bool delete_key(const K& key) {
        Node** current = &head;
        while (*current != nullptr) {
            if ((*current)->key == key) {
                Node* temp = *current;
                *current = temp->next;
                if (temp == tail) {
                    tail = *current;
                }
                delete temp;
                --count;
                return true;
            }
            current = &(*current)->next;
        }
        return false;
    }

    int count_elements() const {
        return count;
    }

    class Iterator {
    private:
        Node* current;
        int index;

    public:
        Iterator(Node* ptr, int idx) : current(ptr), index(idx) {}

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        void operator++() {
            current = current->next;
            ++index;
        }

        std::tuple<K, V, int> operator*() const {
            return std::make_tuple(current->key, current->value, index);
        }
    };

    Iterator begin() const {
        return Iterator(head, 0);
    }

    Iterator end() const {
        return Iterator(nullptr, count);
    }

    V& operator[](const K& key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
                return current->value;
            }
            current = current->next;
        }
        Node* new_node = new Node(key, V(), nullptr);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        ++count;
        return new_node->value;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
