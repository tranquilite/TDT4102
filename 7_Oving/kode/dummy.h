class Dummy {
    public:
        int *num;
        Dummy() { num = new int(0); }
        ~Dummy() { delete num; }
};

void dummyTest();
