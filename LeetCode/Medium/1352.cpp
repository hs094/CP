class ProductOfNumbers {
    int p;
    vector<int> l;
public:
    ProductOfNumbers() {
        p = 1;
        l.clear();
    }
    
    void add(int num) {
        if(num == 0) {
            l.clear();
            p = 1;
            return;
        }
        p *= num;
        l.push_back(p);
    }
    
    int getProduct(int k) {
        if(l.size() < k) return 0;
        else if(l.size() == k) return l.back();
        else return l.back()/l[l.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */