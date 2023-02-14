#include <iostream>

class Subforwardlist{
public:
    Subforwardlist();
    ~Subforwardlist();

    bool push_back(int d);	//добавление элемента в конец недосписка	
    int pop_back();
    bool push_forward(int d);	//добавление элемента в начало недосписка
    int pop_forward(); 	//удаление элемента из начала недосписка
    unsigned int size();
    bool push_where(unsigned int where, int d); //добавление элемента с порядковым номером where
    int erase_where(unsigned int where);	//удаление элемента с порядковым номером where
    void clear();
private:
    struct subforwardlist {
        int data;
        subforwardlist* next;
    };

    //##################################
        bool init(subforwardlist **sfl){ 	//инициализация пустого недосписка 
            (*sfl) = NULL;
            return true;
        }
        bool push_back(subforwardlist **sfl, int d){ 	//добавление элемента в конец недосписка	
            if ((*sfl) != NULL){
                subforwardlist* addres = (*sfl);
                while (addres->next != NULL){
                    addres = addres->next;
                }
                subforwardlist* nx;
                nx = new subforwardlist;
                nx->data=d;
                nx->next=NULL;
                addres->next = nx;
                // addres->next->data = d;
                // addres->next->next = NULL;
                return true;
            } else {
                (*sfl) = new subforwardlist;
                (*sfl)->data = d;
                (*sfl)->next = NULL;
                return true;
            }
            return false;
        }		

        int pop_back(subforwardlist **sfl)
        {
            int temp_data = 0;
            if ((*sfl)!= NULL){
                subforwardlist* temp = *sfl;
                if ((temp->next)!= NULL){
                    while (temp->next->next != NULL)
                        temp = (temp->next);
                    temp_data = temp->next->data;
                    delete temp->next;
                    temp->next = NULL;
                    return temp_data;
                }
                else{
                    temp_data = temp->data;
                    delete temp;
                    (*sfl)=NULL;
                    return temp_data;
                }
            } else {
                return 0;
            }
            
        }
        bool push_forward(subforwardlist **sfl, int d){ 	//добавление элемента в начало недосписка
            subforwardlist* addres;
            addres = new subforwardlist;
            addres->data = d;
            addres->next = *sfl;
            *sfl = addres;
            return true;
        }				
        int pop_forward(subforwardlist **sfl){ 	//удаление элемента из начала недосписка
            if(*sfl != NULL){
                subforwardlist* addres;
                addres = (*sfl)->next;
                int dat = (*sfl)->data;
                delete (*sfl);
                *sfl = addres;
                return dat;
            }
            return 0;
        }
        unsigned int size(subforwardlist  **sfl){	//определить размер недосписка
            if ((*sfl) != NULL){
                subforwardlist* addres = (*sfl);
                unsigned int ln = 1;
                while (addres->next != NULL){
                    addres = addres->next;
                    ln ++;
                }
                return ln;
            }
            return 0;
        }
        bool push_where(subforwardlist **sfl, unsigned int where, int d){ //добавление элемента с порядковым номером where
            if ((*sfl)!= NULL){
                subforwardlist* addres = (*sfl);
                // subforwardlist* addres_pr = NULL;
                if(where < size(sfl)){
                    while (where > 1){
                        // if(where == 1)
                        //     addres_pr = addres;
                        if (addres->next != NULL){
                            addres = addres->next;
                            where --;
                        }else{
                            return false;
                        }
                    }
                    subforwardlist* newElement;
                    newElement =  new subforwardlist;
                    newElement->data = d;
                    newElement->next = addres->next;
                    addres->next = newElement;
                    return true;
                } else {
                    while (addres->next != NULL){
                        addres = addres->next;
                    }
                    subforwardlist* newElement;
                    newElement =  new subforwardlist;
                    newElement->data = d;
                    newElement->next = NULL;
                    addres->next = newElement;
                    return true;
                }
            }    
            return false;
        }		
        int erase_where(subforwardlist **sfl, unsigned int where){	//удаление элемента с порядковым номером where
            if((*sfl) != NULL){
                subforwardlist* addres = (*sfl);
                if(where < size(sfl)){
                    while (where > 1){
                        if (addres->next != NULL){
                            addres = addres->next;
                            where --;
                        }else{
                            return 0;
                        }
                    }
                    int dat = addres->next->data;
                    subforwardlist* add = addres->next->next;
                    delete addres->next;
                    addres->next=add;
                    return dat;
                } else {
                    return 0;
                }
            }
            return 0;
        }

