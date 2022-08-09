class Student{
    private :
    static int totalStudent;

    public :
    int rollNumber;
    int age;

    Student(int rollNumber, int age){
        this->age = age;
        this->rollNumber = rollNumber;
        totalStudent++;
    }

    void display(){
        cout<<rollNumber<<" "<<age<<endl;
    } 

    static int getTotalStudents(){
        return totalStudent;
    }
};

int Student :: totalStudent = 0;