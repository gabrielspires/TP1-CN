#ifndef TP1_INDIVIDUAL_
#define TP1_INDIVIDUAL_

class Individual{
public:
    Individual();
    Individual(Individual &&) = default;
    Individual(const Individual &) = default;
    Individual &operator=(Individual &&) = default;
    Individual &operator=(const Individual &) = default;
    ~Individual();
    

private:
    
};

Individual::Individual(){
}

Individual::~Individual(){
}

#endif //TP1_INDIVIDUAL_