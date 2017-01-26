#include<ctime>
#include<fstream>

enum formatvalg { dev = true, tid = false };

class TestRamme { 
    public:
        void fersk_seed(formatvalg);
        void fersk_seed();
    private:
        
};


void TestRamme::fersk_seed(formatvalg mode = dev) {
    using namespace std;
    ifstream _stream;
    _stream.open("/dev/random", ios::binary);
    if(_stream.is_open()) {
        char* seed = new char[5];
        _stream.read(seed, 4);
        _stream.close();
        int _barnehage = *reinterpret_cast<int*>(seed);
        delete[] seed;
        srand(_barnehage);
        return;
    } else {
        this->fersk_seed(); // Du sa vi skulle gjenbruke kode! +1 funksjonskall
        return;
    }
}

void TestRamme::fersk_seed() {
    srand(4); // RFC 1149.5
    return;
}
