class DynamicArray {
public:
    int size = 0;
    int capacity = 0;
    int *arr = nullptr;
    DynamicArray(int capacity):capacity(capacity) {
        arr = new int[this->capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity) {
            resize();
        }
        arr[size++] = n;
    }

    int popback() {
        if(size > 0) {
            return arr[--size];
        }
        return arr[size];
    }

    void resize() {
        capacity *= 2;
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete []arr;
        arr = temp;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
