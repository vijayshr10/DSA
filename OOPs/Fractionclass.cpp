class Fraction{
    private:

        int numerator;
        int denominator;

    public:

    Fraction(int numerator, int denominator)
    {
        this-> numerator = numerator;
        this-> denominator = denominator;
    }

    void print()
    {
        cout<<this-> numerator<<"/"<<this-> denominator<<endl; // this keyword can be skipped
    }

    void simplify(){
        int gcd = 1;
        int j = min(this->numerator , this->denominator);
        for(int i=1; i<=j; i++)
        {
            if(this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;

    }

    // passing constant referrence to avoid copy constructor(space, time) and avoid changes in f2
    // Fraction add(Fraction const &f2){            calling by f3 = f1.add(f2); 
        
        Fraction operator+(Fraction const &f2) const{         // calling by f3 = f1 + f2;
        int lcm = denominator * f2.denominator;
        int x = numerator * f2.denominator;
        int y = f2.numerator * denominator;

        // numerator = x + y;
        // denominator = lcm;
        int num = x + y;

        Fraction fnew(num, lcm);
        fnew.simplify();
        return fnew;
    }

    // void multiply(Fraction const &f2){
    //     numerator = numerator * f2.numerator;
    //     denominator = denominator * f2.denominator;

    //     simplify();
    // }

    Fraction operator*(Fraction const &f2) const { // const as it does not change any value in this or neihter in argument
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;

    }

    bool operator==(Fraction const &f2){
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // PRE increment
    Fraction& operator++(){
        numerator = numerator + denominator;
        simplify();

        return *this;
    }

    // POST INCREMENT
    Fraction operator++(int){
        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew;

    }

    Fraction& operator+=(Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = numerator * f2.denominator;
        int y = f2.numerator * denominator;

        numerator = x + y;
        denominator = lcm;
        simplify();

        return *this;

    }

   
};