class Polynomial{
    public:
    int *degCoeff;
    int capacity;

    public:

    // default constructor
    Polynomial (){
        degCoeff = new int[5];
        capacity = 5;
        for(int i=0; i<capacity; i++){
            degCoeff[i] = 0;            //initializing with 0 coefficients
        }
    }
    

    // Copy Constructor
    Polynomial(Polynomial const &p){
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity; 
    }

    // set coefficient
    void setCoefficient(int deg, int coefficient){
        while(deg >= capacity){
            int *newdegCoeff = new int [2*capacity];
            for(int i=0; i<capacity; i++){
                newdegCoeff[i] = degCoeff[i];
            }
            for(int j=capacity; j<2*capacity; j++){
                newdegCoeff[j] = 0;
            }
            delete []degCoeff;
            degCoeff = newdegCoeff;
            capacity *= 2;
        }
        degCoeff[deg] = coefficient;

    }

    
    // PRINT FUNCTION
    void print() const{
        for(int i=0; i<capacity; i++)
        {
            if(this->degCoeff[i] == 0){
                continue;
            }
            else{
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }


    // Copy Assignment Operator
    void operator=(Polynomial const &p){
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity; 
    }

    // + operator
    Polynomial operator+(Polynomial &p){
      int maximum = max(capacity, p.capacity);

      if(maximum == capacity){
          for(int i=p.capacity; i<capacity; i++){
            p.setCoefficient(i,0);
          }
      } 
      if(maximum == p.capacity)
      {
          for(int i=capacity; i<p.capacity; i++){
            setCoefficient(i,0);
          }
      }
      Polynomial p2;
      for(int i=0; i<maximum; i++)
      {
          p2.setCoefficient(i,degCoeff[i] + p.degCoeff[i]);
      }
      return p2;
        
    }

    // SUBTRACTION OPERATOR
    Polynomial operator-(Polynomial &p){
        int maximum = max(capacity, p.capacity);

      if(maximum == capacity){
          for(int i=p.capacity; i<capacity; i++){
            p.setCoefficient(i,0);
          }
      } 
      if(maximum == p.capacity)
      {
          for(int i=capacity; i<p.capacity; i++){
            setCoefficient(i,0);
          }
      }
      Polynomial p2;
      for(int i=0; i<maximum; i++)
      {
          p2.setCoefficient(i,degCoeff[i] - p.degCoeff[i]);
      }
      return p2;
       
    }

    Polynomial operator*(Polynomial &p){
        Polynomial p2;
        for(int i=0; i<capacity; i++)
        {
            Polynomial p3;
            for(int j=0; j<p.capacity; j++){
                p3.setCoefficient(i+j,degCoeff[i]*p.degCoeff[j]);
            }
            p2 = p2 + p3;
        }

        return p2;

    }

};