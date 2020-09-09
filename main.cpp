#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Line{
public:
    Line(float k, float b)
    {
        coef = k;
        constant = b;
    }
    ~Line() {};
    void print_line (){
        cout<<"y="<<coef<<"x+"<<constant<<endl;
    }
    float ret_coef(){
        return coef;
    }
    float ret_cons(){
        return constant;
    }
private:
    float coef;
    float constant;
};

float intersection (Line* eq1, Line* eq2){
    float x;
    if (eq1->ret_coef() == eq2->ret_coef()) {
        cout << "straight lines are parallel" << endl;
        return NULL;
    }
    x = (eq2->ret_cons()-eq1->ret_cons())/(eq1->ret_coef()-eq2->ret_coef());
            return x;
}
int main() {
    float k;
    float b;
    float x = NULL ;
    float y;
    cout<<" input first straight line equation params k and b"<<endl;
    cin>>k >> b; //принимаем параметры прямой
    Line *eq1 = new Line(k,b); // создаем прямую
    cout<< "First equation is :";
    eq1->print_line();
    cout<<" input second straight line equation params k and b"<<endl;
    cin>>k>>b; // вторая прямая
    Line *eq2 = new Line(k,b);
    cout<< "Second equation is :";
    eq2->print_line();
    x = intersection(eq1,eq2);
    if (x != NULL) {
        y = eq1->ret_coef() * x + eq1->ret_cons();
        cout << "point is ("<< x << ","<< y << ")"<< endl;
    }
    delete eq1;
    delete eq2;
}

