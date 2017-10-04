#include "Individual.cpp"

// #include "dependencies.h"
#include "functions.h"

int main(int argc, char const *argv[]){
    srand(time(NULL));

    int num_of_var;
    vector <Individual*> population, new_population;

    vector< vector<double> > dataset_train;
    vector< vector<double> > dataset_test;

    ifstream input_train(argv[1]);
             // input_test(argv[2]);

    read_CSV(dataset_train, input_train);
    // read_CSV(dataset_test, input_test);

    num_of_var = dataset_train[0].size() - 1;

    cout << "Ind. max size:   " << ind_max_size << endl
         << "Init. pop. size: " << init_pop_size << endl
         << "Max. pop. size:  " << max_pop_size << endl
         << "Tournament size: " << tourn_size << endl
         << "Max. num. gen.:  " << max_gen << endl
         << "Crossover rate:  " << cross_rate << endl
         << "Mutation rate:   " << mut_rate << endl;

    cout << "Min Fitness:  " << "\t Mean Fitness: " << "\t Max Fitness:  " << endl;

    double min_fitness = (1.0/0.0);
    double max_fitness = 0;
    double mean_fitness = 0;

    // double global_min_fitness = 0;
    // double global_max_fitness = 0;
    // double global_mean_fitness = 0;

    // vector<double> min_fits(max_gen);
    // vector<double> med_fits(max_gen);
    // vector<double> max_fits(max_gen);

    // for (int k = 0; k < num_runs; ++k){

        generate_population(population, num_of_var);

        for (int i = 0; i < max_gen && population.size() < max_pop_size; ++i){
            min_fitness = (1.0/0.0);
            max_fitness = 0;
            mean_fitness = 0;

            calc_fitness(population, dataset_train, num_of_var);
            evolve(population, new_population);

            for (int j = 0; j < population.size(); j++){
                if(population[j]) delete population[j];
            }

            population.swap(new_population);

            for (int j = 0; j < population.size(); j++){
                if (population[j]->fitness < min_fitness){
                    min_fitness = population[j]->fitness;
                }

                if(population[j]->fitness > max_fitness){
                    max_fitness = population[j]->fitness;
                }
                mean_fitness += population[j]->fitness;
            }
            mean_fitness = mean_fitness/population.size();

            new_population.clear();
            cout << i << setw(10) << min_fitness
                 << "     \t" << setw(10) <<  mean_fitness
                 << "     \t" << setw(10) << max_fitness << endl;

            // min_fits[i] += min_fitness;
            // med_fits[i] += mean_fitness;
            // max_fits[i] += max_fitness;
        }
        // population.clear();
        // global_min_fitness += min_fitness/num_runs;
        // global_mean_fitness += mean_fitness/num_runs;
        // global_max_fitness += max_fitness/num_runs;
    // }
    // for (int i = 0; i < max_gen; ++i){
    //     cout << i << " "
    //          << setw(10) << min_fits[i]/num_runs << " "
    //          << setw(10) << med_fits[i]/num_runs << " "
    //          << setw(10) << max_fits[i]/num_runs << endl;
    // }

    return 0;
}