        void clear(subforwardlist  **sfl){	//очистить содержимое недосписка
            if ((*sfl) != NULL){
                subforwardlist* addres = (*sfl);
                subforwardlist* addres_pr = NULL;
                while (addres->next != NULL){
                    addres_pr = addres;
                    addres = addres->next;
                    delete addres_pr;
                }
                delete addres;
                *sfl = NULL;
            }
        }
    //##################################

    subforwardlist* root;
};

Subforwardlist::Subforwardlist(){
    // subforwardlist rt;
    init(&this->root);
}

bool Subforwardlist::push_back(int d){
    return push_back(&this->root, d);
}

int Subforwardlist::pop_back(){
    return pop_back(&this->root);
}

bool Subforwardlist::push_forward(int d){
    return push_forward(&this->root, d);
}

int Subforwardlist::pop_forward(){
    return pop_forward(&this->root);
}

unsigned int Subforwardlist::size(){
    return size(&this->root);
}

bool Subforwardlist::push_where(unsigned int where, int d){
    return push_where(&this->root, where, d);
}

int Subforwardlist::erase_where(unsigned int where){
    return erase_where(&this->root, where);
}

void Subforwardlist::clear(){
    clear(&this->root);
}

Subforwardlist::~Subforwardlist(){
    clear(&this->root);
}

#include <random>
#include <chrono>
using std::cout;
using std::endl;
double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}
int rand_uns(int min, int max)
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        static std::default_random_engine e(seed);
        std::uniform_int_distribution<int> d(min, max);
        return d(e);
}

int main()
{
    unsigned int n = 10000;
    int *test_sequence = new int[n], sum_for_O3 = 0, test_sequence_sum = 0, ongoing_sum = 0,
        *push_sequence = new int[n],
        *pop_sequence = new int[n],
        *pop_push_sequence_eq = new int[n],
        *pop_push_sequence_push = new int[n],
        *pop_push_sequence_pushpush = new int[n],
        *four_ways_test = new int[n];
    double start = 0, finish = 0, total = 0;
    cout << std::fixed;
    cout.precision(4);
//----------- Initialization
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        test_sequence[i] = rand_uns(0, n - 1);
        test_sequence_sum += test_sequence[i];
        push_sequence[i] = rand_uns(0, n - 1);
        pop_sequence[i] = rand_uns(0, n - 1);
        pop_push_sequence_eq[i] = rand_uns(0, 1);
        pop_push_sequence_push[i] = rand_uns(0, 5);
        pop_push_sequence_pushpush[i] = rand_uns(0, 10);
        four_ways_test[i] = rand_uns(0, 3);
    }

    finish = get_time();
    cout << "Test sequence initialization: \t\t\t\t" << finish - start << endl;
    Subforwardlist sv;
//----------- Test 000 Straight push_back
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        sv.push_back(test_sequence[i]);
        // std::cout << test_sequence[i] << ' ';
    }
    // std::cout <<size(&sv) << std::endl;
    finish = get_time();
    cout << "000 Straight push_back: \t\t\t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 001 Straight pop_forward
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        int elem = sv.pop_forward();
        // std::cout << elem << ' ';
        if (elem != test_sequence[i])
        {
            cout <<endl <<"--- !!! Failed push/pop consistency !!! ---" << endl;
            return 0;
        }
    }
    // std::cout <<size(&sv) << std::endl;
    finish = get_time();
    if (sv.size())
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, some elememts stuck !!! ---" << endl;
        return 0;
    }
    cout << "001 Straight pop_forward: \t\t\t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 002 Straight push_forward
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        sv.push_forward(test_sequence[i]);
        // std::cout << test_sequence[i] << ' ';
    }
    // std::cout <<size(&sv) << std::endl;
    // std::cout << std::endl;
    finish = get_time();
    cout << "002 Straight push_forward: \t\t\t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 003 Straight pop_back
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        int elem = sv.pop_back();
        // std::cout << elem << ' ';
        if (elem != test_sequence[i])
        {
            cout <<endl <<"--- !!! Failed push/pop consistency !!! ---" << endl;
            return 0;
        }
    }
    // std::cout <<size(&sv) << std::endl;
    finish = get_time();
    if (sv.size())
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, some elememts stuck !!! ---" << endl;
        return 0;
    }
    cout << "003 Straight pop_back: \t\t\t\t\t" << finish - start << endl;
    // std::cout <<size(&sv) << std::endl;
    total += finish - start;
