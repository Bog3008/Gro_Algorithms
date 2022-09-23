void swap(Node <Type> * a, Node<Type> * b ){           
        if(a == b || a == nullptr || b == nullptr) return;
        //cout <<"a-p: " << a->prev << "; a:" << a << "; a-n"<< a->next <<endl;
        //cout <<"b-p: " << b->prev << "; b:" << b << "; b-n"<< b->next <<endl;
        //neighbors elements - OK - MB_Ok
        if(a->next == b){
            if(a->prev != nullptr){
                b->prev = a->prev;
                a->prev->next = b;
            }
            else{
                b->prev = nullptr;
                head = b;
            }
            if(b->next != nullptr){
                a->next = b->next;
                b->next->prev = a;
            }
            else{
                a->next = nullptr;
                tail = b;
            }
            b->next = a;
            a->prev = b;
            return;

        }
        else if(b->next == a){
            swap(b,a);
            return;
        }
        //not nei:
        // HEAD-Tail - OK - OK
        if(a->prev == nullptr && b->next == nullptr) { //head-tail setuation
            b->next = a->next;
            a->next = nullptr;

            b->next->prev = b;
            b->prev->next = a;

            a->prev = b->prev;
            b->prev = nullptr;

            head = b;
            tail = a;
            return;
        }
        else if(b->prev == nullptr && a->next == nullptr){ // tail - head setuation
            swap(b, a);
            return;
        }
        //Tail - X - OK - OK
        if(a->prev != nullptr && b->next == nullptr){
            b->next = a->next;
            a->next = b->prev; //tmp boof

            b->next->prev = b;
            b->prev = a->prev;
            a->prev = a->next; // boof
            b->prev->next = b;
            a->prev->next = a;
            a->next = nullptr;
            tail = a;
            return;
        }
        else if(b->prev != nullptr && a->next == nullptr){
            swap(b, a);
            return;
        }
        //Head - X - OK - OK
        if(a->prev == nullptr && b->next != nullptr){
            a->prev = b->prev;
            a->prev->next = a;
            b->prev = a->next; // место буфера

            a->next = b->next;
            b->next = b->prev;
            b->next->prev = b;
            a->next->prev = a;
            b->prev = nullptr;
            head = b;
            return;
        }
        else if(b->prev == nullptr && a->next != nullptr){
            swap(b, a);
            return;
        }
        //X - X - OK
        //if() ифа не будет - тк вариантов больше не осталось(скорее всего)
        // обмен значений с предыдущими элиментами
        Node<Type> * boof = a->prev;
        a->prev->next = b;
        b->prev->next = a;
        boof = a->prev;  //////////////// ткуда boof
        a->prev = b->prev;
        b->prev = boof;
        //обмен со след элл
        a->next->prev = b;
        b->next->prev = a;
        boof = a->next;
        a->next = b->next;
        b->next = boof;



    }
