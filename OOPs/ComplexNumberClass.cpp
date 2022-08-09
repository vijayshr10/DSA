class ComplexNumbers{
    private :
        int real;
        int imaginary;
    
    public:

    ComplexNumbers(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers const &c2){
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    void multiply(ComplexNumbers const &c2){
        int x = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        int y = (this->real * c2.imaginary) + (this->imaginary + c2.real);

        real = x;
        imaginary = y;

    }

    void print(){
        cout<<real<<" + i"<<imaginary<<endl; 
    }

    
};