//----------- Test 004 Random push_where
    for (unsigned int i = 0; i < n; i++)
    {
        sv.push_back(test_sequence[i]);
    }
    start = get_time();
    // std::cout << size(&sv) << " 1" << std::endl;
    for (unsigned int i = 0; i < n; i++)
    {
        sv.push_where(push_sequence[i], test_sequence[i]);
    }
    // std::cout << size(&sv) << " 2" << std::endl;
    finish = get_time();
    if (sv.size() != 2 * n)
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, wrong elements number !!! ---" << endl;
        return 0;
    }
    // std::cout << size(&sv) << " 3" << std::endl;
    ongoing_sum = 0;
    for (unsigned int i = 0; i < 2 * n; i++)
    {
        ongoing_sum += sv.pop_back();
    }
    // std::cout << size(&sv) << " 4" << std::endl;
    if (sv.size())
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, some elememts stuck !!! ---" << endl;
        return 0;
    }
    if (ongoing_sum != 2 * test_sequence_sum)
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, sum incoherent !!! ---" << endl;
        return 0;
    }
    cout << "004 Random push_where: \t\t\t\t\t" << finish - start << endl;
    total += finish - start;
//----------- Test 005 Random erase_where
    for (unsigned int i = 0; i < 2 * n; i++)
    {
        sv.push_back(test_sequence[i % n]);
    }
    // std::cout << size(&sv) << " 1" << std::endl;
    sum_for_O3 = 0;
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        sum_for_O3 += sv.erase_where(pop_sequence[i]);
    }
    std::cout << sv.size() << " 2" << std::endl;
    finish = get_time();
    if (sv.size() != n)
    {
        cout <<endl <<"--- !!! Failed push/pop consistency, wrong elements number !!! ---" << endl;
        return 0;
    }
    sv.clear();
    if (sv.size())
    {
        cout <<endl <<"--- !!! Clear works wrongly !!! ---" << endl;
        return 0;
    }
    cout << "005 Random erase_where: \t\t\t\t" << finish - start << " \t\t" << sum_for_O3 << endl;
    total += finish - start;

//----------- Test 006 Random pop/push back equal amount
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_eq[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    sv.clear();
    cout << "006 Random pop/push back equal amount: \t\t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 007 Random pop/push back more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_push[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    sv.clear();
    cout << "007 Random pop/push back more push: \t\t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 008 Random pop/push back much more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_pushpush[i])
            sv.push_back(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_back();
    }
    finish = get_time();
    sv.clear();
    cout << "008 Random pop/push back much more push: \t\t" << finish - start <<"\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 009 Random pop/push forward equal amount
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_eq[i])
            sv.push_forward(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_forward();
    }
    finish = get_time();
    sv.clear();
    cout << "009 Random pop/push forward equal amount: \t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 010 Random pop/push forward more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_push[i])
            sv.push_forward(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_forward();
    }
    finish = get_time();
    sv.clear();
    cout << "010 Random pop/push forward more push: \t\t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 011 Random pop/push forward much more push
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (pop_push_sequence_pushpush[i])
            sv.push_forward(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_forward();
    }
    finish = get_time();
    sv.clear();
    cout << "011 Random pop/push forward much more push: \t\t" << finish - start <<"\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- Test 012 Random pop/push four ways
    sum_for_O3 = 0; // This variable will be printed so O3 won't cut the whole thing.
    start = get_time();
    for (unsigned int i = 0; i < n; i++)
    {
        if (four_ways_test[i] == 0)
            sv.push_back(test_sequence[i]);
        else if (four_ways_test[i] == 1)
            sum_for_O3 += sv.pop_back();
        else if (four_ways_test[i] == 2)
            sv.push_forward(test_sequence[i]);
        else
            sum_for_O3 += sv.pop_forward();
    }
    finish = get_time();
    sv.clear();
    cout << "012 Random pop/push four ways: \t\t\t\t" << finish - start << "\t\t" << sum_for_O3 << endl;
    total += finish - start;
//----------- End of tests

    cout << "-----------" << endl <<"Alltests finished, total time: \t" << total << endl;
    delete[] test_sequence;
    delete[] pop_push_sequence_eq;
    delete[] pop_push_sequence_push;
    delete[] pop_push_sequence_pushpush;
    delete[] push_sequence,
    delete[] pop_sequence,
    delete[] four_ways_test;

    return 0;
}