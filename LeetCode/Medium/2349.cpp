class NumberContainers {
    unordered_map<int,int> container;
    unordered_map<int, set<int>> idx;
public:
    NumberContainers() {
        container.clear();
        idx.clear();
    }
    
    void change(int index, int number) {
        if(!container.count(index)) {
            container[index] = number;
            idx[number].insert(index);
        }
        else {
            idx[container[index]].erase(index);
            if(idx[container[index]].size() == 0) idx.erase(container[index]);
            container[index] = number;
            idx[number].insert(index);
        }
    }
    
    int find(int number) {
        return idx.count(number) ? *idx[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */