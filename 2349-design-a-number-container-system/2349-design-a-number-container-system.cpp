class NumberContainers {
    unordered_map<int, int> container; 
    unordered_map<int, set<int>> mpp; 

public:
    NumberContainers() {}

    void change(int index, int number) {

        if (container.find(index) != container.end()) {
            int oldNumber = container[index];
            mpp[oldNumber].erase(index);
            if (mpp[oldNumber].empty()) {
                mpp.erase(oldNumber);
            }
        }
        container[index] = number;
        mpp[number].insert(index);
    }

    int find(int number) {
        if (mpp.find(number) != mpp.end() && !mpp[number].empty()) {
            return *mpp[number].begin();
        }
        return -1;
    }
};
