class Student{
    public:
    int rollNumber;

    private:
    int age;

    public:

    void display(){
        cout<<rollNumber<<" "<<age<<endl;
    }

    int getAge() // getter
    {
        return age;
    }

    void setAge(int a)  // setter
    {
        age = a;
    }

};
