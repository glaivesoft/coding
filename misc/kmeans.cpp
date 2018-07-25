// K-Means
// we are finding subsets such that the overall variance around cluster centroids is minimized
// In fact, k-means is a special case of EM where we assume isotropic (spherical) Gaussian priors.

/*
 Given cluster centroids μi initialized in some way,
 For iteration t=1..T:
 
    Compute the distance from each point x to each cluster centroid μ,
    Assign each point to the centroid it is closest to,
    Recompute each centroid μ as the mean of all points assigned to it.
 
 */

// The time complexity of this approach is O(n×k×T).

//
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <random>
#include <vector>

#include <iostream>

using namespace std;

//
struct Point {
    double x{0}, y{0};
};

using DataFrame = std::vector<Point>;

double square(double value) {
    return value * value;
}

double squared_l2_distance(Point first, Point second) {
    return square(first.x - second.x) + square(first.y - second.y);
}

DataFrame k_means(const DataFrame& data,
                  size_t k,
                  size_t number_of_iterations) {
    static std::random_device seed;
    static std::mt19937 random_number_generator(seed());
    std::uniform_int_distribution<size_t> indices(0, data.size() - 1);
    
    // Pick centroids as random points from the dataset.
    DataFrame means(k);
    for (auto& cluster : means) {
        cluster = data[indices(random_number_generator)];
    }
    
    std::vector<size_t> assignments(data.size());
    for (size_t iteration = 0; iteration < number_of_iterations; ++iteration) {
        // Find assignments.
        for (size_t point = 0; point < data.size(); ++point) {
            double best_distance = std::numeric_limits<double>::max();
            size_t best_cluster = 0;
            for (size_t cluster = 0; cluster < k; ++cluster) {
                const double distance =
                squared_l2_distance(data[point], means[cluster]);
                if (distance < best_distance) {
                    best_distance = distance;
                    best_cluster = cluster;
                }
            }
            assignments[point] = best_cluster;
        }
        
        // Sum up and count points for each cluster.
        DataFrame new_means(k);
        std::vector<size_t> counts(k, 0);
        for (size_t point = 0; point < data.size(); ++point) {
            const auto cluster = assignments[point];
            new_means[cluster].x += data[point].x;
            new_means[cluster].y += data[point].y;
            counts[cluster] += 1;
        }
        
        // Divide sums by counts to get new centroids.
        for (size_t cluster = 0; cluster < k; ++cluster) {
            // Turn 0/0 into 0/1 to avoid zero division.
            const auto count = std::max<size_t>(1, counts[cluster]);
            means[cluster].x = new_means[cluster].x / count;
            means[cluster].y = new_means[cluster].y / count;
        }
    }
    
    return means;
}

int main(int argc, char *argv[])
{
    //
    DataFrame data;
    int i = 0;
    while(i++ < 10) {
        Point p;
        p.x = (rand() % 100);
        p.y = (rand() % 100);
        
        cout<<p.x<<" "<<p.y<<endl;

        data.push_back(p);
    }
    cout<<" --- \n";
    
    DataFrame means = k_means(data, 2, 1000);
    
    for(int i=0; i<means.size(); i++)
    {
        cout<<means[i].x<<" "<<means[i].y<<endl;
    }
    
    //
    return 0;
}


