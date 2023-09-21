#if !defined(FILA_CIRCULAR_HPP)
#define FILA_CIRCULAR_HPP

#include <unistd.h>

#include <iostream>

template <typename T, ssize_t MAX_FILA>
class FilaCircular {
   public:
    FilaCircular() : front{-1}, back{-1} {
        static_assert(MAX_FILA >= 1,
                      "Falha de compilacao. O tamanho da fila circular deve ser no minimo 1");
    }
    ~FilaCircular() {}

    void enqueue(const T item) {
        if ((this->front == 0 && this->back + 1 == MAX_FILA) ||
            ((this->back + 1) % MAX_FILA == this->front)) {
            std::cerr << "Falha ao inserir. A fila esta cheia.\n";
            return;
        } else if (this->front == -1) /* primeiro elemento */ {
            this->front = this->back = 0;
            this->fila[this->back] = item;
        } else if (this->back == MAX_FILA - 1 && front != 0) {
            this->back = 0;
            this->fila[this->back] = item;
        } else {
            this->back++;
            this->fila[this->back] = item;
        }

        std::cout << "Item " << this->fila[this->back] << " foi\033[0;32m Inserido\033[0m.\n";

        return;
    }

    T dequeue() {
        if (this->front == -1) {
            std::cerr << "Falha ao remover da fila. A fila esta vazia.\n";
            return (T)NULL;
        }

        T data = this->fila[this->front];

        if (this->front == this->back) {
            this->front = this->back = -1;
        } else if (this->front == MAX_FILA - 1)
            this->front = 0;
        else
            this->front++;

        std::cout << "Item " << data << " foi\033[31m Removido\033[0m.\n";

        return data;
    }

    void show() {
        if (this->front == -1) {
            std::cout << "A Fila esta vazia.\n";
        }

        std::cout << "Itens na fila: ";
        if (this->back >= this->front) {
            for (ssize_t i = this->front; i <= this->back; i++) printf("%d ", this->fila[i]);
        } else {
            for (ssize_t i = this->front; i < MAX_FILA; i++) printf("%d ", this->fila[i]);

            for (ssize_t i = 0; i <= this->back; i++) printf("%d ", this->fila[i]);
        }
        std::cout << '\n';
    }

   private:
    T fila[MAX_FILA];
    ssize_t front;
    ssize_t back;
};

#endif  // FILA_CIRCULAR_HPP
