class Student{
    private:
        int age;
    
    public:
        char *name;

        
        Student (int age, char *name){
            this->age = age;

            // Shallow Copy // Copying only starting adddress of name
            // this->name = name;

            // Deep Copy  // copying full array
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);

        }

        // Copy Constructor
        Student (Student const &s){
            this->age = s.age;

            this->name = new char[strlen(s.name) + 1];
            strcpy(this->name, s.name);
        }

        void display(){
            cout<<name<<" "<<age<<endl;
        }
};